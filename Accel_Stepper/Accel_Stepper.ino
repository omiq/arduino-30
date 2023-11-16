// Accelstepper library
#include <AccelStepper.h>

//Half-step mode 
#define HALFSTEP 8   

// change this to fit the number of steps per revolution
// for your motor
#define FULLREVOLUTION 4096  

// Motor pins 
#define MOTOR1  3     // IN1 on the ULN2003 
#define MOTOR2  4     // IN2 on the ULN2003 
#define MOTOR3  5     // IN3 on the ULN2003 
#define MOTOR4  6     // IN4 on the ULN2003 

// initialize the stepper library
AccelStepper myStepper(HALFSTEP, MOTOR1, MOTOR3, MOTOR2, MOTOR4);
 
void setup() {
  
  // Set the max speed
  myStepper.setMaxSpeed(1000.0);
  
  // Set the acceleration
  myStepper.setAcceleration(100.0);  //Make the acc quick
  
  // Set the speed between 0 to max
  myStepper.setSpeed(1000);
  
  // Do a full revolution
  myStepper.moveTo(FULLREVOLUTION);  
}
 
void loop() {
 
  //Change direction when the stepper reaches the target position
  if (myStepper.distanceToGo() == 0) {
    
    //Reverse the stepper motor
    myStepper.moveTo(-myStepper.currentPosition());  
  }
  
  //Start turning
  myStepper.run();  
}