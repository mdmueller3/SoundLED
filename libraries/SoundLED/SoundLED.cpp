/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// // include core Wiring API
// #include "WProgram.h"

#include <Arduino.h>
#include <FastLED.h>
#include <stdlib.h>

// include this library's description file
#include "SoundLED.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"

  

// ENTER INFO HERE

#define INPUT_PIN 6
#define DATA_PIN 7
#define NUM_LEDS 50

// ---------------



int savedInput = 0;

//color scheme stuff
int darkSilence = 0;

int red = 1;
int orange = 1;
int yellow = 1;
int green = 1;
int blue = 1;
int turquoise = 1;
int purple = 1;
int pink = 1;


//modes
#define NUM_MODES 7
int modes[NUM_MODES];



CRGB leds[NUM_LEDS];

SoundLED::SoundLED(void){
  // do whatever is required to initialize the library
  Serial.begin(9600);
}

/**
Activates (sets up) the led stuff
*/
void SoundLED::setupSoundLED(){
  //create CRGB object

  //Add LEDSs
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);

}

/**
Put inside of the loop, and is called every time the arduino cycles
*/

//data
void SoundLED::soundLEDLoop(int analogInput){
  int input = analogInput;

  if((input - 40) < savedInput || (input + 40) > savedInput){
    //check for mode
    if(modes[0] == 1){
      //Rainbow Up
      rainbow();
    }
    else if(modes[1] == 1){
      //Rainbow Down
      rainbow();
    }
    else if(modes[2] == 1){
      //Fire
      fire();
    }
    else if(modes[3] == 1){
      //Blues
    }
    else if(modes[4] == 1){
      //Random Color
    }
    else if(modes[5] == 1){
      //All
    }
    else{
      //Custom
    }
  }

}


/**
Available modes:
  Rainbow(up and down)
  Fire
  Violet & Blue
  Random Color
  Switch all based on 30 second intervals
  Custom
*/

/**
Array Positions:
  [0] = rainbow up

*/
int SoundLED::setMode(char mode[]){
  resetModes();
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

void printMode(void){
  // do stuff later
}


void resetModes(void){
  for(int i = 0; i < NUM_MODES; i++){
    modes[i] = 0;
  }
}


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
This will change the LED colors to a random color
In the future, this will either be replaced by either settings to personalize
the color change, or multiple random color settings (bright, med, dark)
*/
// void SoundLED::randomColor(void){
  // int r = rand() % 256;
  // int g = rand() % 256;
  // int b = rand() % 256;

  //  for(int dot = 0; dot < NUM_LEDS; dot++){
  //    leds[dot].r = r;
  //    leds[dot].g = g;
  //    leds[dot].b = b;
  //    FastLED.show();
  //    FastLED.setBrightness(255);
  //  }
// }

