#include <SoundLED.h>

#include <FastLED.h>
#include <stdlib.h>

//example write LED:
//leds[0] = CRGB::Blue;
//FastLED.show();




SoundLED sound = SoundLED();


int analogInput;
int savedRead;

void setup(){
  //FastLED
  pinMode(0, INPUT);
  
  sound.setNumberOfLeds(0);
  sound.setDataPin(50);
 
//  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
  
}

void loop() {
  analogInput = analogRead(A0);
  sound.go(analogInput);
  if(savedRead == 0){ //if not set
    savedRead = analogInput;
  }

}
