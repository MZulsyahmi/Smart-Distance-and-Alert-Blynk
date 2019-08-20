/*---------------------KRENOVATOR---------------------
  SMART DISTANCE & ALERT

  Demonstrates to aware of the distance using the
  ultrasonic sensor which can measure a distance 
  in centimeter where the LED is responded when
  the threshold is reached with the display from
  OLED.

  Get the code at github:
  http://bit.ly/SmartDistanceAlert
  
  by M.Zulsyahmi @krenovator
  September 2018
 */

/*the library that needed to be included in the codes*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//to initialize the pin used
int trigPin = D4; 
int echoPin = D3; 

int ledPinR = D8;     // LED red
int ledPinY = D7;     // LED yellow
int ledPinG = D6;     // LED green

int buzzer = D5;      // buzzer

long duration;
long distance;
  
void setup() {
  //declaration of each pin
  pinMode(trigPin, OUTPUT);   //trigger pin as a receiver
  pinMode(echoPin, INPUT);    //echo pin as a transmitter
  
  pinMode(ledPinR, OUTPUT);  
  pinMode(ledPinY, OUTPUT);  
  pinMode(ledPinG, OUTPUT);  

  pinMode(buzzer, OUTPUT);    //buzzer
  
  display.clearDisplay();

  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
}

void loop() {
  display.clearDisplay();
  digitalWrite(trigPin, LOW);   //to set the trigger as off
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);  //triggers on
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);   //set back to off

  duration = pulseIn(echoPin, HIGH);  //emits the ultrasonic
  distance = (duration/2)/29.1;       //formula for the distance in ultrasonic in cm

  //codes for display in OLED
  display.setTextColor(WHITE);        //set the color of the text
  display.setCursor(0,0);             //place the text (column,row)
  display.setTextSize(1);             //text size
  display.print("Distance:\n");
  display.setTextSize(2);
  display.print(distance);
  display.print(" cm\n\n");

  /*condition...if else command*/
  if(distance <= 10){ //less than 10cm to give a warning
    display.setTextColor(WHITE);
    display.setTextSize(1);  
    display.print("             Warning!");   //warning will pop up
    digitalWrite(ledPinR, HIGH);              //led will lights up
    digitalWrite(ledPinY, HIGH);              //led will lights up
    digitalWrite(buzzer,HIGH);                // buzzer will turn ON
  }

  else if (distance > 10 && distance <=20){ //between 10cm and 20cm to give a clear sign
    display.setTextColor(WHITE);
    display.setTextSize(1);  
    display.print("       Careful!");   //careful sign pop up
    digitalWrite(ledPinR, LOW);         //led red turns off
    digitalWrite(ledPinY, HIGH);        //led yellow turns ON
    digitalWrite(buzzer,LOW);           // buzzer will turn OFF
  }

  else if (distance > 20){ //greater than 20cm to give a clear sign
    display.setTextColor(WHITE);
    display.setTextSize(1);  
    display.print("Clear");         //clear sign pop up
    digitalWrite(ledPinR, LOW);     //led red turns off
    digitalWrite(ledPinY, LOW);     //led yellow turns off
    digitalWrite(ledPinG, HIGH);    //led green turns ON
    digitalWrite(buzzer,LOW);       // buzzer will turn OFF
  }
  display.display();
  delay(1000);
}
