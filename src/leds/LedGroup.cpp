//
// Created by peter on 04-12-21.
//

#include "LedGroup.h"

CRGB *LedGroup::getLeds() const {
    return leds;
}

size_t LedGroup::getSize() const {
    return size;
}

void LedGroup::setColour(unsigned idx, CRGB colour) {
    this->leds[this->mapping ? this->mapping[idx] : idx] = colour;
}

void LedGroup::addColour(unsigned idx, CRGB colour) {
    this->leds[this->mapping ? this->mapping[idx] : idx] += colour;
}
