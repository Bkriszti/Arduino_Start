int ul=11;
int bl=12;
int wl=13;
int rp=6;
int br=255;
int Readp=A0;
float V2=0;
int delaytime=500;
float readval;
void setup() {
  // put your setup code here, to run once:

pinMode(rp, OUTPUT);
pinMode(Readp, INPUT);
Serial.begin(9600);

}

void loop() {
analogWrite(rp, br);
readval=analogRead(Readp);
V2=(5./1023.)*readval;
Serial.println(V2);
delay(delaytime);
}
