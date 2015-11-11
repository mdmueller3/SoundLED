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

#define DATA_PIN 7
#define NUM_LEDS 50

// ---------------


/**
Different options:
  One color flash (brighter or darker per flash?)
  Rainbow (red orange yellow green blue purple)
  Violet, Blue
  Random Color
  Switch amongst the above

  All with the option of flicker on or off
*/


SoundLED::SoundLED(void){
  // do whatever is required to initialize the library
  Serial.begin(9600);

  int savedInput = 0;
  int darkSilence = 0;

}

/**
Right now simply acting as a testing method to make sure all is working
Delete later
*/
void SoundLED::printStuff(void)
{
  // eventhough this function is public, it can access
  // and modify this library's private variables
  Serial.print(78);
}

/**
Activates (sets up) the led stuff
*/
void SoundLED::activate(){
  //create CRGB object
  CRGB leds[NUM_LEDS];

  //Add LEDSs
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);

}

/**
Put inside of the loop, and is called every time the arduino cycles
*/
void SoundLED::go(int analogInput){
  int input = analogInput;

  



}

/**
1: Red (brighten)
2: Red (darken)
3: Blue (brighten)
4: Blue (darken)
5: Green (brighten)
6: Green (darken)
7: Purple (brighten)
8: Purple (darken)
9: Turquoise (brighten)
10: Turquoise (darken)
11: Rainbow (R -> P)
12: Rainbow (P -> R)
13: Violet/Blue
14: Random Color
15: Yellow Sunshine
*/
void setColorScheme(int setting, int dark){
  darkSilence = dark;


}

/**
This will change the LED colors to a random color
In the future, this will either be replaced by either settings to personalize
the color change, or multiple random color settings (bright, med, dark)
*/
void SoundLED::randomColor(void){
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
}

