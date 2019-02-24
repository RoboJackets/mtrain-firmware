#include "mtrain.hpp"

/** InterruptIn and DigitalOut test
 *
 * Blink LEDs back and forth, changing 4th LED as interrupt flag for all
 * interruptible pins
 */
DigitalOut led (LED4);
void blink() {
    //led.toggle();
}

int main(void)
{
  DigitalOut leds[] = {(LED1), (LED2), (LED3)};

  InterruptIn interrupt31 (p31, &blink, PullType::PullDown),
              interrupt35 (p35, &blink, PullType::PullDown),
              interrupt16 (p16, &blink, PullType::PullDown),
              interrupt30 (p30, &blink, PullType::PullDown),
              interrupt18 (p18, &blink, PullType::PullDown),
              interrupt20 (p20, &blink, PullType::PullDown),
              interrupt11 (p11, &blink, PullType::PullDown),
              interrupt34 (p34, &blink, PullType::PullDown),
              interrupt13 (p13, &blink, PullType::PullDown),
              interrupt36 (p36, &blink, PullType::PullDown),
              interrupt5 (p5, &blink, PullType::PullDown),
              interrupt6 (p6, &blink, PullType::PullDown);

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
