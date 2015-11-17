/*
  SoundLED -- Created by Michael Mueller
*/

// Include FastLED and SoundLED
#include <FastLED.h>
#include "SoundLED.h"

// ENTER INFO HERE

#define DATA_PIN 7  // Where the light data outputs to
#define NUM_LEDS 50 // The number of LEDs connected

// ---------------

// The custom colors currently enabled (only relevant with custom mode)
int red = 1;
int orange = 1;
int yellow = 1;
int green = 1;
int blue = 1;
int turquoise = 1;
int purple = 1;
int pink = 1;

// Set Up Modes Array
#define NUM_MODES 7
int modes[NUM_MODES];

/**
  Dark Mode means when no noise, lights are dark
  1 = On, 0 = Off
*/
int darkMode = 0;

// Defining the light array and input
CRGB leds[NUM_LEDS];
int savedInput;



/**
  Constructor for the SoundLED object
  Hoping that eventually the SoundLED class will be static
*/
SoundLED::SoundLED(void){
  // Value that will be changed every single time the loop is called
  savedInput = 0;
  // Set the LEDs (for FastLED)
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
}

/**
Put inside of the loop, and is called every time the arduino cycles
*/
void SoundLED::soundLEDLoop(int analogInput){
  int input = analogInput;

  // Check if input is different enough
  if((input - 40) < savedInput || (input + 40) > savedInput){
    // Check if darkmode on, if it is
    if(darkMode == 1 && input < 100){
      noLight();
    }
    // Else, set color based on theme
    else{
      if(modes[0] == 1 || modes[1] == 1){
        //Rainbow Up
        rainbow();
      }
      else if(modes[2] == 1){
        //Fire
        fire();
      }
      else if(modes[3] == 1){
        //Blues
        blues();
      }
      else if(modes[4] == 1){
        //Random Color
        random();
      }
      else if(modes[5] == 1){
        //All
        random(); //for now
      }
      else{
        //Custom
        random(); //for now
      }
    }
  }
}


/**
Called to set the mode to one of the following:
  Rainbow Up      [0]
  Rainbow Down    [1]
  Fire            [2]
  Violet & Blue   [3]
  Random Color    [4]
  Switch to all   [5]  
  Custom          [6]
*/
int SoundLED::setMode(char mode[]){
  // Reset modes to make sure no errors will occur
  resetModes();

  //Set the mode value to 1
  if(mode == "rainbow up"){
    modes[0] = 1;
    return 1;
  }
  else if(mode == "rainbow down"){
    modes[1] = 1;
    return 1;
  }
  else if(mode == "fire"){
    modes[2] = 1;
    return 1;
  }
  else if(mode == "blues"){
    modes[3] = 1;
    return 1;
  }
  else if(mode == "random"){
    modes[4] = 1;
    return 1;
  }
  else if(mode == "all"){
    modes[5] = 1;
    return 1;
  }
  else if(mode == "custom"){
    modes[6] = 1;
    return 1;
  }
  else{
    //Error
    modes[6] = 1;
    return - 1;
  }
}


/**
  Sets the dark mode (no lights when music off)
  1 = On
  0 = Off
*/
void SoundLED::setDarkMode(int answer){
  darkMode = answer;
}

/**
  Incomplete - Will print the current mode being used
  How do I print when I don't know which device they are using?
*/
void SoundLED::printMode(void){
  // do stuff later
}

/**
  Reset all of the modes to 0
  Basically assures that there will be no errors when setting a mode to 1
*/
void SoundLED::resetModes(void){
  for(int i = 0; i < NUM_MODES; i++){
    modes[i] = 0;
  }
}


