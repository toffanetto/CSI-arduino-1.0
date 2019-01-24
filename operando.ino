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
    sinVal = (sin(x*(3.1416/180)));
    toneVal = 2000+(int(sinVal*1000));
    tone(pinAltoFalante, toneVal);
    x++;
    if(x>180)
    x=0;
}

void ativaPalmas(){
  int som = digitalRead(pin_somD);
  if(som){
  cont++;
  cont2=0;
  //Serial.println(analogRead(pin_somA));
  } 

  if(cont==2){
    rele = !rele; //Operacao NAO: Se estiver LOW, passa pra HIGH. Se estiver HIGH passa para LOW
    digitalWrite(ledAmarelo, rele); // Manda o valor da variavel para o rele
    cont2=0;
    cont=0;
  }
  cont2++;
  if(cont2==3000){
    cont2=0;
    cont=0;
    //Serial.println("RESETANDO");
  }
  
}
