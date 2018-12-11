/*---------------------KRENOVATOR---------------------
  Potentiometer

  Demonstrates the potentiometer to understand the analog
  pin and how to code it. 
  
  Get the code at github:
  http://bit.ly/SmartDistanceAlert
  
  by M.Zulsyahmi @krenovator
  September 2018
 */

//initialize the pin used
int Potmeter = A0;
int potVal = 0;

void setup() {  
  //declare the function of each initialized
  pinMode(Potmeter,INPUT);
  
  //burn command to be display on serial monitor
  Serial.begin(9600);
}

void loop() {
   //command to read the analog pin for potentiometer
  int potVal = analogRead(Potmeter);

  //the code for the display in serial monitor
  Serial.print("Analog Read= ");
  Serial.println(potVal);
  delay(500);
}
