// Setup of NeoPixel LEDs
#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 12
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);
uint32_t magenta = strip.Color(120, 0, 120, 0);

// Setup of ultrasonic sensor
const int trigPin = 5;
const int echoPin = 18;
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200);      // Starts the serial communication
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input

  strip.begin();
  strip.setBrightness(10); // Setting brightness to 64 out of 255
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_SPEED / 2;

  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;

  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);

  int distanceInt = (int)distanceCm;

  switch (distanceInt) {
    case 1 ... 20:
      Serial.print("Within 20cm");
      for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 30, 180, 40, 20);
    strip.show();
    delay(10);
  }
      break;
    case 21 ... 50:
      Serial.print("Within 50cm");
      for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, 30, 180, 40, 20);
    strip.show();
    delay(10);
  }
      break;
    default:
      Serial.print("Over 50cm");
      for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, 30, 180, 40, 20);
    strip.show();
    delay(10);
  }
  }

  delay(1000);
  strip.fill(magenta);
}