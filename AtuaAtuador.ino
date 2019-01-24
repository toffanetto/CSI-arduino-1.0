//////////////////////////////////////

void ativaServo(int servo){
  int ang;
  if(servo==1){
    Serial.print("Digite o angulo do servo1: ");   
    if(Serial.available()){
    ang=Serial.parseInt();
    }
        Serial.println(ang);
        servoPorta.write(ang);
  }
  if(servo==2){
    Serial.print("Digite o angulo do servo2: ");   
    if(Serial.available()){
    ang=Serial.parseInt();
    }
    Serial.println(ang);
    servoJanela.write(ang);
  }
}

void ativaRele(int rele){
  //int rele;
    Serial.print("Digite o rele:");
    if(Serial.available()){
    rele=Serial.parseInt();
    }
    Serial.println(rele);
  if(rele==1)
  digitalWrite(pinRele_1,LOW);
}

void desativaRele(int rele){
  //int rele;
  Serial.print("Digite o rele:");
  if(Serial.available()){
  rele=Serial.parseInt();
  }
   Serial.println(rele); 
  if(rele==1)
  digitalWrite(pinRele_1,HIGH);
}

void ativaLed(){
  int led;
    Serial.print("Digite o LED:");
    if(Serial.available()){
    led=Serial.parseInt();
    }
    Serial.println(led);
  switch(led){
    case 1:
    digitalWrite(ledAmarelo,HIGH);
    break;

    case 2:
    digitalWrite(ledQuarto,HIGH);
    break;

    case 3:
    digitalWrite(ledVerde,HIGH);
    break;
  }
 }

void desativaLed(){
  int led;
  
    Serial.print("Digite o LED:");
    if(Serial.available()){
    led=Serial.parseInt();
    }
    Serial.println(led);
  switch(led){
    case 1:
    digitalWrite(ledAmarelo,LOW);
    break;

    case 2:
    digitalWrite(ledQuarto,LOW);
    break;

    case 3:
    digitalWrite(ledVerde,LOW);
    break;
  }
 }

void demonstraServo(){
  servoPorta.write(180);
  servoJanela.write(0);
  delay(500);
  servoPorta.write(0);
  servoJanela.write(180);
  delay(500);
  servoPorta.write(45);
  servoJanela.write(45);
  delay(300);
  servoPorta.write(180);
  servoJanela.write(0);    
}

void abrePorta(){
    servoPorta.write(0);
  }

void fechaPorta(){
    servoPorta.write(180);
  }

void abreJanelaCozinha(){
    servoJanela.write(0);
  }

  void fechaJanelaCozinha(){
    servoJanela.write(180);
  }

void acendeLuzQuarto(){
    digitalWrite(ledQuarto,HIGH);    
  }

void apagaLuzQuarto(){
    digitalWrite(ledQuarto,LOW);
  }

void acendeLuzCozinha(){
    digitalWrite(ledVerde,HIGH);
  }

void apagaLuzCozinha(){
    digitalWrite(ledVerde,LOW); 
  }

void acendeLuzSala(){
    digitalWrite(ledNaoSei1,HIGH);
  }

void apagaLuzSala(){
    digitalWrite(ledNaoSei1,LOW);
  }

void acendeLuzGaragem(){
    digitalWrite(ledVermelho,HIGH);
  }

void apagaLuzGaragem(){
    digitalWrite(ledVermelho,LOW);
  }

void abrePortao(){
    servoPortao.write(0);
  }

void fechaPortao(){
    servoPortao.write(180);
  }

void acendeLuz1(){
    digitalWrite(ledNaoSei1,HIGH);
  }
  

void apagaLuz1(){
    digitalWrite(ledNaoSei1,LOW);
  }
  

void acendeLuzQuartoS(){
    digitalWrite(ledAmarelo,HIGH);
  }
  

void apagaLuzQuartoS(){
   digitalWrite(ledAmarelo,LOW);
  }
  

//void acendeLuz3(){
//    digitalWrite(ledNaoSei3,HIGH);
//  }
  

//void apagaLuz3(){
//    digitalWrite(ledNaoSei3,LOW);
//  }

  void ligaVentiladorSala(){
    digitalWrite(pinVentiladorSala, HIGH);
  }

  void desligaVentiladorSala(){
    digitalWrite(pinVentiladorSala, LOW);
  }

  void ativaSolenoide(){
    digitalWrite(pinRele_1, HIGH);
  }

  void desativaSolenoide(){
    digitalWrite(pinRele_1, LOW);
  }
