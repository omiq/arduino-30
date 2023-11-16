/*
  Arduino Magic 8
  
  Responses from Wikipedia:
  https://en.wikipedia.org/wiki/Magic_8-Ball

*/

// Set up the responses Array[] list
// BEFORE Setup, so all the 
// sketch has access (ie. global)
String responses[] = {
  
  "It is certain.",
  "It is decidedly so.",
  "Without a doubt.",
  "Yes - definitely.",
  "You may rely on it.",
  "As I see it, yes.",
  "Most likely.",
  "Outlook good.",
  "Yes.",
  "Signs point to yes.",
  "Reply hazy, try again.",
  "Ask again later.",
  "Better not tell you now.",
  "Cannot predict now.",
  "Concentrate and ask again.",
  "Don't count on it.",
  "My reply is no.",
  "My sources say no.",
  "Outlook not so good.",
  "Very doubtful."
  
  };


// As this loads just once,
// you will need to reset to get
// another answer!
void setup() {
  
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
  String selectedResponse = responses[random (0, 19)];

  // ... and display in serial monitor
  // \n is a new line so we can separate 
  // output more cleanly
  Serial.println("\n\n" + selectedResponse);

}

// No loop in this version
void loop() {}