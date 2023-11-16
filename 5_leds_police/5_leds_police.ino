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
  
  // set all the LEDs on ...
  // but to different brightness
  analogWrite(LED1, 50);
  analogWrite(LED2, 100);
  analogWrite(LED3, 255);
  analogWrite(LED4, 0);
  analogWrite(LED5, 0);
  
  // tell the serial monitor
  Serial.println("11100");
  delay(1000); // Wait for 1000 millisecond(s)

  // everybody off
  analogWrite(LED1, LOW);
  analogWrite(LED2, LOW);
  analogWrite(LED3, LOW);
  analogWrite(LED4, 255);
  analogWrite(LED5, 100);
  
  // again, let the serial monitor know
  Serial.println("00011");
  delay(1000); // Wait for 1000 millisecond(s)
}