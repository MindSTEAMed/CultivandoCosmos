/*
  NeoPixel LEDs
 
  modified on 7 jun 2022
  by RafaHelium @ LRGV (github)

  modified on 7 May 2019
  by Saeed Hosseini @ Electropeak
**This code is based on Adafruit NeoPixel library Example**
  https://electropeak.com/learn/

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN      05
#define NUMPIXELS 16


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels




void setup() {
  // STATIC RANDOM FADE BLYNK LIGTH
  pixels.begin();

  //BLYNK LIGTH
  //pixels.setBrightness(50);

}


void loop() {

  // STATIC LIGTH
  //pixels.clear();
  //pixels.setBrightness(10);
  //pixels.setPixelColor(0, pixels.Color(255, 255, 255));
  //pixels.setPixelColor(1, pixels.Color(255, 0, 0));
  //pixels.setPixelColor(2, pixels.Color(0, 255, 0));
  //pixels.setPixelColor(3, pixels.Color(0, 0, 255));
  //pixels.setPixelColor(4, pixels.Color(255, 0, 255));
  //pixels.setPixelColor(5, pixels.Color(255, 255, 0));
  //pixels.setPixelColor(6, pixels.Color(0, 255, 255));
  //pixels.setPixelColor(7, pixels.Color(255, 255, 255));
  //pixels.setPixelColor(8, pixels.Color(255, 0, 0));
  //pixels.setPixelColor(9, pixels.Color(0, 255, 0));
  //pixels.setPixelColor(10, pixels.Color(0, 0, 255));
  //pixels.setPixelColor(11, pixels.Color(255, 0, 255));
  //pixels.setPixelColor(12, pixels.Color(255, 255, 0));
  //pixels.setPixelColor(13, pixels.Color(0, 255, 255));
  //pixels.setPixelColor(14, pixels.Color(255, 0, 255));
  //pixels.setPixelColor(15, pixels.Color(255, 255, 0));
  //pixels.show();

  //BLYNK LIGTH
  //NeoBlink(NUMPIXELS, 500);

  //FADE LIGTH
  //NeoFade(100);

  //RANDOM LIGTH
  pixels.clear();
  pixels.setPixelColor(random(0, NUMPIXELS), random(0, 255), random(0, 255), random(0, 255));
  pixels.show();
  delay(500);

}


//BLYNK LIGTH
//void NeoBlink(int num, int wait)
//{
//  for (int i = 0; i < num; i++)
//    {
//      pixels.setPixelColor(i, 35, 35, 35);
//    }
//  pixels.show();
//  delay(wait);
//  for (int j = 0; j < num; j++)
//    {
//      pixels.setPixelColor(j, 0, 255, 0);
//    }
//  pixels.show();
//  delay(wait);
//}

//FADE LIGTH
//void NeoFade(int FadeSpeed)
//{
//  int fspeed;
//  for (int i = 0; i < NUMPIXELS; i++) { pixels.setPixelColor(i, 255, 100, 126); } for (int j = 255; j > 0; j=j-2)
//  {
//    pixels.setBrightness(j);
//    pixels.show();
//    delay(FadeSpeed);
//  }
//}
