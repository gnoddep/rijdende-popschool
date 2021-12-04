//
// Created by peter on 04-12-21.
//

#ifndef RIJDENDE_POPSCHOOL_MOVINGLINES_H
#define RIJDENDE_POPSCHOOL_MOVINGLINES_H

#include "Effect.h"

class MovingLines: public Effect {
private:
    long width;
    long height;
    CRGB colour;

    int verticalLineX = 4;
    int verticalDirection = 1;
    int horizontalLineY = 0;
    int horizontalDirection = 1;

public:
    explicit MovingLines(long width, long height, LedGroup& leds);

    void run(unsigned long milliseconds) override;
    void deinit() override;
};

#endif //RIJDENDE_POPSCHOOL_MOVINGLINES_H
