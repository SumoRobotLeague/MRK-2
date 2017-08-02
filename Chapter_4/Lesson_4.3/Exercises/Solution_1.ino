//  Lesson 4.3, Exercise 1 Solution - setSpeed Function

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
  // Have our robot spin in place at full speed

  // Right motor at full speed forward
  setSpeed(0, 255);

  // Left motor at full speed in reverse
  setSpeed(1, -255);
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
