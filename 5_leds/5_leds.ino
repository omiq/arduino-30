/*

5 LEDs all at once

*/

// Let's define where the LEDs
// are plugging into so we can
// keep track
#define LED1 11
#define LED2 10
#define LED3 9
#define LED4 6
#define LED5 5


// Remember, Setup
// runs just once
void setup()
{
  
  // Now we need to set them
  // as output, because we are
  // outputting current to the
  // LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  // Start the serial
  Serial.begin(9600);

}

// Our loop will loop until
// power is removed
void loop()
{
  
  // set all the LEDs on
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  
  // tell the serial monitor
  Serial.println("All Leds On");
  delay(1000); // Wait for 1000 millisecond(s)

  // everybody off
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  
  // again, let the serial monitor know
  Serial.println("All Leds Off");
  delay(1000); // Wait for 1000 millisecond(s)
}