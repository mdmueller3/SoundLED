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

#include "HardwareSerial.h"
#include "SoundLED.h"
#include "FastLED.h"
#include <stdlib.h>

// library interface description
class SoundLED
{
  // user-accessible
  public:
    SoundLED(void);
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
    void blues(void);
    void random(void);
    void noLight(void);
    void setDarkMode(int answer);

    int savedInput;
};

#endif

