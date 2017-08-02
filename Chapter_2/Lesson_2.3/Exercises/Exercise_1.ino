//  Lesson 2.3, Exercise 1


void setup() {
  Serial.begin(9600);
  
  Serial.print("9 * 13 = ");  //print without starting a new line
  Serial.println( multiply(9, 13) ); //print then start a new line
}

void loop() {
}


//a function to multiply to integer values
int multiply(int A, int B) {
  return A * B;
}
