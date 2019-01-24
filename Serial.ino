///////////////////////////////////

void iniciandoSerial(){
  Serial.println("CSI");
  Serial.println("FUNÇÕES");
  Serial.println("1-Escreve Dados");
  Serial.println("2-Ativa Servo1");
  Serial.println("3-Ativa Servo2");
  Serial.println("4-Ativa Rele");
  Serial.println("5-Desativa Rele");
  Serial.println("6-Ativa Led");
  Serial.println("7-Desativa Led");
  Serial.println("8-TESTE SERVOS");
  Serial.println("INICIANDO...");
  }
  
void escreveDados(){  
    
  Serial.print("TEMPERATURA: ");
  Serial.print(dadosDHT('t')); //%%%%%%ATENCAO%%%%%%
  Serial.println(" ºC");
  Serial.print("UMIDADE: ");
  Serial.print(dadosDHT('u'));  
  Serial.println(" %");

  Serial.print("LEITURA LDR: ");
  Serial.println(dadosLDR());
  
  Serial.print("MQ2: ");
  Serial.println(dadosGas('a'));
  Serial.print("MQ7: ");
  Serial.println(dadosGas('c'));
  
  Serial.print("PIR: ");
  Serial.println(dadosPIR());

  Serial.print("UMD: ");
  Serial.println(dadosUMD('A')); //%%%%%%ATENCAO%%%%%%

  Serial.println();     
}
  
void lerSerial(){
    int funcao=0;
    int ang;
    if(Serial.available()){
    funcao=Serial.parseInt();
    Serial.println(funcao);
      switch(funcao){
        case 0:
        break;

        case 1:
        escreveDados();
        break;
        
        case 2:
        ativaServo(1);
        break;

        case 3:
        ativaServo(2);
        break;       

        case 4:
        ativaRele(0);
        break;
        
        case 5:
        desativaRele(0);
        break;
        
        case 6:
        ativaLed();
        break;
        
        case 7:
        desativaLed();
        break;

        case 8:
        demonstraServo();
        break;

        case 9:
        cadastraNFC();

        case 10:
        Serial1.println("FOGO");
        
      }
    }
  }

void avisaNoSerial(){
    Serial.println("//// chegou no BT \\\\");
  }
