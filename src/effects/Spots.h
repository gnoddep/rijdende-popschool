//
// Created by peter on 04-12-21.
//

#ifndef RIJDENDE_POPSCHOOL_SPOTS_H
#define RIJDENDE_POPSCHOOL_SPOTS_H

#define NUM_SPOTS 6

#include "Effect.h"

class Spots: public Effect {
    long width;
    long height;

    long centers[NUM_SPOTS][2];
    long moves[NUM_SPOTS][2];
    CRGB colours[NUM_SPOTS];

private:
    static long updateMove(long move, long max);

public:
    explicit Spots(long width, long height, LedGroup& leds);

    void run(unsigned long milliseconds) override;
    void init() override;
};

#endif //RIJDENDE_POPSCHOOL_SPOTS_H
