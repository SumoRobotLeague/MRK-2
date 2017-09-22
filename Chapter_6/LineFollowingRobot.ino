/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
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
#define MOVE_SPEED 150
#define LINE_VALUE 100
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
  delayMicroseconds(1);

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
    leftSpeed = leftSpeed*9/10;
  } else {
    //if the left sensor doesn't see the line set the left motor to the default speed
    leftSpeed = MOVE_SPEED;
  }
  
  if ( rightReading > LINE_VALUE ) {
    //decrease the right motors speed incrementally by 1/10th for each time the right sensor sees the line
    rightSpeed = rightSpeed*9/10; 
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

/*********************************************************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'*******************************************************************************************************************/
