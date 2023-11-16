#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library
Stepper myStepper(stepsPerRevolution, 3, 4, 5, 6);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  Serial.begin(115200); // start serial
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  Serial.println(sensorReading);
  
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 769, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}


