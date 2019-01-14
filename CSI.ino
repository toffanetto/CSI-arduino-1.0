/*   @toffanetto
 *   Instituto Federal de Minas Gerais - Campus Ouro Preto
 *   Curso Técnico Integrado em Automação Industrial
 *   Projetos de Automação - 2018
 *   Orientadores: Silvia Grasiella Moreira Almeida
 *                 Paulo Raimundo Pinto
 *   CSI - Casa de Segurança Inteligente
 *   Autor: Gabriel Toffanetto França da Rocha
 *   Brazil 2018
 * 
 */

#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>
#include "Servo.h"
#include <PN532_HSU.h>
#include <PN532.h>

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

#define DHTTYPE DHT11
#define pino_DHT 23

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

PN532_HSU pn532hsu(Serial2);
PN532 nfc(pn532hsu);

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0,88);         
IPAddress gateway(192,168,0,1);     
IPAddress subnet(255, 255, 255, 0);
EthernetServer server(80);

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

const int LDR = A0;
const int ledPin = 22;
const int ledPin2 = 28;
const int pinMQ2_D0 = 32;
const int pinMQ7_D0 = 24;
const int pinMQ2_A0 = A2;
const int pinMQ7_A0 = A1;
const int pinPIR = 35;
const int pin_somA = A5;
const int pin_rele = 30;
const int pin_somD = 31;
const int pinUMD_D0 = 26;
const int pinUMD_A0 = A3;
const int pinRele_1 = 5; //SOLENOIDE
const int pinRele_2 = 6; //SIRENE
const int ledQuarto = 49;
const int ledAmarelo = 41;
const int ledVermelho = 47;
const int ledVerde = 39;
const int ledNaoSei1 = 45;
const int ledNaoSei2 = 43;
const int ledNaoSei3 = 42;
const int pinExaustorCozinha = 52;
const int pinVentiladorSala = 53;

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

int cont=0;
int cont2=0;
boolean rele = LOW;
int setpoint = 1024;
int marcus =0;

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

Servo servoPorta;
Servo servoJanela;
Servo servoPortao;
DHT dht(pino_DHT, DHTTYPE);

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
   
void setup() {
  
  Serial.begin(115200);
  Serial1.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(pinPIR, INPUT);
  pinMode(pinMQ2_D0,INPUT);
  pinMode(pinMQ7_D0,INPUT);
  pinMode(pinRele_1,OUTPUT);
  pinMode(pinRele_2,OUTPUT);
  digitalWrite(pinRele_1,LOW);
  digitalWrite(pinRele_2,LOW);
  pinMode(ledQuarto, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(pinVentiladorSala, OUTPUT);
  pinMode(pin_rele, OUTPUT);
  pinMode(pin_somD, INPUT);
  pinMode(pinExaustorCozinha, OUTPUT);
  pinMode(ledNaoSei1, OUTPUT);
  pinMode(ledNaoSei2, OUTPUT);
  pinMode(ledNaoSei3, OUTPUT);  
 
  
  iniciandoSerial();
  
  nfc.begin();
  
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata)
  {
    Serial.println("Placa PN53x nao encontrada...");
    //while (1); // halt
  }
  else
  Serial.println("Placa PN53x encontrada...");
  
  nfc.setPassiveActivationRetries(0xFF);
  nfc.SAMConfig();
  
  dht.begin();
  
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();

  servoPortao.attach(4);
  servoJanela.attach(3);
  servoPorta.attach(2);
  servoPorta.write(0);
  servoJanela.write(0);
  servoPortao.write(0);
  
//  attachInterrupt(0,modoDeSeguranca(),RISING);
  
  delay(3000);
  Serial.println("Rodando");
  escreveBluetooth();
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

void loop() {

  readNFC();
  lerBluetooth();
  lerSerial();
  comunicaEthernet();
  ativaPalmas();
  operar();
  
}
