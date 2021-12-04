//
// Created by peter on 04-12-21.
//

#include "Spots.h"

Spots::Spots(long width, long height, LedGroup &leds):
        Effect(leds),
        width(width),
        height(height)
{
    for (auto &center: this->centers) {
        center[0] = random(this->width);
        center[1] = random(this->height);
    }

    for (auto &move: this->moves) {
        move[0] = random(0, 1) ? random(-1, -2) : random(1, 2);
        move[1] = random(0, 1) ? random(-1, -3) : random(1, 3);
    }
}

void Spots::run(unsigned long milliseconds) {
    LedGroup& leds = this->getLeds();

    this->clear();

    int idx = 0;
    for (auto &center: this->centers) {
        for (long x = center[0] - 1; x < center[0] + 1; x++) {
            for (long y = center[1] - 1; y < center[1] + 1; y++) {
                if (0 <= x && x < this->width && 0 <= y && y < this->height) {
                    leds.addColour(x + (y * this->width), this->colours[idx]);
                }
            }
        }

        center[0] += this->moves[idx][0];
        center[1] += this->moves[idx][1];

        if (center[0] < 0) {
            center[0] = 0;
            this->moves[idx][0] = Spots::updateMove(this->moves[idx][0], 2);
        } else if (center[0] >= this->width) {
            center[0] = this->width - 1;
            this->moves[idx][0] = Spots::updateMove(this->moves[idx][0], 2);
        }

        if (center[1] < 0) {
            center[1] = 0;
            this->moves[idx][1] = Spots::updateMove(this->moves[idx][1], 3);
        } else if (center[1] >= this->height) {
            center[1] = this->height - 1;
            this->moves[idx][1] = Spots::updateMove(this->moves[idx][1], 3);
        }

        ++idx;
    }

    delay(50);
}

void Spots::init() {
    Effect::init();
    for (auto &colour: this->colours) {
        colour = CRGB((random(256) << 16) + (random(256) << 8) + random(256));
    }
}

long Spots::updateMove(long move, long max) {
    if (move < 0) {
        return random(1, max);
    }

    return random(-max, -1);
}
