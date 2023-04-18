int rp=A0;
float readval;
int buz=9;
float dt;
void setup() {
  // put your setup code here, to run once:
  pinMode(rp, INPUT);
  pinMode(buz, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readval=analogRead(rp);
  Serial.println(readval);
  delay(200);
  dt=3./40.*readval-3./40.*30.+1;
  digitalWrite(buz, HIGH);
  delay(dt);
  digitalWrite(buz, LOW);
  delay(dt);
}
