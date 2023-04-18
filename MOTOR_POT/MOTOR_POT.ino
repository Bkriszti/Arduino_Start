int myNumber;
String msg="Introduceti numarul dvs: ";
String msg2="Nr introdus este: ";
int dt=500;
int mo=9;
int pp=7;
int readPin=A0;
float pval,readval;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mo, OUTPUT);
  pinMode(readPin, INPUT);
  pinMode(pp, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pp, HIGH);
  readval=analogRead(readPin);
  pval=(255./1020.)*readval;
  Serial.println(pval);
  analogWrite(mo, pval);
}
