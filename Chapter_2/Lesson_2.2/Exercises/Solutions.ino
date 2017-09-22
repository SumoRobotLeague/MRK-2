/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
//Chapter 2 Lesson 2.2 Solutions

void setup() {
	Serial.begin(9600);

	int a = 5;
	int b = a + 12;
	a = 10;
	float c = 7.2;
	int d = c * a;
	int e = 9 / 4;
	int irSensors[] = { A1, A2, A3 };

	// Question 1 Solution
	Serial.print("Question 1: The current value of b is: ");
	Serial.println(b);

	// Question 2 Solution
	Serial.print("Question 2: The final value of a is: ");
	Serial.println(a);

	// Question 3 Solution
	Serial.print("Question 3: The final value of d is: ");
	Serial.println(d);

	// Question 4 Solution
	Serial.print("Question 4: The IR Sensor in irSensors[] at index 2 is: ");
	Serial.println(irSensors[2]);

	// Question 5 Solution
	Serial.print("Question 5: The IR Sensor in irSensors[] at index 0 is: ");
	Serial.println(irSensors[0]);
	
	// Question 6 Solution
	Serial.print("Question 6: The final value of e is: ");
	Serial.println(e);
}

void loop() {

}
/*********************************************************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'*******************************************************************************************************************/
