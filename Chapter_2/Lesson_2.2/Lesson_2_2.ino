

// initialize our global variables
int delayMs = 1000; // delay time in milliseconds

void setup() {
	// initialize digital pin 13 as an output
	pinMode(13, OUTPUT);
}

void loop() {
	digitalWrite(13, HIGH); // turn the LED on
	delay(delayMs);
	digitalWrite(13, LOW);  // turn the LED off
	delay(delayMs); 
}

