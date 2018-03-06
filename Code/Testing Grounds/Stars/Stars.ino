#include <Adafruit_NeoPixel.h>

#define PIN 6
#define Pixels 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(Pixels, PIN, NEO_GRBW + NEO_KHZ800);

float redStates[Pixels];
float blueStates[Pixels];
float greenStates[Pixels];
float fadeRate = 0.96;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  for(uint16_t j = 0; j < Pixels; j++) {
    redStates[j] = 0;
    greenStates[j] = 0;
    blueStates[j] = 0;
  }
}

void loop () {
   if (random(2) == 1) {
      uint16_t i = random(Pixels);
      if (redStates[i] < 1 && greenStates[i] < 1 && blueStates[i] < 1) {
        redStates[i] = random(256);
        greenStates[i] = random(256);
        blueStates[i] = random(256);
      }
    }
    
    for(uint16_t j = 0; j < Pixels; j++) {
      if (redStates[j] > 1 || greenStates[j] > 1 || blueStates[j] > 1) {
        strip.setPixelColor(j, redStates[j], greenStates[j], blueStates[j]);
        
        if (redStates[j] > 1) {
          redStates[j] = redStates[j] * fadeRate;
        } else {
          redStates[j] = 0;
        }
        
        if (greenStates[j] > 1) {
          greenStates[j] = greenStates[j] * fadeRate;
        } else {
          greenStates[j] = 0;
        }
        
        if (blueStates[j] > 1) {
          blueStates[j] = blueStates[j] * fadeRate;
        } else {
          blueStates[j] = 0;
        }
        
      } else {
        strip.setPixelColor(j, 0, 0, 0);
      }
    }
    strip.show();
    //delay(0);
  
}
