//
// Created by peter on 04-12-21.
//

#include <FastLED.h>

#include "Random.h"

void Random::run(unsigned long milliseconds) {
    LedGroup& leds = this->getLeds();

    for (unsigned idx = 0; idx < leds.getSize(); idx++) {
        if (random(32) >= 8) {
            leds.setColour(idx, CRGB::Black);
        } else {
            unsigned r = random(random(256));
            unsigned g = random(random(256));
            unsigned b = random(random(256));

            leds.setColour(idx, CRGB((r << 16) + (g << 8) + b));
        }
    }
}
