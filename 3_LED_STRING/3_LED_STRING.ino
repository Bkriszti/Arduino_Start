String myNumber;
String msg="Al catelea led?";
int l1=8;
int l2=9;
int l3=10;
int dt=100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0)
  {
    
  }
  myNumber=Serial.readString();

  if(myNumber == "led1")
  {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  }
  if(myNumber == "led2 ")
  {
    digitalWrite(l2, HIGH);
    digitalWrite(l1, LOW);
    digitalWrite(l3, LOW);
  }
  if(myNumber == "led3")
  {
    digitalWrite(l3, HIGH);
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
  }
}
