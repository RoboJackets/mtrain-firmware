#ifndef __DIGITAL_IN_H
#define __DIGITAL_IN_H

#include "pin_defs.h"

// Initializes Digital In
// Required: pin_name pin
// Default: pull_type PULL_NONE, pin_mode GPIO_MODE_INPUT
void digitalin_init(pin_name p);
// Initializes Digital In
// Required: pin_name pin, pull_type
// Default: pin_mode GPIO_MODE_INPUT
void digitalin_init_ex(pin_name p, pull_type type);
// Deinitalizes Digital In
// Required: pin_name pin
void digitalin_deinit(pin_name p);

// Returns pin state as 1 (high) or 0 (low)
// Required: pin_name pin
int digitalin_read(pin_name p);

#endif
