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

