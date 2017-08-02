
void setup() {
	Serial.begin(9600);

	Serial.println( msToCm(5000) );
	Serial.println( msToCm(10000) );
	
	//In sumo competition the ms values such as the 5000 and 10000 above will come from
	//the ultrasonic sensor which is used to time in microseconds how long the ultrasound
	//travels from the sensor to an object and back to the sensor.
}

void loop() {
}

long msToCm(long microseconds) {
	// returns the centimeters a soundwave travels at sea level 
	// after bouncing off an object and returning to the 
	// point of origin
	return microseconds / 29 / 2;
}
