/*---------------------KRENOVATOR---------------------
  Potentiometer + LED

  Demonstrates the potentiometer to understand the analog
  pin and how to code it. That potentiometer will triggers
  to the LED if the condition is met.
  
  Get the code at github:
  http://bit.ly/SmartDistanceAlert
  
  by M.Zulsyahmi @krenovator
  September 2018
 */
 
//initialize the pin used for potentiometer and LED 
int Potmeter = A0;
int potVal = 0;

int ledG = 14; //D5
int ledY = 12; //D6
int ledR = 13; //D7

void setup() {  
  //declare the function of each initialized
  pinMode(Potmeter,INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  
  //burn command to be display on serial monitor
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(Potmeter);

  Serial.print("Analog Read= ");
  Serial.println(potVal);
  
  //the condition to be met for the potentiometer to trigger the LED and display in serial monitor
  if (potVal<= 600){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);
  }

  else if (potVal>600 && potVal<=800){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);
  }

  else if (potVal>800){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  }
  delay(250);
}
