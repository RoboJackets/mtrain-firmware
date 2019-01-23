#pragma once

#include "PinDefs.hpp"

class DigitalIn {
public:
    // Initializes Digital In
    // Required: pin_name pin
    // Default: pull_type PULL_NONE, pin_mode GPIO_MODE_INPUT
    DigitalIn(PinName pin, PullType pull = PullType::PullNone);
    
    // Deinitalizes Digital In
    ~DigitalIn();
    
    // Returns pin state as true (high) or false (low)
    bool read();
    
    // Overloads bool operation, returns pin state as true (high) or false (low)
    operator bool() {
        return read();
    }

protected:
    PinName pin;
};
