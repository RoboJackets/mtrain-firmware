#ifndef __INTERRUPT_IN_H
#define __INTERRUPT_IN_H

#include "pin_defs.h"

typedef enum {
    INTERRUPT_RISING = GPIO_MODE_IT_RISING,
    INTERRUPT_FALLING = GPIO_MODE_IT_FALLING,
    INTERRUPT_RISING_FALLING = GPIO_MODE_IT_RISING_FALLING
} interrupt_mode;

/** Handles interrupts for interrupt line 0
 */
void EXTI0_IRQHandler(void);

/** Handles interrupts for interrupt line 4
 */
void EXTI4_IRQHandler(void);

/** Handles interrupts for interrupt lines 5 to 9
 */
void EXTI9_5_IRQHandler(void);

/** Handles interrupts for interrupt lines 10 to 15
 */
void EXTI15_10_IRQHandler(void);

/** Configures GPIO pin for interruptin
 *
 * Defaults to no pull type and both edge detection
 *
 * @param pin Pin def external to board
 * @param function Function linked to interrupt
 */
void interruptin_init(pin_name pin, void (*function)());

/** Configures GPIO pin for interruptin
 *
 * @param pin Pin def external to board
 * @param pull Pin pull type (pull up, pull down, or no pull)
 * @param mode Interrupt mode (rising edge, falling edge, or both edges)
 * @param function Function linked to interrupt
 */
void interruptin_init_ex(pin_name pin, pull_type pull, interrupt_mode mode,
    void (*function)());

/** Deinits GPIO pin
 *
 * @param pin Pin def external to board
 */
void interruptin_deinit(pin_name pin);

/** Reads current value of pin
 *
 * @param pin Pin def external to board
 * @return 1 (high) or 0 (low)
 */
int digitalin_read(pin_name pin);

#endif
