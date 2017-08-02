//  Lesson 5.2, Musical Programming

#include "Pitches.h"

#define buzzer 3

void setup() {
	Serial.begin(9600);

	pinMode(buzzer, OUTPUT);
}

void loop() {
	// Let's play the first part of "Twinkle Twinkle Little Star"
	tone(buzzer, NOTE_C5, 250);
	delay(500);
	tone(buzzer, NOTE_C5, 250);
	delay(500);
	tone(buzzer, NOTE_G5, 250);
	delay(500);
	tone(buzzer, NOTE_G5, 250);
	delay(500);
	tone(buzzer, NOTE_A5, 250);
	delay(500);
	tone(buzzer, NOTE_A5, 250);
	delay(500);
	tone(buzzer, NOTE_G5, 500);
}
