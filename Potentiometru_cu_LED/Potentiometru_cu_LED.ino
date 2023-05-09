int Voltmeter=A0;
int readval;
float V0;
int V=6;
int delayt=75;
int p=255;
int rl=9;
float VLED;
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
  Serial.println(V0);
  VLED=readval*(255./1023.);
  analogWrite(rl, VLED);
  
  
}
