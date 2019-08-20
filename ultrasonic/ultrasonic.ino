/*---------------------KRENOVATOR---------------------
  SMART DISTANCE & ALERT

  Demonstrates to aware of the distance using the
  ultrasonic sensor which can measure a distance 
  in centimeter.

  Get the code at github:
  http://bit.ly/SmartDistanceAlert
  
  by M.Zulsyahmi @krenovator
  September 2018
 */

//to initialize the pin used
int trigPin = D4; 
int echoPin = D3;

long duration;
long distance;

void setup() {
  pinMode(trigPin, OUTPUT);   //trigger pin as a receiver
  pinMode(echoPin, INPUT);    //echo pin as a transmitter
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);   //to set the trigger as off
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);  //triggers on
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);   //set back to off

  duration = pulseIn(echoPin, HIGH);  //emits the ultrasonic
  distance = (duration/2)/29.1;       //formula for the distance in ultrasonic in cm

  //for the display in the Serial Monitor
  Serial.print("\nDistance: ");
  Serial.print(distance);
  Serial.print(" cm");
  delay(1000);
}
