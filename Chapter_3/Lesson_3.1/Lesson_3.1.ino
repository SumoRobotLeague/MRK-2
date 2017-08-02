//  Lesson 3.1

void setup() {
	Serial.begin(9600);
	
	int magicCounter = 0;
	for (int i = 0; i < 10; i++ ) {
		magicCounter = magicCounter + 1;
		Serial.println(magicCounter);
	}
}

void loop() {
}

