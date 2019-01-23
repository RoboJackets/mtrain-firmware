#pragma once

#include "PinDefs.hpp"

typedef enum { PUSH_PULL = GPIO_MODE_OUTPUT_PP, OPEN_DRAIN = GPIO_MODE_OUTPUT_OD } PinMode;

typedef enum { LOW = GPIO_SPEED_FREQ_LOW, MEDIUM = GPIO_SPEED_FREQ_MEDIUM, HIGH = GPIO_SPEED_FREQ_HIGH, VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH } PinSpeed;

class DigitalOut {
    int PinState;
public:
    DigitalOut(PinName pin, PullType pull = PullType::PullNone, PinMode mode = GPIO_MODE_OUTPUT_PP, PinSpeed speed = GPIO_SPEED_FREQ_LOW);
    
    ~DigitalOut();

    void write(int state);
    void toggle();

    operator bool() {
        return PinState != 0;
    }

protected:
    PinName pin;
    PinState;
};
