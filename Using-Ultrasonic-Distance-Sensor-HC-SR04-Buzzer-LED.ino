// defines pins numbers

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <inttypes.h>
#include <Arduino.h>
#include <Wire.h>



// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;


// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {

	// Turn on the blacklight and print a message.

	lcd.begin();
  lcd.clear();                                                         //Clear the LCD                                                  //Set the LCD cursor to position to position 0,0
  lcd.print("MPU-6050 IMU"); 
	// lcd.print("Hello, world!");


pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  lcd.print(safetyDistance);

}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  lcd.print("Not close yet");
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
