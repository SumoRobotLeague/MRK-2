//  Lesson 3.3 - Using If Blocks

void setup() {
  Serial.begin(9600);

  int your_age = 23;

  // check the permissions using the integer variable "age" defined above
  // Try changing the age and seeing what happens at different ages.
  checkPermissions_if(your_age);
}

void loop() {
}

//As written checkPermissions_if() prints a response ONLY if the age matches one of the 4 categories
//Try changing the == to <, >, <=, >=, or != 
void checkPermissions_if(int age) {
  if ( age == 15 ) {
    Serial.println("learner's permit");
  }
  if ( age == 16 ) {
    Serial.println("driver's license");
  }
  if ( age == 18 ) {
    Serial.println("lottery tickets");
  }
  if ( age == 25 ) {
    Serial.println("insurance discount");
  }
}