/**
  Modifies the custom list of the colors
  Whatever color the user enters will be allowed
  Only relevant in custom mode
*/
void SoundLED::allow(char color[]){
  if(color == "red")
    red = 1;
  else if(color == "orange")
    orange = 1;
  else if(color == "yellow")
    yellow = 1;
  else if(color == "green")
    green = 1;
  else if(color == "blue")
    blue = 1;
  else if(color == "turquoise")
    turquoise = 1;
  else if(color == "purple")
    purple = 1;
  else if(color == "pink")
    pink = 1;
  else{
    //not being read
    Serial.print("Error reading input - allow(char color[])");
  }
}

/**
  Modifies the custom list of the colors
  Whatever color the user enters will be disallowed
  Only relevant in custom mode
*/
void SoundLED::disallow(char color[]){
  if(color == "red")
    red = 0;
  else if(color == "orange")
    orange = 0;
  else if(color == "yellow")
    yellow = 0;
  else if(color == "green")
    green = 0;
  else if(color == "blue")
    blue = 0;
  else if(color == "turquoise")
    turquoise = 0;
  else if(color == "purple")
    purple = 0;
  else if(color == "pink")
    pink = 0;
  else{
    //not being read
    Serial.print("Error reading input - disallow(char color[])");
  }
}

/**
  Private function that changes the color of the leds to a random color
*/
int rainbowNum = 0;

void SoundLED::rainbow(){
  switch(rainbowNum){
    case 0:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Red;
           FastLED.show();
      }
      break;
    case 1:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Orange;
           FastLED.show();
      }
      break;
    case 2:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Yellow;
           FastLED.show();
      }
      break;
    case 3:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Green;
           FastLED.show();
      }
      break;
    case 4:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Blue;
           FastLED.show();
      }
      break;
    case 5:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Violet;
           FastLED.show();
      }
      break;
    case 6:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Pink;
           FastLED.show();
      }
      break;
    default:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Red;
           FastLED.show();
      }
      rainbowNum = 0;
      break;
  }
  if(modes[0] == 1){
    if(rainbowNum == 6){
      rainbowNum = 0;
    }
    else{
      rainbowNum++;
    }
  }
  else{
    if(rainbowNum == 0){
      rainbowNum = 6;
    }
    else{
      rainbowNum--;
    }
  }
}

/**
  Private function that sets the color of the lights to a fire-looking color (could switch each indiividual light?)
*/
int fireNum = 0;

void SoundLED::fire(){
  bool notNew = true;
  int newNum = fireNum;
  while(notNew){
    newNum = rand() % 3;
    if(newNum != fireNum){
      fireNum = newNum;
      notNew = false;
    }
  }
  switch(fireNum){
    case 0:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Red;
           FastLED.show();
      }
      break;
    case 1:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Orange;
           FastLED.show();
      }
      break;
    case 2:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Yellow;
           FastLED.show();
      }
      break;
    default:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Red;
           FastLED.show();
      }
      break;
  }
}

/**
  Private function that sets the color of the lights to a blueish color
  Could access each individual light?
*/
void SoundLED::blues(){
  bool notNew = true;
  int newNum = fireNum;
  while(notNew){
    newNum = rand() % 3;
    if(newNum != fireNum){
      fireNum = newNum;
      notNew = false;
    }
  }
  switch(fireNum){
    case 0:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::AliceBlue;
           FastLED.show();
      }
      break;
    case 1:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Purple;
           FastLED.show();
      }
      break;
    case 2:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Violet;
           FastLED.show();
      }
      break;
    default:
      for(int dot = 0; dot < NUM_LEDS; dot++){
           leds[dot] = CRGB::Blue;
           FastLED.show();
      }
      break;
  }
}

/**
This changes the LED colors to a random color on the color spectrum
*/
void SoundLED::random(void){
  int r = rand() % 256;
  int g = rand() % 256;
  int b = rand() % 256;

   for(int dot = 0; dot < NUM_LEDS; dot++){
     leds[dot].r = r;
     leds[dot].g = g;
     leds[dot].b = b;
     FastLED.show();
   }
}

void SoundLED::noLight(void){
  for(int dot = 0; dot < NUM_LEDS; dot++){
     leds[dot] = CRGB::Black;
  }
}

