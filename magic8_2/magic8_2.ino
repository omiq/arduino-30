/*
  Arduino Magic 8
  
  Responses from Wikipedia:
  https://en.wikipedia.org/wiki/Magic_8-Ball
  
  NOW WITH LIGHTS!?

*/

// I am using an RGB LED
// but you could switch to
// Red, Yellow, and Green LEDs
#define LED1 10
#define LED2 6
#define LED3 9

// Set up the responses Array[] list
// BEFORE Setup, so all the 
// sketch has access (ie. global)
//
// NOTE: It is now 2 dimensional
// First is rows, then columns
String responses[][2] = {
  
  {"2","It is certain."},
  {"2","It is decidedly so."},
  {"2","Without a doubt."},
  {"2","Yes - definitely."},
  {"2","You may rely on it."},
  {"2","As I see it, yes."},
  {"2","Most likely."},
  {"2","Outlook good."},
  {"2","Yes."},
  {"2","Signs point to yes."},
  {"1","Reply hazy, try again."},
  {"1","Ask again later."},
  {"1","Better not tell you now."},
  {"1","Cannot predict now."},
  {"1","Concentrate and ask again."},
  {"0","Don't count on it."},
  {"0","My reply is no."},
  {"0","My sources say no."},
  {"0","Outlook not so good."},
  {"0","Very doubtful."}
  
  };


// As this loads just once,
// you will need to reset to get
// another answer!
void setup() {
  
  // LED outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  // We don't need fast for this
  Serial.begin(9600);

  Serial.println();
  Serial.println("-------------------");
  Serial.println("Welcome adventurer!");
  Serial.println("-------------------");

  // Now we pick a random response
  // we need to seed the randomizer
  // otherwise we get the same answers
  randomSeed(analogRead(0)); 
  
  int pickedNum = random (0, 19);

  String selectedPositivity = responses[pickedNum][0];
  String selectedResponse = responses[pickedNum][1];

  // ... and display in serial monitor
  // \n is a new line so we can separate 
  // output more cleanly
  Serial.println("\n" + selectedResponse);
  Serial.println("\n" + selectedPositivity);
  
  // Now we work out which light/color
  // should be lit up 
  if(selectedPositivity == "2") { 
    // show green for go
    analogWrite(LED1, 0);
    analogWrite(LED2, 255);
    analogWrite(LED3, 0);
    
  } else if(selectedPositivity == "1") {
    // show amber
    analogWrite(LED1, 255);
    analogWrite(LED2, 255);
    analogWrite(LED3, 0);
    
  } else {
    // otherwise show red
    analogWrite(LED1, 255);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
  }


}

// No loop in this version
void loop() {}