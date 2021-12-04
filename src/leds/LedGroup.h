//
// Created by peter on 04-12-21.
//

#ifndef RIJDENDE_POPSCHOOL_LEDGROUP_H
#define RIJDENDE_POPSCHOOL_LEDGROUP_H

#include <FastLED.h>

class LedGroup {
private:
    CRGB* leds;
    size_t size;
    unsigned* mapping;

public:
    LedGroup(CRGB* leds, size_t size, unsigned* mapping = nullptr): leds(leds), size(size), mapping(mapping) {};

    [[nodiscard]] CRGB* getLeds() const;
    [[nodiscard]] size_t getSize() const;

    void setColour(unsigned idx, CRGB colour);
    void addColour(unsigned idx, CRGB colour);
};


#endif //RIJDENDE_POPSCHOOL_LEDGROUP_H
