//  Chapter 1, Lesson 3 Exercises

void setup() {
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
}

void loop() {
	digitalWrite(13, HIGH); // turn the LED on.
	delay(1000);           // wait for a second.
	digitalWrite(13, LOW);  // turn the LED off.
	delay(1000);           // wait for a second.
}
