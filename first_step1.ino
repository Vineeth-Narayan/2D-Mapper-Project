

#include <NewPing.h>

NewPing sonar1(A0, A1, 100);
NewPing sonar2(A2, A3, 100);
NewPing sonar3(A4, A5, 100);

int dis1,dis2,dis3;
int i;

//Motor A
const int ip1  = 4;    // Pin 15 of L293D IC
const int ip2  = 5;
const int pwm1 = 3;
// Pin 10 of L293D IC
//Motor B
const int ip3  = 8;   // Pin  7 of L293D IC
const int ip4  = 7;
const int pwm2  = 6;// Pin  2 of L293D IC
int val=200;
int val2=200;

void distance()
{
  dis1=sonar1.ping_cm();
  dis2=sonar2.ping_cm();
  dis3=sonar3.ping_cm();
  
}

void left()
{
  
      analogWrite(pwm1,val);
      digitalWrite(ip1,HIGH);
      analogWrite(pwm2,val);
      digitalWrite(ip2,LOW);
      digitalWrite(ip3,LOW);
      digitalWrite(ip4,HIGH);
}
void right()
{
 
      analogWrite(pwm2,val);
      digitalWrite(ip1,LOW);
      analogWrite(pwm1,val);
      digitalWrite(ip2,HIGH);
      
      digitalWrite(ip3,HIGH);
      digitalWrite(ip4,LOW);
}
void forward()
{
      digitalWrite(ip1,HIGH);
      analogWrite(pwm1,val);
      
      analogWrite(pwm2,val2);
      digitalWrite(ip2,LOW);

      digitalWrite(ip3,HIGH);
      digitalWrite(ip4,LOW); 
}
void stoop()
{

      digitalWrite(ip1,LOW);
      digitalWrite(ip2,LOW);
      digitalWrite(ip3,LOW);
      digitalWrite(ip4,LOW);
      analogWrite(pwm1, 0);
      analogWrite(pwm2, 0);
}
void setup() 
{
    pinMode(ip1, OUTPUT);
    pinMode(ip2, OUTPUT);
    pinMode(ip3, OUTPUT);
    pinMode(ip4, OUTPUT);  
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    Serial.begin(9600);
    
}

void loop() 
{
     
    distance();
    Serial.print(dis1);
    Serial.print(dis2);
    Serial.println(dis3);
    while (!Serial.available())
    {}
    if(Serial.available() > 0)
    {
      i=Serial.read();
    }
    switch(i)
    {
      case 1:
      forward();
      delay(250);
    
      stoop();
      delay(100);
      break;
      case 3: right();
      delay(420);
      stoop();
      delay(100);
      break;
      case 2: left();
      delay(420);
      stoop();
      delay(100);
      break;
      default: stoop();
    }
  }
              
    
            

    
    

    
    


  
