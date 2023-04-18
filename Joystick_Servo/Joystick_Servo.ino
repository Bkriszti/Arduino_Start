#include <Servo.h>///
int xPin=A0;
int yPin=A1;
int swPin=9;
int ServoPin=7;
int xval;
int yval;
int swval;
Servo Servo1;
int angle;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(swPin, INPUT);
Servo1.attach(ServoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  xval=analogRead(xPin);
  yval=analogRead(yPin);
  swval=digitalRead(swPin);
  
  angle=(180./1023.)*xval;
  Serial.println(angle);
  Servo1.write(angle);
  delay(250);
}
