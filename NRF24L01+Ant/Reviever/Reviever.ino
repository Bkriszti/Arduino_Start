#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7,8);
const byte adress[6]="00001";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0,adress);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(radio.available())
  {
    char text[32]="";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
