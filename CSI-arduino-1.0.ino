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

const int LDR = A0; // 
const int ledPin = 50; // LED NFC
const int ledPin2 = 48; // LED DE EMERGENCIA
const int pinMQ2_D0 = 32; // DIGITAL MQ2
const int pinMQ7_D0 = 24; // DIGITAL MQ7
const int pinMQ2_A0 = A2; // ANALOGICO MQ2
const int pinMQ7_A0 = A1; // ANALOGICO MQ7
const int pinPIR = 35; // SAIDA DO PIR
const int pin_somA = A5; // ANALOGICO SOM
//const int pin_rele = 30; // SLA
const int pin_somD = 31; // DIGITAL SOM
const int pinUMD_D0 = 26; // DIGITAL UMD
const int pinUMD_A0 = A3; // ANALOGICO UMD
const int pinRele_1 = 5; //SOLENOIDE
const int pinAltoFalante = 6; //SIRENE
const int ledQuarto = 49; //  LUZ DO QUARTO DE CASAL
const int ledAmarelo = 41; // LUZ DO QUARTO DE SOLTEIRO
const int ledVermelho = 47; // LUZ DA GARAGEM
const int ledVerde = 39; // LUZ DA COZINHA
const int ledNaoSei1 = 45; // LUZ DA SALA
//const int ledNaoSei2 = 41; // 
//const int ledNaoSei3 = 42; // LUZ DA 
const int pinExaustorCozinha = 52; // VENTUINHA DA COZINHA // VS2
const int pinVentiladorSala = 53; // VENTUINHA DA SALA //VS1

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

int cont=0;
int cont2=0;
boolean rele = LOW;
int setpointGas = 1024; // QUANTIDADE DE GÁS QUE VAI ATIVAR O MODO DE SEGURANÇA
int setpointUmidade = 500;
int marcus = 0;
int x=0;
int sinVal = 0;
int toneVal = 0;

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
  pinMode(ledPin, OUTPUT); //
  pinMode(ledPin2, OUTPUT); //
  pinMode(pinPIR, INPUT); // 
  pinMode(pinMQ2_D0,INPUT); //
  pinMode(pinMQ7_D0,INPUT); //
  pinMode(pinRele_1,OUTPUT); //
  pinMode(pinAltoFalante,OUTPUT); //
  digitalWrite(pinRele_1,LOW); //
  pinMode(ledQuarto, OUTPUT); //
  pinMode(ledVerde, OUTPUT); // 
  pinMode(ledAmarelo, OUTPUT); //
  pinMode(pinVentiladorSala, OUTPUT); //
//  pinMode(pin_rele, OUTPUT); //
  pinMode(pin_somD, INPUT); //
  pinMode(pinExaustorCozinha, OUTPUT); //
  pinMode(ledNaoSei1, OUTPUT); //
//  pinMode(ledNaoSei2, OUTPUT); //
//  pinMode(ledNaoSei3, OUTPUT);   //
   
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

  servoPortao.attach(4);
  servoJanela.attach(3);
  servoPorta.attach(2);
  servoPorta.write(0);
  servoJanela.write(0);
  servoPortao.write(0);
  
//  attachInterrupt(0,modoDeSeguranca(),RISING);
  
  delay(3000);
  Serial.println("Rodando");
  
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

void loop() {

  readNFC();
  lerBluetooth();
  lerSerial();
  operar();
  escreveBluetooth();
}
