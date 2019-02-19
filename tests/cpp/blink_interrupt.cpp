#include "mtrain.hpp"

/** InterruptIn and DigitalOut test
 *
 * Blink LEDs back and forth, changing 4th LED as interrupt flag for all
 * interruptible pins
 */

DigitalOut led (LED4);
void blink() {
    led.toggle();
}

int main(void)
{
  DigitalOut leds[] = {(LED1), (LED2), (LED3)};

  InterruptIn interrupt31 (p31, blink),
              interrupt35 (p35, blink),
              interrupt16 (p16, blink),
              interrupt30 (p30, blink),
              interrupt18 (p18, blink),
              interrupt20 (p20, blink),
              interrupt11 (p11, blink),
              interrupt34 (p34, blink),
              interrupt13 (p13, blink),
              interrupt36 (p36, blink),
              interrupt5 (p5, blink),
              interrupt6 (p6, blink);

  int id = 0;
  bool forward = true;

  while (true) {
    leds[id].toggle();
    HAL_Delay(100);
    leds[id].toggle();

    if (id == 2) {
        forward = false;
    } else if (id == 0) {
        forward = true;
    }
    id += forward ? 1 : -1;
  }
}
