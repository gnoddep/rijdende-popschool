//
// Created by peter on 30-11-21.
//

#include "Effect.h"

LedGroup& Effect::getLeds() {
    return this->leds;
}

void Effect::start(unsigned long milliseconds, unsigned long runtimeMilliseconds) {
    if (runtimeMilliseconds == 0) {
        this->startMilliseconds = 0;
        this->endMilliseconds = 0;
    } else {
        this->startMilliseconds = milliseconds;
        this->endMilliseconds = milliseconds + runtimeMilliseconds;
    }

    this->init();
}

bool Effect::shouldRun(unsigned long milliseconds) const {
    Serial.print(this->startMilliseconds);
    Serial.print(" >= ");
    Serial.print(milliseconds);
    Serial.print(" < ");
    Serial.println(this->endMilliseconds);

    return (this->startMilliseconds == 0 && this->endMilliseconds == 0)
        || (milliseconds >= this->startMilliseconds && milliseconds < this->endMilliseconds);
}

void Effect::init() {
    FastLED.setBrightness(32);
    this->clear();
}

void Effect::clear() {
    for (unsigned idx = 0; idx < this->leds.getSize(); idx++) {
        this->leds.setColour(idx, CRGB::Black);
    }
}
