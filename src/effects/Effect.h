//
// Created by peter on 30-11-21.
//

#ifndef RIJDENDE_POPSCHOOL_EFFECT_H
#define RIJDENDE_POPSCHOOL_EFFECT_H

#include <FastLED.h>

#include "../leds/LedGroup.h"

class Effect {
private:
    LedGroup& leds;

    unsigned long startMilliseconds = 0;
    unsigned long endMilliseconds = 0;

protected:
    LedGroup& getLeds();
    void clear();

public:
    explicit Effect(LedGroup& leds): leds(leds) {};

    void start(unsigned long milliseconds, unsigned long runtimeMilliseconds);
    [[nodiscard]] bool shouldRun(unsigned long milliseconds) const;

    virtual void init();
    virtual void run(unsigned long milliseconds) = 0;
    virtual void deinit() {};
};

#endif //RIJDENDE_POPSCHOOL_EFFECT_H
