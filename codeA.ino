#include <NewPing.h>

NewPing sonar1(A0, A1, 100);
NewPing sonar2(A2, A3, 100);
NewPing sonar3(A4, A5, 100);

int dis1,dis2,dis3;
int i;
int dir=0;
int x=0;
int y=0;
int x1,x2,y1,y2;

//Motor A
const int ip1  = 4;    // Pin 15 of L293D IC
const int ip2  = 5;

// Pin 10 of L293D IC
//Motor B
const int ip3  = 8;   // Pin  7 of L293D IC
const int ip4  = 7;

// Pin  2 of L293D IC

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
void setup() 
{
    pinMode(ip1, OUTPUT);
    pinMode(ip2, OUTPUT);
    pinMode(ip3, OUTPUT);
    pinMode(ip4, OUTPUT);  
    
    Serial.begin(9600);
    
}

void loop()
{
  distance();
  if(dis2>30)
  {
    left();
    delay(100);
    dir=dir+1;
    dir=dir%4;
  }
  else if(dis1>100)
  {
    forward();
    delay(100);
    plot(dir);
  }
  else 
  {
    right();
    delay(100);
    dir=dir-1;
    dir=dir%4;
  }
 }

  
