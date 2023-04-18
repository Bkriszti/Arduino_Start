 int rp=8;
int gp=9;
int bp=10; 
String Mycolor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(rp, OUTPUT);
  pinMode(gp, OUTPUT);
  pinMode(bp, OUTPUT);
}

void loop() { 
  // put your main code here, to run repeatedly:
  Serial.print("What color do you like to glow?");
  while(Serial.available()==0)
  {

  }
  Mycolor=Serial.readString();
  if(Mycolor=="red")
  {
    digitalWrite(rp, HIGH);
    digitalWrite(bp,LOW);
    digitalWrite(gp, LOW);
  }
  if(Mycolor=="green")
  {
    digitalWrite(rp, LOW);
    digitalWrite(bp,LOW);
    digitalWrite(gp, HIGH);
  }
  if(Mycolor=="blue")
  {
    digitalWrite(rp, LOW);
    digitalWrite(bp,HIGH);
    digitalWrite(gp, LOW);
  }
}
