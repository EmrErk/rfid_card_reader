#include<RFID.h>
#include<SPI.h>

RFID rfid(10,9); // RST,SDA pinlerini tanımlama 

void setup(){
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop(){

  if(rfid.isCard()){

    if(rfid.readCardSerial()){

      Serial.print(" ID Numarası: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(" ");
      Serial.print(rfid.serNum[1]);
      Serial.print(" ");
      Serial.print(rfid.serNum[2]);
      Serial.print(" ");
      Serial.print(rfid.serNum[3]);
      Serial.print(" ");
      Serial.println(rfid.serNum[4]);
    }
    rfid.halt();    
  }
}