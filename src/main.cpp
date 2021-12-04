#include <Arduino.h>
#include <ESP8266WiFi.h>

#include <array>

#include <FastLED.h>

#include "leds/LedGroup.h"

#include "effects/Spots.h"
#include "effects/MovingLines.h"
#include "effects/Random.h"

#define NUM_LEDS 128

#define DATA_PIN 4
#define CLOCK_PIN 5

CRGB ledsStorage[NUM_LEDS];
unsigned squareMapping[NUM_LEDS] = {
    0,   1,   2,   3,   4,   5,   6,   7,
    15,  14,  13,  12,  11,  10,   9,   8,
    16,  17,  18,  19,  20,  21,  22,  23,
    31,  30,  29,  28,  27,  26,  25,  24,
    32,  33,  34,  35,  36,  37,  38,  39,
    47,  46,  45,  44,  43,  42,  41,  40,
    48,  49,  50,  51,  52,  53,  54,  55,
    63,  62,  61,  60,  59,  58,  57,  56,
    64,  65,  66,  67,  68,  69,  70,  71,
    79,  78,  77,  76,  75,  74,  73,  72,
    80,  81,  82,  83,  84,  85,  86,  87,
    95,  94,  93,  92,  91,  90,  89,  88,
    96, 97, 98, 99,  100,  101,  102,  103,
    111, 110, 109, 108, 107, 106, 105, 104,
    112, 113, 114, 115, 116, 117, 118, 119,
    127, 126, 125, 124, 123, 122, 121, 120,
};

LedGroup leds(ledsStorage, NUM_LEDS, squareMapping);

struct EffectConfiguration {
    Effect& effect;
    long minRuntime = 1000;
    long maxRuntime = 10000;
    const char *name = nullptr;
    long runtime = random(minRuntime, maxRuntime);
};

Spots spots(8, 16, leds);
MovingLines movingLines(8, 16, leds);
Random randomLeds(leds);

bool firstRun = true;
unsigned effectIdx = 0;
std::array<EffectConfiguration, 4> effects = {{
    {spots, 5000, 15000, "Moving Lines"},
    {randomLeds, 1000, 2000, "Random"},
    {movingLines, 4000, 8000, "Moving Lines"},
    {randomLeds, 1000, 2000, "Random"},
}};

void setup() {
    Serial.begin(74880);
    randomSeed(analogRead(12));

    Serial.println("Turning WiFu off");

    WiFi.mode(WIFI_OFF);
    WiFi.forceSleepBegin();

    delay(500);

    Serial.println("Initializing FastLED");

    CFastLED::addLeds<LPD8806, DATA_PIN, CLOCK_PIN, BRG>(ledsStorage, NUM_LEDS);

    FastLED.clear();

    for (unsigned idx = 0; idx < leds.getSize(); idx++) {
        leds.setColour(idx, CRGB::Black);
    }

    FastLED.show();
}

void loop() {
    unsigned long milliseconds = millis();

    Effect* effect = &(effects[effectIdx].effect);

    if (firstRun) {
        effect->start(milliseconds,effects[effectIdx].runtime);
        firstRun = false;
    } else if (!effect->shouldRun(milliseconds)) {
        effects[effectIdx].runtime = random(effects[effectIdx].minRuntime, effects[effectIdx].maxRuntime);
        
        effect->deinit();

        ++effectIdx;

        if (effectIdx >= effects.size()) {
            effectIdx = 0;
        }

        effect = &(effects[effectIdx].effect);
        effect->start(milliseconds,effects[effectIdx].runtime);
    }

    Serial.print(effects[effectIdx].name);
    Serial.print(' ');
    Serial.print(milliseconds);
    Serial.print(' ');
    Serial.println(effectIdx);

    effect->run(milliseconds);
    FastLED.show();

    delay(50);
}
