
void setup() {
	Serial.begin(9600);  // setup USB communication
						 //   then to troubleshoot your code use Serial.println("t");
						 
	pinMode(13, OUTPUT); // initialize digital pin 13 as an output
}

void loop() {
	blink(1000);
	blink(500);
	blink(1500);
	blink(250);
}

void blink(int delayMs) {
	digitalWrite(13, HIGH); // turn the LED on
	delay(delayMs);
	digitalWrite(13, LOW);  // turn the LED off
	delay(delayMs);
}
