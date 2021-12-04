//
// Created by peter on 04-12-21.
//

#include "MovingLines.h"

MovingLines::MovingLines(long width, long height, LedGroup &leds):
    Effect(leds),
    width(width),
    height(height) {};

void MovingLines::run(unsigned long milliseconds) {
    LedGroup& leds = this->getLeds();

    this->clear();

    for (unsigned x = 0; x < this->width; x++) {
        leds.addColour(x + (this->horizontalLineY * this->width), colour);
        leds.addColour(x + ((this->horizontalLineY + 1) * this->width), colour);
    }

    this->horizontalLineY += this->horizontalDirection;
    if (this->horizontalLineY < 0 || this->horizontalLineY >= this->height - 1) {
        this->horizontalDirection = -this->horizontalDirection;
        this->horizontalLineY += this->horizontalDirection * 2;
    }

    for (unsigned y = 0; y < this->height; y++) {
        leds.addColour(this->verticalLineX + (y * this->width), colour);
    }

    this->verticalLineX += this->verticalDirection;
    if (this->verticalLineX < 0 || this->verticalLineX >= this->width) {
        this->verticalDirection = -this->verticalDirection;
        this->verticalLineX += this->verticalDirection * 2;
    }

    delay(50);
}

void MovingLines::init() {
    Effect::init();
    this->colour = CRGB((random(256) << 16) + (random(256) << 8) + random(256));
}
