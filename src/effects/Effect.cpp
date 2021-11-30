//
// Created by peter on 30-11-21.
//

#include "Effect.h"

Effect::Effect(CRGB *leds, unsigned int ledCount) {
    this->leds = leds;
    this->ledCount = ledCount;
}
