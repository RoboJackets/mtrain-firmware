#pragma once

#include "PinDefs.hpp"

class DigitalIn {
public:
    DigitalIn(PinName pin, PullType pull = GPIO_NOPULL);
    
    ~DigitalIn();

    bool read();

    operator bool() {
        return read();
    }

protected:
    PinName pin;
};
