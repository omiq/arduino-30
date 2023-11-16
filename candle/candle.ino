/*
  Arduino Flickering Candle
*/

// RGB LED pins
#define LED1 10
#define LED2 6
#define LED3 9

// Setup variables
void setup() {
  
  // we need to seed the randomizer
  // otherwise we get the same results
  randomSeed(analogRead(0));
  
  // LED outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop() {
  
  // Red and Green brightness 
  int red = random (150, 255);
  int green = random (100, 255);
 
  // apply the values to the LED
  analogWrite(LED1, red);
  analogWrite(LED2, green);
  
  // we just need warm colors
  // but for different uses
  // you might want blue
  analogWrite(LED3, 0);
  
  // random delay
  delay(random (0, 100));

  // random off duration
  analogWrite(LED1, 0);
  analogWrite(LED2, 0);
  delay(random (0, 50));

  
}