#include "mtrain.h"

void do_nothing() {
    digitalout_toggle(LED4);
    // // while (1) {
    // //     digitalout_toggle(LED4);
    // //     HAL_Delay(500);
    // //     digitalout_toggle(LED4);
    // //     HAL_Delay(500);
    // // }
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
  interruptin_init(PIN31, &do_nothing);
  
  pin_name leds[] = {LED1, LED2, LED3, LED4};

  int id = 0;
  int forward = 1;

  while (1) {
    digitalout_toggle(leds[id]);
    HAL_Delay(100);
    digitalout_toggle(leds[id]);

    if (id == 2) {
        forward = -1;
    } else if(id == 0) {
        forward = 1;
    }
    id += forward;
  }
}
