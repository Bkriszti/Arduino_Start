int myNumber;
String msg="Introduceti numarul dvs: ";
String msg2="Nr introdus este: ";
int dt=500;
int mo=9;
int readPin=A0;
float pval;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mo, OUTPUT);
  pinMode(readPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0)
  {

  }
  myNumber=Serial.parseInt();
  for(int i=1;i<=myNumber;i++)
  {
    digitalWrite(wl, HIGH);
    delay(dt);
    digitalWrite(wl, LOW);
    delay(dt);
  }
}
