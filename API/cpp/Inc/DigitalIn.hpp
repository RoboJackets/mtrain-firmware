#pragma once

#include "PinDefs.hpp"

class DigitalIn {
public:
    /** Configures GPIO pin for DigitalIn
     *
     * @param pin Pin def external to board
     * @param pull Pin pull type (pull up, pull down, or no pull)
     */
    DigitalIn(PinName pin, PullType pull = PullType::PullNone);

    ~DigitalIn();

    /** Reads current value of pin
     *
     * @return true (high) or false (low)
     */
    bool read();

    operator bool() {
        return read();
    }

protected:
    PinName pin;
};
