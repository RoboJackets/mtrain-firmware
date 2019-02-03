#ifndef __INTERRUPT_IN_H
#define __INTERRUPT_IN_H

#include "pin_defs.h"

typedef enum {
    INTERRUPT_RISING = GPIO_MODE_IT_RISING,
    INTERRUPT_FALLING = GPIO_MODE_IT_FALLING,
    INTERRUPT_RISING_FALLING = GPIO_MODE_IT_RISING_FALLING
} pin_mode;

/** Configures GPIO pin for digital in
 *
 * Defaults to no pull type
 *
 * @param pin Pin def external to board
 */
void interruptin_init(pin_name pin);

/** Configures GPIO pin for digital in
 *
 * @param pin Pin def external to board
 * @param pull Pin pull type
 * @param mode Interrupt mode (rising edge, falling edge, or both edges)
 */
void interruptin_init_ex(pin_name pin, pull_type pull, pin_mode mode);

/** Deinit GPIO pin
 *
 * @param pin  Pin def external to board
 */
void interruptin_deinit(pin_name pin);

#endif
