int bup=A1;
int bdown=A0;
int ledPin=9;
int readval1;
int readval2;
int currentSt=0;
void setup() {

  // put your setup code here, to run once:
  pinMode(bup, INPUT);
  pinMode(bdown, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readval1=digitalRead(bdown);
  readval2=digitalRead(bup);
  delay(100);
  if(readval1==0)
    currentSt=currentSt-51;
  if(readval2==0)
    currentSt=currentSt+51;
  if(currentSt>255)
    currentSt=255;
  if(currentSt<0)
    currentSt=0;
  analogWrite(ledPin,currentSt);


}
