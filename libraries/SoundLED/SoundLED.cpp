/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// // include core Wiring API
// #include "WProgram.h"

#include <Arduino.h>
#include <FastLED.h>

// include this library's description file
#include "SoundLED.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

SoundLED::SoundLED(int givenValue)
{
  // do whatever is required to initialize the library
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void SoundLED::printStuff(void)
{
  // eventhough this function is public, it can access
  // and modify this library's private variables
  Serial.print(78);
}

void SoundLED::setNumberOfLeds(int num){
  num_leds = num;
}

void SoundLED::setDataPin(int pin){
  data_pin = pin;
}

void SoundLED::randomColorBright(void){
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

void SoundLED::randomColorMedium(void){}

void SoundLED::randomColorDark(void){}

void SoundLED::activate(int pinOut){

  //must be constants (pinout, num_leds)
  // FastLED.addLeds<WS2811, pinOut>(leds, num_leds);

}

void SoundLED::go(int analogInput){}


