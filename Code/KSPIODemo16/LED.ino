void initialize(Adafruit_NeoPixel strip) {
  strip.begin();
  strip.show();
}

void LEDsetup() {
  initialize(strip);
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

void dim(Adafruit_NeoPixel strip, uint32_t interval) {
  if (interval < 50) {
    strip.setBrightness(0);
  } else {
    uint32_t timeStep = interval / 50;
    float intensity = 1.0;
    uint8_t brightness = strip.getBrightness();
    for (int i = 0; i < 50; i++) {
      intensity -= .02;
      strip.setBrightness((uint8_t) brightness * intensity);
      strip.show();
      delay(timeStep);
    }
    strip.setBrightness(0);
  }
  strip.show();
}

