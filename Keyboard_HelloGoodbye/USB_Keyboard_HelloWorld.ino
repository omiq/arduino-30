/********************************************
  USB Keyboard Hello World
  MakerHacks.com 12/2020
*********************************************/

// The library that does the magicx
#include "Keyboard.h"

// Right now our "keyboard" has one key
#define KEY_PIN 2


void setup()
{

  // First we need our input pin
  // We use the built-in pullup
  // that means when it is connected to ground
  // we know the key has been pressed
  pinMode(KEY_PIN, INPUT_PULLUP);

  // Start watching the "keyboard"
  Keyboard.begin();
}

void loop()
{

  // We need to check the pin for Ground
  if (KeyPressed(KEY_PIN))
  {
    // Do our Hello macro
    do_the_thing();
  }
  else
  {
    // We wait, do nothing
    delay(100);
  }

}

// This is our Hello World macro
// We have various options for key-sending
void do_the_thing()
{

  // .write is like pressing and releasing
  // capitals are handled automagically
  Keyboard.write('H');
  delay(100);
  Keyboard.write('e');
  delay(100);
  Keyboard.write('l');
  delay(100);
  Keyboard.write('l');
  delay(100);
  Keyboard.write('o');
  delay(100);

  // Rather than send each keypress individually, we can send whole strings
  Keyboard.print("Hello World!");

  // You can also send "modifiers" and special keys, eg. hit return
  // https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
  // For multiple key presses we will use several Keyboard.press() calls
  Keyboard.write(KEY_RETURN);

  // Just in case any keys are "down"
  Keyboard.releaseAll();
  delay(100);
}

// This will be our function that returns if a key was pressed HelloHello World!
bool KeyPressed(int the_pin)
{
  if (digitalRead(the_pin) == LOW)
  {
    return true;
  }
  else
  {
    return false;
  }
}

