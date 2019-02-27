#include <mtrain.h>

#ifndef __DAC_H
#define __DAC_H

void analogout_init(pin_name pin);
void analogout_deinit(pin_name pin);

void analogout_write(pin_name pin, float value);
void analogout_read(pin_naame pin);

#endif /* __MAIN_H */


