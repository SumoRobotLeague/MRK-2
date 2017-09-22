/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
//  Lesson 3.3 - Using If Blocks

void setup() {
  Serial.begin(9600);

  int your_age = 23;

  // check the permissions using the integer variable "age" defined above
  // Try changing the age and seeing what happens at different ages.
  checkPermissions_if(your_age);
}

void loop() {
}

//As written checkPermissions_if() prints a response ONLY if the age matches one of the 4 categories
//Try changing the == to <, >, <=, >=, or != 
void checkPermissions_if(int age) {
  if ( age == 15 ) {
    Serial.println("learner's permit");
  }
  if ( age == 16 ) {
    Serial.println("driver's license");
  }
  if ( age == 18 ) {
    Serial.println("lottery tickets");
  }
  if ( age == 25 ) {
    Serial.println("insurance discount");
  }
}
/*********************************************************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'*******************************************************************************************************************/
