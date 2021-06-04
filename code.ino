#include <Stepper.h>
#include <LiquidCrystal.h> // includes the LiquidCrystal Library

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int stepsPerRevolution = 50;
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
// Define number of steps per rotation:


int i=0,a=0;
// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver
const int trigPin = 12;
const int echoPin = 13 ;
long duration;
float distanceCm,j=0 ;
void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
 // Set the speed to 5 rpm:
  myStepper.setSpeed(155);
  
  // Begin Serial communication at a baud rate of 9600:
  
}
void loop() {

  for(i=0,j=0;i<40;i++)
  {
 Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
if(distanceCm>=20) {
    lcd.clear();
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("NO OBSTACLE");
  lcd.setCursor(0,1);// Sets the location at which subsequent text written to the LCD will be displayed
lcd.print(" IN RANGE"); // Prints string "Angle" on the LCD
  delay(10);
  }
  else{
      lcd.clear();
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm");
delay(10);
lcd.setCursor(0,1);// Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Angle: "); // Prints string "Angle" on the LCD
lcd.print(j); // Prints the Angle value from the motor
lcd.print(" deg");
delay(2000);
  }
  j=j+8.8;
 }
 for(a=0,j=360;a<=40;a++)
  {
   Serial.println("anticlockwise");
  myStepper.step(-stepsPerRevolution);
 
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
 if(distanceCm>=20) {
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.clear();
 lcd.print("NO OBSTACLE");
  lcd.setCursor(0,1);// Sets the location at which subsequent text written to the LCD will be displayed
lcd.print(" IN RANGE"); // Prints string "Angle" on the LCD
  delay(10);
  }
  else{
      lcd.clear();
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm");
delay(10);
lcd.setCursor(0,1);// Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Angle: "); // Prints string "Angle" on the LCD
lcd.print(j); // Prints the Angle value from the motor
lcd.print(" deg");
delay(2000);
  }
  j=j-8.8;
  }
  }
