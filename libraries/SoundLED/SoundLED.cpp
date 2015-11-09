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

SoundLED::SoundLED(void)
{
  // do whatever is required to initialize the library
  Serial.begin(9600);
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
Sets the number of leds so SoundLED can properly send out data
*/
void SoundLED::setNumberOfLeds(int num){
  num_leds = num;
}


/**
Sets the data pin so that SoundLED knows where to send the value
*/
void SoundLED::setDataPin(int pin){
  data_pin = pin;
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

/**
Activates (sets up) the led stuff
*/
void SoundLED::activate(int pinOut){

  //must be constants (pinout, num_leds)
  // FastLED.addLeds<WS2811, pinOut>(leds, num_leds);

}

/**
Put inside of the loop, and is called every time the arduino cycles
*/
void SoundLED::go(int analogInput){}


