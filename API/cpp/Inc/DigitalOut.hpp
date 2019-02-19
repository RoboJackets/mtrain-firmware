#pragma once

#include "PinDefs.hpp"

typedef enum {
    PushPull = GPIO_MODE_OUTPUT_PP,
    OpenDrain = GPIO_MODE_OUTPUT_OD
} PinMode;

typedef enum {
    Low = GPIO_SPEED_FREQ_LOW,
    Medium = GPIO_SPEED_FREQ_MEDIUM,
    High = GPIO_SPEED_FREQ_HIGH,
    VeryHigh = GPIO_SPEED_FREQ_VERY_HIGH
} PinSpeed;

class DigitalOut {
public:
    /** Configures GPIO pin for DigitalOut
     *
     * @param pin Pin def external to board
     * @param pull Pin pull type (pull up, pull down, or no pull)
     * @param mode Output mode (push-pull or open-drain)
     * @param speed GPIO frequency (low, medium, high, or very high)
     * @param inverted Inverts output value of pin
     */
    DigitalOut(PinName pin, PullType pull = PullType::PullNone,
        PinMode mode = PinMode::PushPull, PinSpeed speed = PinSpeed::Low,
        bool inverted = false);

    ~DigitalOut();

    /** Changes output state of pin
     *
     * @param state Output value of pin
     *              push-pull:  0 (low) or 1 (high),
     *              open-drain: 0 (high-z) or 1 (drive low)
     */
    void write(bool state);

    /** Toggles pin output
     *
     */
    void toggle();

    /** Reads current value of pin
     *
     * @return true (high) or false (low)
     */
    bool read();

    void operator = (bool rhs) {
        write(rhs);
    }

    operator bool() {
        return read();
    }

protected:
    PinName pin;
    bool inverted;
};
