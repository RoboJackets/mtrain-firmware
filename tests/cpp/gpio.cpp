#include "mtrain.hpp"

/** DigitalIn and DigitalOut test
 *
 * Read pins 35 and 36 and output value to LED1 and LED2
 */
int main(void)
{
  // Configure pins for DigitalOut
  DigitalOut led1 (LED1),
             led2 (LED2);

  // Configure pins for DigitalIn
  DigitalIn pin35 (p35, PullType::PullDown),
            pin36 (p36, PullType::PullDown);

  while (true) {
    // Read pins and assign values to LEDs
    led1 = pin35;
    led2 = pin36;
    HAL_Delay(10);
  }
}
