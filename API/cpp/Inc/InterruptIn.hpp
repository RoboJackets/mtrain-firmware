#pragma once

#include "PinDefs.hpp"

typedef enum {
    InterruptRising = GPIO_MODE_IT_RISING,
    InterruptFalling = GPIO_MODE_IT_FALLING,
    InterruptRisingFalling = GPIO_MODE_IT_RISING_FALLING
} InterruptMode;

class InterruptIn {
public:
    /** Configures GPIO pin for digital in
     *
     * @param pin Pin def external to board
     * @param pull Pin pull type
     */
    DigitalIn(PinName pin, PullType pull = PullType::PullNone,
        InterruptMode mode = InterruptMode::InterruptRisingFalling);
    
    ~DigitalIn();
    
    /** Read current value of pin
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
