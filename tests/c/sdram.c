#include "mtrain.h"

int fill_function (int i) {
    return (i * i) + i + 3;
}

/**
 * Blink LEDs back and forth
 */
int main(void)
{
    digitalout_init(LED1);
    digitalout_init(LED2);
    digitalout_init(LED3);
    digitalout_init(LED4);

    pin_name leds[] = {LED1, LED2, LED3, LED4};

    int test_length = 400;

    int* ram_start = (int*) 0xCFFFFFFF;
    int* cur = ram_start;

    int test_success = 1;

    digitalout_toggle(leds[0]);
    for(int i = 0; i < test_length; i++) {
        *cur = fill_function(i); // HARD FAULT
    }
    digitalout_toggle(leds[0]);

    digitalout_toggle(leds[1]);
    for(int i = 0; i < test_length; i++) {
        if (fill_function(i) == *cur) {
            test_success = 1; // continuing success
        } else {
            test_success = 0; // fail and break
            break;
        }
    }
    digitalout_toggle(leds[1]);

    if (test_success == 1) {
        digitalout_toggle(leds[2]);
    } else {
        digitalout_toggle(leds[3]);
    }
    return test_success;
}
