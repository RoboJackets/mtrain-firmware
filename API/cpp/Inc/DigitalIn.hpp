#pragma once

#include "PinDefs.hpp"

class DigitalIn {
public:
    DigitalIn(PinName pin, PullType pull = PullType::PullNone);
    
    ~DigitalIn();

    bool read();

    operator bool() {
        return read();
    }

protected:
    PinName pin;
};
