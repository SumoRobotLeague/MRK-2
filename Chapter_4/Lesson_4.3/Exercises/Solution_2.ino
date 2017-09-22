/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
//  Lesson 4.3, Exercise 2 Solution - Simple Motor Tests

// Pin definitions
#define leftMotorSpeed 5
#define rightMotorSpeed 6
#define leftMotorDirection 7
#define rightMotorDirection 8

void setup() {
  Serial.begin(9600);
  pinMode(leftMotorSpeed,      OUTPUT);
  pinMode(rightMotorSpeed,     OUTPUT);
  pinMode(leftMotorDirection,  OUTPUT);
  pinMode(rightMotorDirection, OUTPUT);
}

void loop() {
  /* Perform the following three tests and then repeat:
    1. Drive full speed ahead for 3 seconds.
    2. Drive full speed in reverse for 3 seconds.
    3. Spin in place for 3 seconds
  */

  setSpeed(0, 255);
  setSpeed(1, 255);
  delay(3000);

  setSpeed(0, -255);
  setSpeed(1, -255);
  delay(3000);

  setSpeed(0, 255);
  setSpeed(1, -255);
  delay(3000);
}

// int motor defines which motor we want to control.
// motor 0 is our right motor, motor 1 is our left motor.
void setSpeed(int motor, int motorspeed) {
  if ( motor == 0 ) {
    if ( motorspeed < 0 ) {
      digitalWrite(rightMotorDirection, LOW);
      analogWrite(rightMotorSpeed, abs(motorspeed));
    } else {
      digitalWrite(rightMotorDirection, HIGH);
      analogWrite(rightMotorSpeed, motorspeed);
    }
  } else {
    if ( motorspeed < 0 ) {
      digitalWrite(leftMotorDirection, HIGH);
      analogWrite(leftMotorSpeed, abs(motorspeed));
    } else {
      digitalWrite(leftMotorDirection, LOW);
      analogWrite(leftMotorSpeed, motorspeed);
    }
  }
}
/*********************************************************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'*******************************************************************************************************************/
