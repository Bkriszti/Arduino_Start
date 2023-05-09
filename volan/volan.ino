int ppin=A0;
int val;
int power1;
int mpin=9;
void setup() {
  // put your setup code here, to run once:
  pinMode(ppin, INPUT);
  pinMode(mpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(ppin);
  delay(100);
  
  power1=(255./-480)*(val-530);
  Serial.println(power1);
  analogWrite(mpin, power1);
}
