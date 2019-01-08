////////////////////////////////////////

float dadosDHT(char selectDHT){
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  float umidadeprint = umidade + 200;
  if (isnan(umidade) || isnan(temperatura)){
    return(99,99);
  }
  if(selectDHT=='t'){
    return(temperatura);
  }
  else if(selectDHT=='u'){
    return(umidade);
  }
}

int dadosUMD(char selectUMD){
  int umidadeDoSolo;
  int umidadeDoSoloBool;
  umidadeDoSolo=analogRead(A3);
  umidadeDoSoloBool=digitalRead(pinUMD_D0);
  //Serial.println(umidadeDoSolo);

  if(selectUMD=='A'){
    return(umidadeDoSolo);
  }
  else if(selectUMD=='D')
    return(umidadeDoSoloBool);
}

int dadosLDR(){
  int ldr_read;
  ldr_read=analogRead(LDR);
  return(ldr_read);  
}

int dadosGas(char selectMQ){
  bool mq2_D0;
  bool mq7_D0;
  int mq2_A0;
  int mq7_A0;
  mq2_D0=digitalRead(pinMQ2_D0);
  mq7_D0=digitalRead(pinMQ7_D0);
  mq2_A0=analogRead(pinMQ2_A0);
  mq7_A0=analogRead(pinMQ7_A0);

  if(selectMQ=='a'){
    return(mq2_A0);
  }
  if(selectMQ=='b'){
    return(mq2_D0);
  }
  if(selectMQ=='c'){
    return(mq7_A0);
  }
  if(selectMQ=='d'){
    return(mq7_D0);
  }    
}

bool dadosPIR(){
  return(digitalRead(pinPIR));
}
