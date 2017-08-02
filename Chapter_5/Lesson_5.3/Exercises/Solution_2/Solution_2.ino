//  Lesson 5.3, Solution 2, Attack Method


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

	// Implement a method in motor called Attack() that will
	// drive forward at full speed.
	motor.attack();
}

void loop() {
	// Do nothing but motor.attack() (configured in setup())
}
