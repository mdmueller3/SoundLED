#include <SoundLED.h>

#include <FastLED.h>
#include <stdlib.h>


#define NUM_LEDS 50
#define DATA_PIN 6

//example write LED:
//leds[0] = CRGB::Blue;
//FastLED.show();

CRGB leds[NUM_LEDS];

SoundLED myTest = SoundLED(2);

void randomColorMedium(){
  int r = rand() % 256;
  int g = rand() % 256;
  int b = rand() % 256;

   for(int dot = 0; dot < NUM_LEDS; dot++){
     leds[dot].r = r;
     leds[dot].g = g;
     leds[dot].b = b;
     FastLED.show();
     FastLED.setBrightness(220);
   }

}

//void randomColorBright(){
//  int r = rand() % 256;
//  int g = rand() % 256;
//  int b = rand() % 256;
//
//   for(int dot = 0; dot < NUM_LEDS; dot++){
//     leds[dot].r = r;
//     leds[dot].g = g;
//     leds[dot].b = b;
//     FastLED.show();
//     FastLED.setBrightness(255);
//   }
//}

void randomColorDark(){
  for(int dot = 0; dot < NUM_LEDS; dot++){
       FastLED.setBrightness(150);
       FastLED.show();
   }
}  


int analogInput;
int savedRead;
int timer = 0;

void setup(){
  //FastLED
  pinMode(0, INPUT);
  Serial.begin(9600);
  myTest.printStuff();
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);

}

void loop() {
  Serial.write("yolo");
  if(timer > 3500){
    analogInput = analogRead(A0);
    
    if(savedRead == 0){ //if not set
      savedRead = analogInput;
    }
   
    if((analogInput + 20) < savedRead || (analogInput - 20) > savedRead){
      if(analogInput > 60 && analogInput < 120){
        randomColorDark();
      }
      else if(analogInput <= 60){
        randomColorDark();
      }
      else{
        randomColorBright();
      }
    }
    timer = 0;
  }
  else{
    timer++;
  }

}
