////////////////////////////////

void lerBluetooth(){
    int cod=0;
    if(Serial1.available()){
      //avisaNoSerial();
      cod=Serial1.read();
      if(cod!=0)
      Serial.println(cod);
      switch(cod){
        case 0:
        break;

        case 1:
        abrePorta();
        break;

        case 2:
        fechaPorta();
        break;

        case 3:
        acendeLuzQuarto();
        break;

        case 4:
        apagaLuzQuarto();
        break;

        case 5:
        acendeLuzCozinha();
        break;

        case 6:
        apagaLuzCozinha();
        break;

        case 7:
        abrePortao();
        break;

        case 8:
        fechaPortao();
        break;

        case 9:
        acendeLuzSala();
        break;

        case 10:
        apagaLuzSala();
        break;

        case 11:
        acendeLuzGaragem();
        break;

        case 12:
        apagaLuzGaragem();
        break;

        case 13:
        abreJanelaCozinha();
        break;

        case 14:
        fechaJanelaCozinha();
        break;

        case 15:
        acendeLuz1();
        break;

        case 16:
        apagaLuz1();
        break;

        case 17:
        acendeLuzQuartoS();
        break;

        case 18:
        apagaLuzQuartoS();
        break;

    /*  case 19:
        acendeLuz3();
        break;

        case 20:
        apagaLuz3();
        break;
    */
        case 21:
        ligaVentiladorSala();
        break;

        case 22:
        desligaVentiladorSala();
        break;

                
      }
    }
  }

void escreveBluetooth(){

      if(!dadosGas('b')){
        Serial1.println("SFE");
      }
      else if(dadosGas('b')){
        Serial1.println("SFA");
      }

      if(!dadosGas('d')){
        Serial1.println("SGE");
      }
      else if(dadosGas('d')){
        Serial1.println("SGA");
      }

      if(!dadosPIR()){
        Serial1.println("SPD");
      }
      else if(dadosPIR()){
        Serial1.println("SPA");
      }


      Serial1.println(int(dadosDHT('t')));

      Serial1.println(int(dadosDHT('u')+200));
          
   }
