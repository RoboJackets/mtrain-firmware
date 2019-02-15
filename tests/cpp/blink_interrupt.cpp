#include "mtrain.hpp"

/** InterruptIn and DigitalOut test
 *
 * Blink LEDs back and forth, changing 4th LED as interrupt flag for all
 * interruptible pins
 */
void blink() {
    DigitalOut led (LED4);
    led.toggle();
}

int main(void)
{
  DigitalOut leds[] = {(LED1), (LED2), (LED3)};
  
  InterruptIn(p31, blink);
  InterruptIn(p35, blink);
  InterruptIn(p16, blink);
  InterruptIn(p30, blink);
  InterruptIn(p18, blink);
  InterruptIn(p20, blink);
  InterruptIn(p11, blink);
  InterruptIn(p34, blink);
  InterruptIn(p13, blink);
  InterruptIn(p36, blink);
  InterruptIn(p5, blink);
  InterruptIn(p6, blink);

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
