//  Lesson 2.3, Exercise 2

void setup() {
	Serial.begin(9600);

	Serial.print("5000 microseconds distance in inches is: ");
	Serial.println( msToInches(5000) );
}

void loop() {
}

//function to convert microseconds in long format, which is similar to int but allows for bigger numbers,
//into inches using the speed of sound in inches per microsecond (74) and that the sound travels the 
//distance twice (2)
long msToInches(long microseconds) {
	return microseconds / 74 / 2;
}

