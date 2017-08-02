//  Lesson 5.3, Solution 3, Abort Method


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

	// Implement a method in motor called abort() that will
	// drive in reverse at full speed.
	motor.abortNow();
}

void loop() {
	// Do nothing but abortNow (configured in setup())
}
