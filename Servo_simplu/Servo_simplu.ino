#include <Servo.h>
int servopin=9;
int servoPos;
Servo Servo1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Servo1.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Angle of servo?");
  while(Serial.available()==0)
  {
    
  }
  servoPos=Serial.parseInt();

  Servo1.write(servoPos);
  delay(100);
}
