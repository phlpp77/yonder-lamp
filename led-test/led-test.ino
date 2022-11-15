#include <Adafruit_NeoPixel.h>

#define LED_PIN 6

#define LED_COUNT 12

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);
uint32_t magenta = strip.Color(255, 0, 255, 0);

void setup() {
  strip.begin();
  strip.setBrightness(10); // Setting brightness to 64 out of 255
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {

  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, 30, 180, 40, 20);
    strip.show();
    delay(1000);
  }
  strip.clear(); // Does not need a show
  strip.fill(magenta); // Fills the whole circle with magenta
  
}