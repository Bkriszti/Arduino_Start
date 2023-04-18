int GPin=9;
int RPin=8;
int SPin=7;
int ReadValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(SPin, INPUT);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ReadValue=digitalRead(SPin);
  delay(250);
  Serial.println(ReadValue);
}
