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
