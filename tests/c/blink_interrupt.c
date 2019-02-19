#include "mtrain.h"

/** interruptin and digitalout test
 *
 * Blinks LEDs back and forth, changing 4th LED as interrupt flag for all
 * interruptible pins
 */
 void blink() {
     digitalout_toggle(LED4);
 }

int main(void)
{
  digitalout_init(LED1);
  digitalout_init(LED2);
  digitalout_init(LED3);
  digitalout_init(LED4);

  interruptin_init(PIN31, &blink);
  interruptin_init(PIN35, &blink);
  interruptin_init(PIN16, &blink);
  interruptin_init(PIN30, &blink);
  interruptin_init(PIN18, &blink);
  interruptin_init(PIN20, &blink);
  interruptin_init(PIN11, &blink);
  interruptin_init(PIN34, &blink);
  interruptin_init(PIN13, &blink);
  interruptin_init(PIN36, &blink);
  interruptin_init(PIN5, &blink);
  interruptin_init(PIN4, &blink);

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
