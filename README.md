# SoundLED

Sound-Responsive LEDs controlled by an Arduino. Takes the difficulty out of programming LEDs so you can enjoy the light show!

There are two main ways to create sound-responsive LEDs. These are:
* Control the lights directly from your sound-source
* Control the lights with an external platform capable of "hearing" the music

While the first one would be nice to have, most of us don't have a sound-source capable of controlling LED lights. And while there are devices that both have GPIO pins and a chip capable of playing music, you are quickly adding complexity. So SoundLED aims to make the second one easy.

SoundLED as of now is only operational on the Arduino. Most Arduino boards should work (a full list will come soon)

**This repository is a work in progress**

# Connecting Your Device

The idea behind SoundLED is to have a microcontroller that is capable of inputting a range of voltages, as well as outputting a digital signal. For example, an Arduino board. 

First, let's connect the music source to the board. The easiest way to do this is to cut an AUX cord. Inside an AUX cord, there is a left-channel connection, a right-channel connection, and a ground connection. Follow these instructions:

1. Take either the right or left channel connections and connect them to an analog input in the board. It's not necessary at the moment to connect both, but 2-channel support will eventually be added.
2. Connect the ground connection to a ground connection in the Arduino.

Next, we will connect the Arduino to the LED set. Most LED strands will have 3 inputs: Power (usually 5v), Ground, and Data.

1. Connect the ground connection to a digital ground pin
2. Connect the data pin to a digital output pin on the board
3. Connect the power connection to the appropriate voltage (usually 5v). This is a separate process and won't be covered here (as of now).

You are officially connected! This is usually the hardest step, so if you've made it here, you are in good shape.

# How To Download

The first thing to do is to download the FastLED library, [found here.](https://github.com/FastLED/FastLED)

While SoundLED controls the sound-responsiveness of the program, controlling the LEDs is a whole nother monster. FastLED makes all of this easy. The FastLED library is a complex but very simple-to-use library and I highly recommend checking it out if you wish to do any custom LED control.

**TBD - Due to recent issues, SoundLED may not be functional for a couple of weeks. I apologize**
