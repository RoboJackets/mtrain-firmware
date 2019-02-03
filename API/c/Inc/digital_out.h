#ifndef __DIGITAL_OUT_H
#define __DIGITAL_OUT_H

#include "pin_defs.h"

typedef enum {
    PUSH_PULL = GPIO_MODE_OUTPUT_PP,
    OPEN_DRAIN = GPIO_MODE_OUTPUT_OD
} pin_mode;

typedef enum {
    LOW = GPIO_SPEED_FREQ_LOW,
    MEDIUM = GPIO_SPEED_FREQ_MEDIUM,
    HIGH = GPIO_SPEED_FREQ_HIGH,
    VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH
} pin_speed;

/** Configures GPIO pin for digital out
 *
 * Defaults to push-pull mode, no pull type, and low gpio frequency
 *
 * @param pin Pin def external to board
 */
void digitalout_init(pin_name pin);

/** Configures GPIO pin for digital out
 *
 * @param pin Pin def external to board
 * @param pull Pin pull type (pull up, pull down, or no pull)
 * @param mode Output mode (push-pull or open-drain)
 * @param speed GPIO frequency (low, medium, high, or very high)
 */
void digitalout_init_ex(pin_name pin, pull_type pull,
    pin_mode mode, pin_speed speed);

/** Deinit GPIO pin
 *
 * @param pin Pin def external to board
 */
void digitalout_deinit(pin_name pin);

/** Change output state of pin
 *
 * @param pin Pin def external to board
 * @param state Output value of pin
 *              push-pull:  0 (low) or 1 (high),
 *              open-drain: 0 (high-z) or 1 (drive low)
 */
void digitalout_write(pin_name pin, int state);

/** Toggle pin output
 *
 * @param pin Pin def external to board
 */
void digitalout_toggle(pin_name pin);

/** Read current value of pin
 *
 * @param pin Pin def external to board
 * @return 1 (high) or 0 (low)
 */
int digitalout_read(pin_name p);

#endif
