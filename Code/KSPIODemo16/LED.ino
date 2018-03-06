void initialize(Adafruit_NeoPixel strip) {
  strip.begin();
  strip.show();
}

void LEDsetup() {
  initialize(strip);
    for(uint16_t j = 0; j < numled; j++) {
    redStates[j] = 0;
    greenStates[j] = 0;
    blueStates[j] = 0;
  }
}

void ignitionSequence() {
        if(count == 2 && VData.CurrentStage/TSN == 1 && count2 != 1){
        colorChange(strip.Color(0,50,0));
        count = count+1;}
        else if(count == 4 && VData.CurrentStage/TSN == 1 && count2 != 1){
        colorChange(strip.Color(0,0,0));
        count = 0;}
        else if(VData.CurrentStage/TSN == 1)
        count = count+1;
        else if(VData.CurrentStage/TSN !=1 && count < 20 && count2 != 1){
        colorChange(strip.Color(0,50,0));  
        count = count+1;}
        else if(VData.CurrentStage/TSN !=1 && count > 19 && count2 != 1)
        count2 = 1;
}


void Stars() {
   if (random(2) == 1) {
      uint16_t i = random(numled);
      if (redStates[i] < 1 && greenStates[i] < 1 && blueStates[i] < 1) {
        redStates[i] = random(256);
        greenStates[i] = random(256);
        blueStates[i] = random(256);
      }
    }
    
    for(uint16_t j = 0; j < numled; j++) {
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
  
}









void colorChange(uint32_t c) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
}

















void colorBlink(uint32_t c, uint32_t delaytime) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(delaytime);
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
  strip.show();
  delay(delaytime);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void colorDim(uint32_t wait) {
  for(uint16_t i=strip.getBrightness(); i>0; i--) {
    strip.setBrightness(i);
    strip.show();
    delay(wait/256);
  }
}

void colorUndim(uint32_t wait) {
  for(uint16_t i=strip.getBrightness()+1; i<255; i++) {
    strip.setBrightness(i+1);
    strip.show();
    delay(wait/256);
  }
}
<<<<<<< HEAD

void dim(Adafruit_NeoPixel strip, uint32_t interval) {
  uint32_t timestep = interval / 15;
  for (int i = 0; i < 15; i++) {
    double intensity = pow(0.75, (float) i);
    uint8_t brightness = strip.getBrightness();
    strip.setBrightness((uint8_t) brightness * intensity);
    strip.show();
    delay(timestep);
  }
  strip.setBrightness(0);
}

=======
s
>>>>>>> 7695b3341222e2ae7c254b8e5970461d188dd308
