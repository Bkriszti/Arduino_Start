
#include <SoftwareSerial.h>

#include <AltSoftSerial.h>
#include <TinyGPS++.h>


const String PHONE = "+40748486376";
int time;

//--------------------------------------------------------------

#define rxPin 11
#define txPin 10
SoftwareSerial sim800(txPin, rxPin);
//--------------------------------------------------------------
//GPS Module RX pin to Arduino 9
//GPS Module TX pin to Arduino 8
AltSoftSerial neogps;
TinyGPSPlus gps;



const float maxDistance = 30;

//--------------------------------------------------------------
float initialLatitude = 47.179183;
float initialLongitude = 24.172716;
///47.179252, 24.172548
///47.179633, 24.174396
float latitude, longitude;
//--------------------------------------------------------------


void getGps(float& latitude, float& longitude);


void setup()
{

  Serial.begin(9600);
  
  sim800.begin(9600);

  neogps.begin(9600);
 

  sim800.println("AT");
  delay(1000);
  sim800.println("ATE1");
  delay(1000);
  sim800.println("AT+CPIN?"); 
  delay(1000);
  sim800.println("AT+CMGF=1"); 
  delay(1000);
  sim800.println("AT+CNMI=1,1,0,0,0"); 
  delay(1000);
 
  delay(20000);
 
}





void loop()
{
  //--------------------------------------------------------------
  getGps(latitude, longitude);
  //--------------------------------------------------------------
  float distance = getDistance(latitude, longitude, initialLatitude, initialLongitude);
  //--------------------------------------------------------------
  Serial.print("Latitude= "); Serial.println(latitude, 6);
  Serial.print("Lngitude= "); Serial.println(longitude, 6);
  Serial.print("initialLatitude= "); Serial.println(initialLatitude, 6);
  Serial.print("initialLngitude= "); Serial.println(initialLongitude, 6);
  Serial.print("current Distance= "); Serial.println(distance);
  //--------------------------------------------------------------
  
  if(distance > maxDistance) 
      {
        SendMessage();
        delay(60000);
      }
  
  if (sim800.available() > 0)
    Serial.write(sim800.read());

}


float getDistance(float flat1, float flon1, float flat2, float flon2) {

  // Variables
  float dist_calc=0;
  float dist_calc2=0;
  float diflat=0;
  float diflon=0;

  diflat  = radians(flat2-flat1);
  flat1 = radians(flat1);
  flat2 = radians(flat2);
  diflon = radians((flon2)-(flon1));

  dist_calc = (sin(diflat/2.0)*sin(diflat/2.0));
  dist_calc2 = cos(flat1);
  dist_calc2*=cos(flat2);
  dist_calc2*=sin(diflon/2.0);
  dist_calc2*=sin(diflon/2.0);
  dist_calc +=dist_calc2;

  dist_calc=(2*atan2(sqrt(dist_calc),sqrt(1.0-dist_calc)));
  
  dist_calc*=6371000.0; 

  return dist_calc;
}


void getGps(float& latitude, float& longitude)
{
  
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 4000;){
    while (neogps.available()){
      if (gps.encode(neogps.read())){
        newData = true;
        break;
      }


    }
  }
  
  if (newData) 
  {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    newData = false;
  }
  else {
    Serial.println("Date GPS invalide!");
    latitude = 0;
    longitude = 0;
  }
}


void SendMessage()
{
  Serial.println ("Sending Message");
  sim800.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  //Serial.println ("Set SMS Number");
  sim800.println("AT+CMGS=\"" + PHONE + "\"\r"); //Mobile phone number to send message
  delay(1000);
  String SMS = "Dispozitivul a parasit zona de siguranta!http://maps.google.com/?q="+String(latitude) + "," + String(longitude);
  sim800.println(SMS);
  delay(100);
  sim800.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println("SMS Sent Successfully.");
}