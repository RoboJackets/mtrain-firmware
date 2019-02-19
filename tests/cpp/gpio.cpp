#include "mtrain.hpp"

/** DigitalIn and DigitalOut test
 *
 * Read pins 35 and 36 and outputs value to LED1 and LED2
 */
int main(void)
{
  // Configure pins for digital out
  DigitalOut led1 (LED1);
  DigitalOut led2 (LED2);

  // Configure pins for digital in
  DigitalIn pin35 (p35, PullType::PullDown);
  DigitalIn pin36 (p36, PullType::PullDown);

  while (true) {
    // Read pins and assign values to LEDs
    led1 = (bool) pin35;
    led2 = (bool) pin36;
    HAL_Delay(10);
  }
}
