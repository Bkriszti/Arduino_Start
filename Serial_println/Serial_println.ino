int Voltmeter=A0;
int readval;
float V0;
int V=6;
int delayt=750;
int p=255;
int rl=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(Voltmeter, INPUT);
  pinMode(V,OUTPUT);
  pinMode(rl, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(V, p);
  readval=analogRead(Voltmeter);
  V0=(5./1023.)*readval;
  if(V0>=2.6)
  {
    digitalWrite(rl, HIGH);
    Serial.println(V0);
  delay(delayt);
  }
  else 
  {
    digitalWrite(rl, LOW);
    Serial.println(V0);
     delay(delayt);
  }
  
}
