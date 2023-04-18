int Mynumb;
int bp=8;
int pp=10;
int readval;
int Vp=A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bp, OUTPUT);
  pinMode(pp, OUTPUT);
  pinMode(Vp, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pp, HIGH);
  readval=analogRead(Vp);
  Serial.println(readval);
  while(readval>1000)
  {
      digitalWrite(bp, HIGH);
      delay(1000);
      digitalWrite(bp,LOW);
      readval=analogRead(Vp);
    

  }
    
 
  delay(500);
}
