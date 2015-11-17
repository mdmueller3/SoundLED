/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef SoundLED_h
#define SoundLED_h

// // include types & constants of Wiring core API
// #include "WConstants.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// library interface description
class SoundLED
{
  // user-accessible
  public:
    SoundLED(void);
    void setupSoundLED();
    void soundLEDLoop(int analogInput);
    int setMode(char color[]);
    void printMode(void);
    void allow(char color[]);
    void disallow(char color[]);
    void printAllowList(void);
    void printDisallowList(void);


  // library-accessible
  private:
    void resetModes(void);
    void rainbow(void);
    void fire(void);
    int num_leds;
    int data_pin;
    int savedInput;
    int flicker;

    
};

#endif

