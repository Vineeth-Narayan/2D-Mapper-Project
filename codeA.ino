#include <NewPing.h>
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//----------- Enter you Wi-Fi Details---------//
char ssid[] = "xxxxxxxx"; //SSID
char pass[] = "yyyyyyyy"; // Password
//-------------------------------------------//

NewPing sonar1(A0, A1, 100);
NewPing sonar2(A2, A3, 100);
NewPing sonar3(A4, A5, 100);

WiFiClient  client;

unsigned long myChannelField = 123456; // Channel ID
const int ChannelField = 1; // Which channel to write data
const char * myWriteAPIKey = "xxxxxxxxxxx"; // Your write API Key

int dis1,dis2,dis3;
int i;
int dir=0;
int x=0;
int y=0;
int x1,x2,y1,y2;

//Motor A
const int ip2  = 3;    // Pin 15 of L293D IC
const int ip1  = 4;

// Pin 10 of L293D IC
//Motor B
const int ip4  = 5;   // Pin  7 of L293D IC
const int ip3  = 6;

// Pin  2 of L293D IC


void setup() 
{
    pinMode(ip1, OUTPUT);
    pinMode(ip2, OUTPUT);
    pinMode(ip3, OUTPUT);
    pinMode(ip4, OUTPUT);  
    WiFi.mode(WIFI_STA);
    ThingSpeak.begin(client);
    Serial.begin(9600);
    
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
    
  distance();
  if(dis2>30)
  {
    left();
    delay(1000);
    dir=dir+1;
    dir=dir%4;
    stoop();
  }
  else if(dis1>100)
  {
    forward();
    delay(1000);
    stoop();
    plot(dir);
  }
  else 
  {
    right();
    delay(1000);
    dir=dir-1;
    dir=dir%4;
    stoop();
  }
 }

  void distance()
{
  dis1=sonar1.ping_cm();
  dis2=sonar2.ping_cm();
  dis3=sonar3.ping_cm();
  
}

void forward()
{
      digitalWrite(ip1,HIGH);
     
      
      
      digitalWrite(ip2,LOW);

      digitalWrite(ip3,HIGH);
      digitalWrite(ip4,LOW); 
}

void left()
{
  
      
      digitalWrite(ip1,HIGH);
      
      digitalWrite(ip2,LOW);
      digitalWrite(ip3,LOW);
      digitalWrite(ip4,HIGH);
}
void right()
{
 
      
      digitalWrite(ip1,LOW);
      
      digitalWrite(ip2,HIGH);
      
      digitalWrite(ip3,HIGH);
      digitalWrite(ip4,LOW);
}
void stoop()
{

      digitalWrite(ip1,LOW);
      digitalWrite(ip2,LOW);
      digitalWrite(ip3,LOW);
      digitalWrite(ip4,LOW);
}

void plot(int dir)
{
  if(dir==0)
  {
     x1=x-dis2;
     x2=x1;
     y1=y;
     y2=y+20;
     
     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);

     if(dis3<30){
     x1=x+dis3;
     x2=x+dis3;
     y1=y;
     y2=y+20;
     
     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);

     }
     y=y+20;    
  }

  else if(dir==2)
  {
     x1=x+dis2;
     x2=x1;
     y1=y;
     y2=y-20;
     
     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);

     if(dis3<30){
     x1=x-dis3;
     x2=x-dis3;
     y1=y;
     y2=y-20;
     
     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);
  }
  y=y-20;
 }
  else if(dir==1)
  {
    y1=y-dis2;
    y2=y1;
    x1=x;
    x2=x-20;

     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);

     if(dis3<30){
     y1=y+dis3;
     y2=y+dis3;
     x1=x;
     x2=x-20;
     
     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);

     }
     x=x-20;
    
  }

  else if(dir==3)
  {
    y1=y+dis2;
    y2=y1;
    x1=x;
    x2=x+20;

     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);

     if(dis3<30){
     y1=y-dis3;
     y2=y-dis3;
     x1=x;
     x2=x+20;
     
     Serial.println(x1);
     Serial.println(x2);
     Serial.println(y1);
     Serial.println(y2);

     }
     x=x+20;
    
  }
}
