int rp=A0;
float readval;
int rl=9;
int gp=8;
void setup() {
  // put your setup code here, to run once:
  pinMode(rp, INPUT);
  Serial.begin(9600);
  pinMode(rl, OUTPUT);
  pinMode(gp, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  readval=analogRead(rp);
  Serial.println(readval);
  delay(1000);
  if(readval<20)
  {
     digitalWrite(rl, HIGH);
     digitalWrite(gp, LOW);
  }
  
  if(readval>50)
  {
     digitalWrite(gp, HIGH);
      digitalWrite(rl, LOW);
  }
  
  
}
