// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int STEPS_PER_REV = 200;




Stepper stepper_NEMA17(STEPS_PER_REV, 2, 3, 4, 5);

void setup() {
  stepper_NEMA17.setSpeed(100);
  
}

void loop() {


  for(int steps=0; steps < STEPS_PER_REV; steps++) {
    stepper_NEMA17.step(1);
  }

  delay(2000);
  
   for(int steps=0; steps <STEPS_PER_REV; steps++) {
    stepper_NEMA17.step(-1);
  }

  delay(2000);


}