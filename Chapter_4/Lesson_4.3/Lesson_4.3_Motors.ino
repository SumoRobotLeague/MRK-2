//  Lesson 4.3, Motor Control

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
  delay(1000);
}

void loop() {
  // Set our right motor to go full speed forward
  digitalWrite(rightMotorDirection, HIGH);  //on the rightMotorDirection pin LOW = reverse and HIGH = forward
  analogWrite(rightMotorSpeed, 255);
  
  // Set our left motor to go full speed in reverse
  // NOTE: The left motor is installed backwards, so
  // "forward" is the opposite motor direction from
  // your right motor.
  // LOW = forward, HIGH = reverse
  digitalWrite(leftMotorDirection, HIGH);
  analogWrite(leftMotorSpeed, 255);
}
