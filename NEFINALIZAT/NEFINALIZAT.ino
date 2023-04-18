int lp=8;
int bp=12;
int ButtonRead;
int dt=250;
void setup() {
  // put your setup code here, to run once:
  pinMode(lp, OUTPUT);
  pinMode(bp, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ButtonRead=digitalRead(bp);
  Serial.println(ButtonRead);
  if(ButtonRead==1)
       I’m  digitalWrite(lp, LOW);

  else 
      digitalWrite(lp, HIGH);
}
