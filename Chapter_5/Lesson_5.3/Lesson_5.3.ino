//  Lesson 5.3, A Motor Control Library

#include "Motor.h"

// Pin definitions
#define leftMotorSpeed 5
#define rightMotorSpeed 6
#define leftMotorDirection 7
#define rightMotorDirection 8

// Create a new motor object from our class
Motor motor;

void setup() {
  motor.setupRight(rightMotorSpeed, rightMotorDirection);
  motor.setupLeft(leftMotorSpeed, leftMotorDirection);

  motor.left(255);
  motor.right(-255);
}

void loop() {
  // Do nothing but spin (configured in setup())
}
