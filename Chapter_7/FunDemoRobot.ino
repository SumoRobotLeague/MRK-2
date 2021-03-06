/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
//  Lesson 7, Bot: Fun Demo Robot

#include "Motor.h"

// Define pins and configuration for managing state
#define button 2
#define led 13
#define stateSwitchDelay 3000

// Define pins to control the sonar sensor
#define echoPin A0
#define pingPin 10

// Motor pins
#define leftMotorSpeed 5
#define rightMotorSpeed 6
#define leftMotorDirection 7
#define rightMotorDirection 8

// Initialize state variables
const int states = 1;
int state = 1;
bool buttonPressed = false;

// Global operational variables
long cm = 0;
const int turnDuration = 600;

// Create our motor object
Motor motor;

void setup() {
  Serial.begin(9600);
  pinMode(led,    OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(echoPin, INPUT);
  pinMode(pingPin, OUTPUT);

  // Configure our motors
  motor.setupRight(rightMotorSpeed, rightMotorDirection);
  motor.setupLeft(leftMotorSpeed, leftMotorDirection);

  // Once setup is complete, start our robot in our
  // first operational state.
  blink(state);
  delay(stateSwitchDelay);
}

void loop() {
  if ( digitalRead(button) == 0 ) {
    // the button is being held down
    buttonPressed = true;
  }
  if ( buttonPressed && digitalRead(button) == 1 ) {
    // the button WAS held down and was just released
    buttonPressed = false;

    if ( state == states ) {
      // we've reached our maximum state, reset to 1
      state = 0;
    } else {
      state = state + 1;
    }

    blink(state);
    delay(stateSwitchDelay);
  }

  switch(state) {
    case 0:
      // do nothing
      motor.left(0);
      motor.right(0);
      break;
    case 1:
      search_and_avoid();
      break;
  }
}

// Randomly drive around. If an object is detected closer than
// 10 cm, pick a new direction and drive away.
void search_and_avoid() {
  // get a random direction, 1 = left, 2 = right
  int turnDirection = 1;

  // get distance in centimeters
  cm = msToCm( ping() );

  // if distance is less than 10, pick a new random direction
  if ( cm < 10 ) {
    turnDirection = random(1, 3);

    if ( turnDirection == 1 ) {
      motor.left(255);
      motor.right(-255);
      delay(turnDuration);
    } else {
      motor.left(-255);
      motor.right(255);
      delay(turnDuration);
    }
  } else {
    // if distance is greater than 10, just drive forward
    motor.left(255);
    motor.right(255);
  }
}

// Helper function to manage our ultrasonic sensor.
long ping() {
  long duration;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  return duration;
}

// Helper function to return the distance to an object
// detected by the ultrasonic sensor in centimeters.
long msToCm(long microseconds) {
  return microseconds / 29 / 2;
}

// Simple blink function called in loop() whenever a state
// change is made by a user button press.
void blink(int blinks) {
  for ( int i = 0; i <= blinks; i++ ) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
}
/*********************************************************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'*******************************************************************************************************************/
