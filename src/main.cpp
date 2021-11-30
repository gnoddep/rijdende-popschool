#include <Arduino.h>
#include <ESP8266WiFi.h>

#include <FastLED.h>

#include "effects/FadeInAndOut.h"

#define NUM_LEDS 10

#define DATA_PIN 4
#define CLOCK_PIN 5

CRGB leds[NUM_LEDS];

FadeInAndOut fadeInAndOut = FadeInAndOut(leds, NUM_LEDS);

void setup() {
    Serial.begin(74880);

    WiFi.mode(WIFI_OFF);
    WiFi.forceSleepBegin();

    delay(500);

    CFastLED::addLeds<LPD8806, DATA_PIN, CLOCK_PIN, BRG>(leds, NUM_LEDS);

    FastLED.clear();
    FastLED.show();

    delay(250);

    FastLED.setBrightness(0);

    leds[0] = CRGB::Red;
    leds[1] = CRGB::Green;
    leds[2] = CRGB::Blue;
    leds[3] = CRGB::White;

    FastLED.show();
}

void loop() {
    fadeInAndOut.run(millis());
    delay(50);
}