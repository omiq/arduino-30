// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int STEPS_PER_REV = 200;


Stepper stepper_NEMA17(STEPS_PER_REV, 3, 4, 5, 6);

void setup() {
  stepper_NEMA17.setSpeed(100);
  
}

void loop() {


  
  // step 1/100 of a revolution:
  stepper_NEMA17.step(1);

}