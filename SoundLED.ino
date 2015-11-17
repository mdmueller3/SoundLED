#include <SoundLED.h>

#include <FastLED.h>
#include <stdlib.h>

//example write LED:
//leds[0] = CRGB::Blue;
//FastLED.show();

SoundLED sound = SoundLED();

void setup(){
  //FastLED
  pinMode(0, INPUT);
  sound.setMode("rainbow up");
}

void loop() {
  int analogInput = analogRead(A0);
  sound.soundLEDLoop(analogInput);

}
