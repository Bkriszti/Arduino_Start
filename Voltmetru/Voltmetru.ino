int j=1;
int delaytime=750;
String Mystring="j = ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  Serial.print(Mystring);
  Serial.print(j);
  Serial.println();
  j++;
  delay(delaytime);
  if(j==10) exit(-1);
}
