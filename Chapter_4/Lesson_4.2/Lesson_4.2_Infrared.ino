/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
//  Lesson 4.2, Infrared Line Detection Sensors

#define leftSensor  A1
#define rightSensor A2
#define IREmitter   4

void setup() {
	Serial.begin(9600);
	pinMode(leftSensor, INPUT);
	pinMode(rightSensor, INPUT);
	pinMode(IREmitter, OUTPUT);
}

void loop() {
	digitalWrite(IREmitter, HIGH);
	int rightInput = analogRead(rightSensor);
	int leftInput  = analogRead(leftSensor);
	Serial.print("Left/");
	Serial.print(leftInput);
	Serial.print(" - Right/");
	Serial.println(rightInput);
	delay(500);
}
/*********************************************************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'*******************************************************************************************************************/
