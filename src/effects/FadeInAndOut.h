//
// Created by peter on 30-11-21.
//

#ifndef RIJDENDE_POPSCHOOL_FADEINANDOUT_H
#define RIJDENDE_POPSCHOOL_FADEINANDOUT_H

#include "Effect.h"

class FadeInAndOut: public Effect {
public:
    FadeInAndOut(CRGB *leds, unsigned int ledCount);
    void run(unsigned long milliSeconds) override;
};


#endif //RIJDENDE_POPSCHOOL_FADEINANDOUT_H
