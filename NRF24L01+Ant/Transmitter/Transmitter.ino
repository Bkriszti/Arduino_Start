#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7,8);
const byte adress[6]="00001";

void setup() {
  // put your setup code here, to run once:
radio.begin();
radio.openWritingPipe(adress);
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  const char text[]="Hello Kriszti";
  radio.write(&text, sizeof(text));
  delay(1000);
}
