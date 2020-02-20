


const int trigPin1 = 12;
const int echoPin1 = 11;
const int trigPin2 = 8;
const int echoPin2 = 9;
const int trigPin3 = 6;
const int echoPin3  = 7;

// defines variables
long duration1;
long duration2;
long duration3;
int distance1;
int distance2;
int distance3;

void setup() {
pinMode(trigPin1, OUTPUT);// Sets the trigPin as an Output
pinMode(trigPin2, OUTPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(echoPin2, INPUT);
pinMode(echoPin3, INPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin1, LOW);
//delayMicroseconds(2)
digitalWrite(trigPin2, LOW);
//delayMicroseconds(2)
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
//digitalWrite(trigPin1, LOW);
//digitalWrite(trigPin2, LOW);
//digitalWrite(trigPin3, LOW);


// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
duration2 = pulseIn(echoPin2, HIGH);
duration3 = pulseIn(echoPin3, HIGH);

// Calculating the distance
distance1= duration1*0.034/2;
distance2= duration2*0.034/2;
distance3= duration3*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
Serial.print("Distance2: ");
Serial.println(distance2);
Serial.print("Distance3: ");
Serial.println(distance3);
}
