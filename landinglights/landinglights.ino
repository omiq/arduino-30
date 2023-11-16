

int LEDs[] = {A0,A1,A2,A3,A4,3,5,6,9,10,11,13};
int LEDCount = 12;
int DelayTime = 50;
int step = 0;
int MaxSteps = 10;

int LED1Value = 0;
int LED1Direction = 10;

int LED2Value = 255;
int LED2Direction = -10;

int LED3Value = HIGH;
int Ticks3 = 0;

int LED4Value = LOW;
int Ticks4 = 50;

int LED5Value = 0;

void BootSequence() {
  
  for (int thisPin = 0; thisPin < LEDCount; thisPin++) {

    digitalWrite(thisPin, LOW);
    delay(DelayTime);  
  }
  
  
  for (int iteration = 0; iteration < 10; iteration++) {
  
    for (int thisPin = 0; thisPin < LEDCount; thisPin++) {
  
      digitalWrite(LEDs[thisPin], HIGH);
      delay(DelayTime);  
    }
  
    for (int thisPin = 0; thisPin < LEDCount; thisPin++) {
  
      digitalWrite(LEDs[thisPin], LOW);
      delay(DelayTime);  
    }
  }
}


void setup() {

  for (int thisPin = 0; thisPin < LEDCount; thisPin++) {

    pinMode(LEDs[thisPin], OUTPUT);
    digitalWrite(LEDs[thisPin], HIGH);
    delay(DelayTime);  
  }

  // Initial test lights
  BootSequence();
  

}


int FadeInOut(int &LEDValue, int &LEDDirection)
{
  
  if(LEDValue >= 250 && LEDDirection == 10)
  {
    LEDDirection = -10;
  LEDValue += LEDDirection;
  
  }
  else if(LEDValue == 0 && LEDDirection == -10)
  {
    LEDDirection = 10;
    LEDValue += LEDDirection;
  
  }
  else
  {
    LEDValue += LEDDirection;
  }

  return LEDValue;
}


int Blink(int &LEDValue, int &Ticks)
{
  
  Ticks++;
  
  if(Ticks > 100)
  {
    Ticks = 0;
  }
  
  if(Ticks > 50)
  {
    LEDValue = LOW;
  }
  else
  {
    LEDValue = HIGH;
  }
  
  return LEDValue;

}


int Flicker()
{
  
  randomSeed(analogRead(A5)); 
  
  int pickedNum = random (100);

  return pickedNum % 3;

}

void loop() {

  analogWrite(3,random(255));   
  analogWrite(5,FadeInOut(LED1Value,LED1Direction));   
  analogWrite(6, FadeInOut(LED2Value,LED2Direction));   

  digitalWrite(A0, Blink(LED3Value, Ticks3));     
  digitalWrite(A1, Blink(LED4Value, Ticks4));   
  digitalWrite(A2, Flicker());   
  digitalWrite(A3, Flicker());   
  digitalWrite(A4, Flicker());   
  
  analogWrite(9, random(255));   
  analogWrite(10,random(255));   
  analogWrite(11,random(255));   
  analogWrite(13,random(255));   
  
  delay(DelayTime);                       


}