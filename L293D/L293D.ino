/*

 In this sketch we control a motor using
 the popular L293D H-Bridge chip.

 Enter F or R, followed by a comma, then the speed (eg. F,200)

*/
   

// Arduino pins
#define ENABLE 11
#define MOTOR1 9
#define MOTOR2 6

// Start power on zero
int power = 0;         

// set things up ...
void setup() {

  // start the serial connection
  Serial.begin(9600);

  // declare both motor control pins to be output:
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);

  // enable pin is also output
  pinMode(ENABLE, OUTPUT);

}

// keep doing this forever:
void loop() {

  // play with the power setting to see
  // the effects
  while (Serial.available() > 0) {

    // F or R
    String direction = Serial.readStringUntil(',');
    direction.toUpperCase();

    // look for the next power number in the serial monitor
    // turn it into an integer and place in our power variable:
    int power = Serial.parseInt();
 
    // look for the newline
    if (Serial.read() == '\n') {

        // report back the number we were provided:
        Serial.print(power);
      
        // If we want to go forwards ...
        if(direction == "F") {
          
          // Makes #1 5v and #2 act like Ground
          digitalWrite(MOTOR1, HIGH);
          digitalWrite(MOTOR2, LOW);

          // set the speed via the Enable pin
          analogWrite(ENABLE, power);

        } 
        
        // Otherwise ...
        else 
        {

          // Makes #2 5v and #1 act like Ground
          digitalWrite(MOTOR1, LOW);
          digitalWrite(MOTOR2, HIGH);

          // again, set the speed via the Enable pin
          analogWrite(ENABLE, power);

        }

        
        // output text to say we got it
        Serial.println(" - Roger!");
    }
  }
}