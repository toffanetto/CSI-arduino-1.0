/////////////////////////////////////////

void operar(){
  while(dadosGas('c')>=setpointGas || dadosGas('a')>=setpointGas){
    marcus++;
    modoDeSeguranca();
    
    //continua travado nesse loop ate o gas sair
  }
  if(marcus!=0){
    desativaSolenoide();
    fechaJanelaCozinha();
    digitalWrite(ledPin2, LOW);
    marcus=0;
  }
  ativaPalmas();
  if(dadosUMD('A')<setpointUmidade){
    //POEM AGUA NA PORRA DO VASO
  }
  controlaLuzExterna();
 
}
  
void controlaLuzExterna(){
  if(dadosLDR() >700)
  digitalWrite(ledPin, HIGH);
  else
  digitalWrite(ledPin, LOW);
}

void modoDeSeguranca(){ //INTERRUPÇÃO
    abreJanelaCozinha();
    Serial1.println("FOGO");
    ativaSolenoide();
    digitalWrite(ledPin2, HIGH);
    ativaSirene();
    delay(2000);
    desativaSirene();
    delay(1800);
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
