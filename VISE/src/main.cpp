#include <Arduino.h>



// Define Constants
 
// Connections to A4988
const int dirPin = 48;  // Direction
const int stepPin = 46; // Step
int en = A8;
// Motor steps per rotation
const int STEPS_PER_REV = 2038;
 
void setup() {
  
  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(en, OUTPUT);
}
void loop() {
  
  // Set motor direction clockwise
  digitalWrite(dirPin,HIGH); 
  digitalWrite(en, LOW);
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000); 
  }
  
  // Pause for one second
  delay(1000); 
  
  // Set motor direction counterclockwise
  digitalWrite(dirPin,LOW);
  
  // Spin motor two rotations quickly
  for(int x = 0; x < (STEPS_PER_REV * 2); x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);
  }
  
  // Pause for one second
  delay(1000);
}