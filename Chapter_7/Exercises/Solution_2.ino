/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
//  Lesson 7, Exercise 2, Bot: Fun Demo Robot
  /*  - search_and_avoid()
    - search_and_destroy()
    - search_and_avoid_musically()
  */

#include "Motor.h"

// Define pins and configuration for managing state
#define button 2
#define led 13
#define stateSwitchDelay 3000

// Define pins to control the sonar sensor
#define echoPin A0
#define pingPin 10

// Define our buzzer pin
#define buzzer 3

// Define pins to control infrared line sensors
#define leftSensor  A1
#define rightSensor A2
#define IREmitter   4

// Motor pins
#define leftMotorSpeed 5
#define rightMotorSpeed 6
#define leftMotorDirection 7
#define rightMotorDirection 8

// Initialize state variables
const int states = 3;
int state = 1;
bool buttonPressed = false;

// Global operational variables
long cm = 0;
const int turnDuration = 600;

// search_and_destroy() attack configuration
const int stopDistance   = 3; // Distance in centimeters
const int attackDistance = 45;

// Create our motor object
Motor motor;

void setup() {
  Serial.begin(9600);
  pinMode(led,    OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(echoPin, INPUT);
  pinMode(pingPin, OUTPUT);

  // Configure our IR sensors
  pinMode(leftSensor,  INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(IREmitter,   OUTPUT);

  // Turn on our IR Emitter and leave it on
  digitalWrite(IREmitter, HIGH);

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
      // we've reached our maximum state, reset to 0
      // and pause until we press the button again
      state = 0;
    } else {
      state = state + 1;
    }

    blink(state);
    delay(stateSwitchDelay);
  }

  switch(state) {
    case 0:
      // Do nothing
      break;
    case 1:
      search_and_avoid();
      break;
    case 2:
      search_and_destroy();
      break;
    case 3: search_and_avoid_musically();
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

// Randomly drive towards the nearest object. Stop when
// the distance to the object is 1cm or less. If the object moves,
// resume searching
void search_and_destroy() {
  // get a random direction, 1 = left, 2 = right
  int turnDirection = 1;

  // get distance in centimeters
  cm = msToCm( ping() );

  // if distance is less than 10, pick a new random direction
  if ( cm < attackDistance ) {
    // We have found an object, attack!
    motor.attack();

    // we are within 1 cm of our object, stop attacking
    // and blink at the target angrily. :)
    if ( cm <= stopDistance ) {
      motor.left(0);
      motor.right(0);

      blink(1);
    }

  } else {
    // We haven't found anything close to us, spin in place
    // until we find something.
    turnDirection = random(1, 3);

    if ( turnDirection == 1 ) {
      motor.left(255);
      motor.right(-255);
    } else {
      motor.left(-255);
      motor.right(255);
    }
  }
  delay(turnDuration/2);
}

// Randomly drive around. If an object is detected closer than
// 10 cm, pick a new direction and drive away.
// As the robot drives, read the current reflectivity from the
// IR sensors and play a musical tone from the buzzer that
// corresponds to the values from the sensors.
void search_and_avoid_musically() {
  // get a random direction, 1 = left, 2 = right
  int turnDirection = 1;

  // get distance in centimeters
  cm = msToCm( ping() );

  /*********************************************************
  DISCUSSION: With our values from our line sensors, we
  have a few different options for choosing how to determine
  which note we want to play. In our Pitches.h library from
  Chapter 5, we have the option of having "named" notes
  ranging from frequencies 31 all the way up to 4978 on the
  high end of the scale.

  One approach would be to manually select a range of notes
  that we want to play and then selecting the note based on
  a large if block and the results of the line sensor readings.

  Another approach would be to simply take the line sensor
  results and pass that number directly to the Arduino tone()
  function (called inside the playNote() function).

  The other thing we need to consider is to decide what to do
  with each sensor. We have two sensors at the front of the
  robot that will both return different values, depending on
  what type of surface your robot is currently driving over.

  Our line sensors return values between 0 and 1023, so the
  easiest approach (and the one we're going to use here) will
  be to simply take both line sensor values, add them together
  and pass that number directly to our playNote() function.

  These combined values will give us a number in a range of
  0 to 2046. We will take that number and use it directly,
  which should produce interesting sounds as your robot drives
  around the room.

  ** PLEASE FEEL FREE TO EXPERIMENT! **
  *********************************************************/
  // Read our line sensor values.
  int leftReading = analogRead(leftSensor);
  int rightReading = analogRead(rightSensor);
  int frequencyToPlay = 2*(leftReading + rightReading);
  // Play the frequency of double the combined sensor readings
  playNote(frequencyToPlay);

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

// Helper function to play musical notes
// NOTE: this function is slightly different than our
// musical playNote function that we developed in Chapter 5.
// We don't want any calls to delay() that would slow down
// the functional operation of our robot. We also don't need
// to specify a duration. When we call playNote with the value
// we get from the IR Line Sensors, we'll continue to play
// that frequency until the value changes.
void playNote(int note) {
  tone(buzzer, note);
}

// Helper function to manage our ultrasonic sensor.
long ping() {
  long duration;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH, 5500);  //setting the timeout to 5500 is helpful but will return 0 whenever pulseIn() times out
  if(duration == 0){
    duration = 5500;  //here we change the 0 value to the actual timeout limit
  }
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
