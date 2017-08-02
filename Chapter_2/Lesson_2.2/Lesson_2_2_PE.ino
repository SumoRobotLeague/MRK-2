// initialize our global variables
int durationOn  = 1000;
int durationOff = 1000;

void setup() {
	// initialize digital pin 13 as an output
	pinMode(13, OUTPUT);
}

void loop() {
	digitalWrite(13, HIGH); // turn the LED on
	delay(durationOn);
	digitalWrite(13, LOW);  // turn the LED off
	delay(durationOff); 
}
