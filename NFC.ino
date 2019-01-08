////////////////////////////////////

  uint8_t cadastrados[1000];
  int contCadastrados=0;

void readNFC(){
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);

  if(verificaCartaoNFC(uid,uidLength,contCadastrados)){
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
  }
  }
    
bool verificaCartaoNFC(uint8_t value[6], uint8_t lenght, int nCadastrados){
  
  for(int i=0;i<contCadastrados;i++){
    int contSucess=0;
    for(int j=i*lenght;j<i*lenght+lenght;j++){
      if(value[j]==cadastrados[j]){
        contSucess++;
      }
      if(contSucess==lenght){
        return true;
      }
    }
    if(i==nCadastrados-1)
    return false;
  }


  }

void cadastraNFC(){
    boolean success;
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
    uint8_t uidLength;
    success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);

    if(success){
    contCadastrados++;    
    for(int i=contCadastrados-1;i<uidLength;i++){
      cadastrados[i]=uid[i];
    }
  }
  }
  

  
