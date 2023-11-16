//button
int buttonPin = 1;
int buttonstate = HIGH;
//timer
unsigned long fireTimer = 0;                    // use to compare 
int countdownTime = 5000;                       //time in ms to do the things
unsigned long counter = 0;                      //to count off of 
//bolterFront
const int bolterPinF =  4;                      // the number of the LED front pin
int bolterFState = LOW;                         // ledState used to set the LED
unsigned long bolterFMillis = 0;                // will store last time LED was updated
const long bolterFGunInterval = 70;             // interval at which to fire (milliseconds)
//bolterL
const int bolterPinL =  2;                      // the number of the LED left pin
int bolterLState = LOW;                         // ledState used to set the LED
unsigned long bolterLMillis = 0;                // will store last time LED was updated
const long bolterLGunInterval = 70;             // interval at which to fire (milliseconds)
//bolterR
const int bolterPinR =  3;                      // the number of the LED left pin
int bolterRState = LOW;                         // ledState used to set the LED
unsigned long bolterRMillis = 0;                // will store last time LED was updated
const long bolterRGunInterval = 70;             // interval at which to fire (milliseconds)
//mainGun
const int mainGunPin =  0;		                // the number of the LED main gun pin
int mainGunState = LOW;                         // ledState used to set the LED needs to be pwm
unsigned long mainGunMillis = 0;                // will store last time LED was updated                                   
int holdState = 0;                              // time maingun is on full divide by  mainGunInterval to works out to ms                                      
                                                                                                                                                            
void setup(){
 
    pinMode(bolterPinR, OUTPUT);
    pinMode(bolterPinL, OUTPUT);
    pinMode(bolterPinF, OUTPUT);
    pinMode(mainGunPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    
}

void loop(){
    buttonstate = digitalRead(buttonPin); //check button state 
    //if button press fire()
if (buttonstate == LOW) {
    fire();
    } 
 
}


void fire(){
    fireTimer = millis();
    counter = millis() + countdownTime; 
    unsigned long first = countdownTime * .25 + millis();
    unsigned long second = countdownTime * .5 + millis();
    unsigned long third = countdownTime * .75 + millis();
    unsigned long fourth = countdownTime + millis();
 
  while (fireTimer <= first){
        fireTimer = millis();
        bolterR();
        bolterF();
      	mainGun();
     }
        OFF();
        holdState = 400;
  while (fireTimer <= second){
        fireTimer = millis();
        bolterL();
        bolterR();
        mainGun();
    }
        OFF();
  while (fireTimer <= third){
        fireTimer = millis();
        bolterL();
        bolterF();
        bolterR();
        mainGun();
    }
        OFF();
    holdState = 400;
  while (fireTimer <= fourth){
        fireTimer = millis();
        bolterF();
        bolterL();
      	mainGun();
    }
        OFF();
} 
void OFF(){
digitalWrite(bolterPinF, LOW);
digitalWrite(bolterPinR, LOW);
digitalWrite(bolterPinL, LOW);
digitalWrite(mainGunPin, 0);

}

void mainGun(){    
    if (holdState > 0){
        holdState --;                           //Led will be on as the hold sate counts down
        mainGunState = HIGH;                     
    }
    else{                               
        mainGunState = LOW;                                            
    }  
    digitalWrite(mainGunPin, mainGunState);
}

void bolterL(){
    unsigned long currentMillis = millis();
if (currentMillis - bolterLMillis >= bolterLGunInterval) {   // save the last time you blinked the LED  
    bolterLMillis = currentMillis;
    if (bolterLState == LOW) {
      bolterLState = HIGH;      
    } 
    else {
      bolterLState = LOW;
      
    }
    digitalWrite(bolterPinL, bolterLState);
    }
}
void bolterR(){
    unsigned long currentMillis = millis();
if (currentMillis - bolterRMillis >= bolterRGunInterval) {   // save the last time you blinked the LED 
    bolterRMillis = currentMillis;
    if (bolterRState == LOW) {
      bolterRState = HIGH;     
    } 
    else {
      bolterRState = LOW;
      
    }
    digitalWrite(bolterPinR, bolterRState);
    }
}

void bolterF(){
    unsigned long currentMillis = millis();
if (currentMillis - bolterFMillis >= bolterRGunInterval) {   // save the last time you blinked the LED 
    bolterFMillis = currentMillis;
    if (bolterFState == LOW) {
      bolterFState = HIGH;     
    } 
    else {
      bolterFState = LOW;
    }
    digitalWrite(bolterPinF, bolterFState);
    }
}






