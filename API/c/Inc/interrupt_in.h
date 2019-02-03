#ifndef __INTERRUPT_IN_H
#define __INTERRUPT_IN_H

#include "pin_defs.h"

typedef enum {
    INTERRUPT_RISING = GPIO_MODE_IT_RISING,
    INTERRUPT_FALLING = GPIO_MODE_IT_FALLING,
    INTERRUPT_RISING_FALLING = GPIO_MODE_IT_RISING_FALLING
} interrupt_mode;

/** Configures GPIO pin for interrupt in
 *
 * Defaults to no pull type and both edge detection
 *
 * @param pin Pin def external to board
 */
void interruptin_init(pin_name pin);

/** Configures GPIO pin for interrupt in
 *
 * @param pin Pin def external to board
 * @param pull Pin pull type (pull up, pull down, or no pull)
 * @param mode Interrupt mode (rising edge, falling edge, or both edges)
 */
void interruptin_init_ex(pin_name pin, pull_type pull, interrupt_mode mode);

/** Deinit GPIO pin
 *
 * @param pin Pin def external to board
 */
void interruptin_deinit(pin_name pin);

/** Read current value of pin
 *
 * @param pin Pin def external to board
 * @return 1 (high) or 0 (low)
 */
int digitalin_read(pin_name pin);

#endif
