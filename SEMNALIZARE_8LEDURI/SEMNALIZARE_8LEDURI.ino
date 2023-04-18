int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=75;
byte LED0=0b0100000;

byte LED1=0b10000000;
byte LED2=0b11000000;
byte LED3=0b11100000;
byte LED4=0b11110000;
byte LED5=0b11111000;
byte LED6=0b11111100;
byte LED7=0b11111110;
byte LED8=0b11111111;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED0);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED1);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED2);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED3);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED4);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED5);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED6);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED7);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED8);
  digitalWrite(latchPin, HIGH);
  delay(150);
   digitalWrite(latchPin, LOW);
  shiftOut(dataPin , clockPin, LSBFIRST, LED0);
  digitalWrite(latchPin, HIGH);
  delay(150);
  // put your main code here, to run repeatedly:
  

}
