/////////////////////////////////////////

void operar(){
  while(dadosGas('c')>=setpoint || dadosGas('a')>=setpoint){
    abreJanelaCozinha();
    Serial1.println("FOGO");
    ativaSolenoide();
    abreJanelaCozinha();
    ativaSirene();
    delay(2000);
    desativaSirene();
    delay(1800);
    marcus++;
    //continua travado nesse loop ate o gas sair
  }
  if(marcus!=0){
    desativaSolenoide();
    fechaJanelaCozinha();
    marcus=0;
  }
}
  
void controlaLuzExterna(){
  if(dadosLDR() >700)
  digitalWrite(ledPin, HIGH);
  else
  digitalWrite(ledPin, LOW);

  }

void verificaGas(){
    if(pinMQ2_D0 || pinMQ7_D0){
      digitalWrite(ledPin2, HIGH);
    }
  }

short modoDeSeguranca(){ //INTERRUPÇÃO
    digitalWrite(ledPin2, HIGH);
    ativaRele(1);
    if(pinMQ2_D0 || pinMQ7_D0){
      return(modoDeSeguranca());
    }
      else{
        desativaRele(1);
        digitalWrite(ledPin2, LOW);
      }   
}

void ativaPalmas(){
  int som = digitalRead(pin_somD);
  if(som){
  cont++;
  cont2=0;
  Serial.println(analogRead(pin_somA));
  delay(10);
  }
  

  if(cont==2){
    rele = !rele; //Operacao NAO: Se estiver LOW, passa pra HIGH. Se estiver HIGH passa para LOW
    digitalWrite(pin_rele, rele); // Manda o valor da variavel para o rele
    cont2=0;
    cont=0;
  }
  delay(1);
  cont2++;
  if(cont2==3000){
    cont2=0;
    cont=0;
    Serial.println("RESETANDO");
  }
  
}
