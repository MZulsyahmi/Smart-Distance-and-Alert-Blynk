/*---------------------KRENOVATOR---------------------
  SMART DISTANCE & ALERT

  Demonstrates to aware of the distance using the
  ultrasonic sensor which can measure a distance 
  in centimeter where the LED is responded when
  the threshold is reached.

  Get the code at github:
  http://bit.ly/SmartDistanceAlert
  
  by M.Zulsyahmi @krenovator
  September 2018
 */

//to initialize the pin used
int trigPin = D4; 
int echoPin = D3; 

int ledPinR = D7; 
int ledPinY = D6; 
int ledPinG = D5; 

long duration;
long distance;

void setup() {
  pinMode(trigPin, OUTPUT);   //trigger pin as a receiver
  pinMode(echoPin, INPUT);    //echo pin as a transmitter
  
  pinMode(ledPinR, OUTPUT);   //led red for the result shows
  pinMode(ledPinY, OUTPUT);   //led yellow for the result shows
  pinMode(ledPinG, OUTPUT);   //led green for the result shows
  
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

  Serial.print("\nDistance: ");
  Serial.print(distance);             //recall command to be displayed
  Serial.print(" cm");

  /*condition...if else command*/
  if(distance <= 10){     //less than 10cm to give a warning
    Serial.print("    Warning!");   //warning will pop up
    digitalWrite(ledPinR, HIGH);    //led will lights up
    digitalWrite(ledPinY, HIGH);    //led will lights up
  }

  else if (distance > 10 && distance <=20){   //between 10cm and 20cm to give a clear sign
    Serial.print("    Careful!");   //clear sign pop up
    digitalWrite(ledPinR, LOW);     //led red turns off
    digitalWrite(ledPinY, HIGH);    //led yellow turns ON
  }

  else if (distance > 20){    //greater than 20cm to give a clear sign
    Serial.print("    Clear");    //clear sign pop up
    digitalWrite(ledPinR, LOW);     //led red turns off
    digitalWrite(ledPinY, LOW);     //led yellow turns off
    digitalWrite(ledPinG, HIGH);    //led green turns ON
  }
  delay(1000);
}
