/********************************************************************
An Introduction to Robot Programming
  Second Edition  --  Fall 2017
Authors - Eric Ryan Harrison <me@ericharrison.info> & William J Ashby, PhD <will@scibrary.org>
http://github.com/SumoRobotLeague/MRK-2/ contains the complete collection
Our code is open source, MIT License (details at the end).
Please use our code in your projects and tell your friends about us!

The MRK-2 robot kit is available from http://www.SumoRobotLeague.com
********************************************************************/
//  Lesson 5.2, Solution 1, Musical Helper Function

/***************************************************
 * Functional Requirements
 *
 * 1. Develop a function that will take 3 arguments
 * play the note provided for the duration specified,
 * then pause for the time specified by the rest
 * duration argument.
 *
 * 2. Define an array format that will contain all
 * three of the required arguments.
 *
 * 3. Loop through this array to play a song.
 ***************************************************/

#include "Pitches.h"

#define buzzer 3

// Our musical notation array.
int notes[] = {
	// NOTE, DURATION, REST
	NOTE_C5, 250, 500,
	NOTE_C5, 250, 500,
	NOTE_G5, 250, 500,
	NOTE_G5, 250, 500,
	NOTE_A5, 250, 500,
	NOTE_A5, 250, 500,
	NOTE_G5, 500, 1000
};

void setup() {
	Serial.begin(9600);
	pinMode(buzzer, OUTPUT);

	int arrayLength = (sizeof(notes)/sizeof(int));
	int notesToPlay = arrayLength / 3;

	Serial.println("Starting musical robot!");
	Serial.print("Your notes array contains '");
	Serial.print(notesToPlay);
	Serial.println("' total notes.");
}

void loop() {
	int arrayLength = (sizeof(notes)/sizeof(int));

	// NOTE: We are adding 3 to the loop index so that
	// we can always skip to the next note.
	for ( int i = 0; i < arrayLength; i = i + 3) {
		playNote(notes[i], notes[i+1], notes[i+2]);
	}

	// Once we've finished playing our melody, pause
	// for a few seconds and repeat. :)

	delay(3000);
}

void playNote(int note, int duration, int rest) {
	tone(buzzer, note, duration);
	delay(rest);
}
/*********************************************************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'*******************************************************************************************************************/
