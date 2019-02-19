#ifndef __DIGITAL_IN_H
#define __DIGITAL_IN_H

#include "pin_defs.h"

/** Configures GPIO pin for digitalin
 *
 * Defaults to no pull type
 *
 * @param pin Pin def external to board
 */
void digitalin_init(pin_name pin);

/** Configures GPIO pin for digitalin
 *
 * @param pin Pin def external to board
 * @param pull Pin pull type (pull up, pull down, or no pull)
 */
void digitalin_init_ex(pin_name pin, pull_type pull);

/** Deinits GPIO pin
 *
 * @param pin Pin def external to board
 */
void digitalin_deinit(pin_name pin);

/** Reads current value of pin
 *
 * @param pin Pin def external to board
 * @return 1 (high) or 0 (low)
 */
int digitalin_read(pin_name pin);

#endif
