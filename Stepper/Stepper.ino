// Default stepper library
#include <Stepper.h>

// change this to fit the number of steps per revolution
// for your motor
#define FULLREVOLUTION 4096 

// Motor pins
#define MOTOR1  3     // IN1 on the ULN2003 
#define MOTOR2  4     // IN2 on the ULN2003 
#define MOTOR3  5     // IN3 on the ULN2003 
#define MOTOR4  6     // IN4 on the ULN2003 

// initialize the stepper library
Stepper myStepper(FULLREVOLUTION, MOTOR1, MOTOR3, MOTOR2, MOTOR4);

void setup() { }

void loop() {
 
  
  for(int step = 0; step < FULLREVOLUTION; step++)
  {
 
    // step 
    myStepper.step(1);
    
    // delay
    delay(5);
  
  }

  // wait before 
  delay(1000);
}

