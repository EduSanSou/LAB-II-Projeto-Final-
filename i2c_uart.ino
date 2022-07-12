//Codigo para testar a comunicação UART entre a GUI e o Arduino UNO (recebimento da string de movimentação)
#include <Wire.h>

void setup()
{
  Wire.begin(0x0A);                
  Wire.onReceive(receiveEvent);
  digitalWrite(SCL, LOW);
  digitalWrite(SDA, LOW);
  Serial.begin(115200);          
}

void loop() {
  if(Serial.available()){
   String mov_string = Serial.readString(); //arduino armazena string de movimento
  }
}


void receiveEvent(int numBytes)
{
  while (1 < Wire.available())
  { 
    char td = Wire.read();
    Serial.print(td);        
  }
  int valor = Wire.read();    
  Serial.println("");
  Serial.println(valor, HEX);   
  Serial.println(valor, BIN);
  Serial.println(valor, OCT);
  Serial.println(valor);       
}
