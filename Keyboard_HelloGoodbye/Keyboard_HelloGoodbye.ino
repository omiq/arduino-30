/********************************************
  USB Keyboard Hello World, Goodbye Zoom!
  MakerHacks.com 12/2020
*********************************************/

// The library that does the magicx
#include "Keyboard.h"

// Right now our "keyboard" has one key
#define KEY_PIN 2

// If we select another pin, we can have another function
#define ZOOM_PIN 3


void setup()
{

  // First we need our input pin
  // We use the built-in pullup
  // that means when it is connected to ground
  // we know the key has been pressed
  pinMode(KEY_PIN, INPUT_PULLUP);

  // Our secondary input ...
  pinMode(ZOOM_PIN, INPUT_PULLUP);

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
  // Check if the Zoom key has pressed
  else if (KeyPressed(ZOOM_PIN))
  {
    // Do our ZOOM macro
    pull_the_pin();
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


// Let's make a macro that quits out of zoom.
// I use a mac for work so I need Command(⌘)+W
// in this library we need to use KEY_LEFT_GUI
// (which is the Apple/Windows key)
// We get the combo from
// https://support.zoom.us/hc/en-us/articles/205683899-hot-keys-and-keyboard-for-zoom
void pull_the_pin()
{

  // Keyboard.press() all the required keys
  // 🍏+w
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  delay(100);
  Keyboard.releaseAll();

  // Now if we initiated, we can end for all (just hit Return)
  // or do we want to quit for us? (Tab then Enter)
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(100);
}
