// Lesson 6, Bot: Line Following

  /*Please note that not everything that looks dark, like blue painters tape
    will be dark to infrared sensors.  Test different materials using the Infrared sensor
    code from Lesson 4.2 to make sure that in infrared you have a light background
    and dark line.  If needed change LINE_VALUE below to be a number inbetween your light 
	and dark infrared sensor readings.
  */

#include "Motor.h"

// Pin definitions
// IR Sensors and IR Emitter
#define leftSensor  A1
#define rightSensor A2
#define IREmitter   4

// Motor pins
#define leftMotorSpeed 5
#define rightMotorSpeed 6
#define leftMotorDirection 7
#define rightMotorDirection 8

// Robot configuration
#define MOVE_SPEED 180
#define LINE_VALUE 200
#define DELAY_TIME 10

// Create our motor object
Motor motor;

// Create variables to constantly vary the motor speeds
int leftSpeed = MOVE_SPEED;
int rightSpeed = MOVE_SPEED;

void setup() {
  Serial.begin(9600);
  pinMode(IREmitter,   OUTPUT);
  pinMode(leftSensor,  INPUT);
  pinMode(rightSensor, INPUT);

  motor.setupRight(rightMotorSpeed, rightMotorDirection);
  motor.setupLeft(leftMotorSpeed,   leftMotorDirection);
}

void loop() {
  // Turn on our IREmitter so that our line sensors will get
  // a strong signal.
  digitalWrite(IREmitter, HIGH);
  delayMicroseconds(2);

  // Move using our variables which were initialized to our pre-defined speed.
  motor.left(leftSpeed);
  motor.right(rightSpeed);

  //delay a little to give the robot some time to move to a slightly different position before checking for the line
  delay(DELAY_TIME);

  // Read our line sensor values.
  int leftReading = analogRead(leftSensor);
  int rightReading = analogRead(rightSensor);

  if ( leftReading > LINE_VALUE ) {
    //decrease the left motors speed by 1/10th each time the left sensor sees the line
    leftSpeed = leftSpeed/10*9;
  } else {
    //if the left sensor doesn't see the line set the left motor to the default speed
    leftSpeed = MOVE_SPEED;
  }
  
  if ( rightReading > LINE_VALUE ) {
    //decrease the right motors speed incrementally by 1/10th for each time the right sensor sees the line
    rightSpeed = rightSpeed/10*9; 
  } else {
    //if the right sensor doesn't see the line set the right motor to the default speed
    rightSpeed = MOVE_SPEED;
  }

  //To troubleshoot your code the following print commands are very useful
  Serial.print("Left reading: ");
  Serial.print(leftReading);
  Serial.print("   Right reading: ");
  Serial.println(rightReading);  

}

