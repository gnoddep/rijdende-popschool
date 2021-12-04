//
// Created by peter on 04-12-21.
//

#ifndef RIJDENDE_POPSCHOOL_RANDOM_H
#define RIJDENDE_POPSCHOOL_RANDOM_H

#include "Effect.h"

class Random: public Effect {
public:
    explicit Random(LedGroup& leds): Effect(leds) {};
    void run(unsigned long milliseconds) override;
};


#endif //RIJDENDE_POPSCHOOL_RANDOM_H
