//
// Created by peter on 30-11-21.
//

#ifndef RIJDENDE_POPSCHOOL_EFFECT_H
#define RIJDENDE_POPSCHOOL_EFFECT_H

#include <FastLED.h>

class Effect {
protected:
    CRGB *leds = nullptr;
    unsigned ledCount = 0;

public:
    Effect(CRGB *leds, unsigned ledCount);
    virtual void run(unsigned long milliSeconds) = 0;
};


#endif //RIJDENDE_POPSCHOOL_EFFECT_H
