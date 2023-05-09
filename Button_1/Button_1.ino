int Ledp=8;
int Ledg=9;
int buttonpin=12;
int button2pin=6;
int ButtonNew;
int ButtonOld=1;
int Ledstate1=0;
int ButtonNew1;
int ButtonOld1=1;
int Ledstate2=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(Ledp, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
  pinMode(Ledg, OUTPUT);
  pinMode(button2pin, INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  ButtonNew=digitalRead(buttonpin);
  
  if(ButtonOld==0 && ButtonNew==1){
    if(Ledstate1==0){
      digitalWrite(Ledp, HIGH);
      Ledstate1=1;
    }
    else{
      digitalWrite(Ledp, LOW);
      Ledstate1=0;
    }
  }
  ButtonOld=ButtonNew;

  ButtonNew1=digitalRead(button2pin);
  Serial.println(ButtonNew1);
  if(ButtonOld1==0 && ButtonNew==1)  
  {
    if(Ledstate2==0){
      digitalWrite(Ledg, HIGH);
      Ledstate2=1;
    }
    else{
      digitalWrite(Ledg, LOW);
      Ledstate2=0;
    }
  }
  ButtonOld1=ButtonNew1;

}
