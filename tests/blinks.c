#include "mtrain.h"
#include "digital_out.h"

int main(void)
{
  pin_name pin1 = (pin_name) {LED_PORT, LED1_PIN};
  pin_name pin2 = (pin_name) {LED_PORT, LED2_PIN};
  pin_name pin3 = (pin_name) {LED_PORT, LED3_PIN};
  pin_name pin4 = (pin_name) {LED_PORT, LED4_PIN};
  
  // Basic Init Testing
  digitalout_init(pin1);
  digitalout_init(pin2);
  digitalout_init(pin3);
  digitalout_init(pin4);
  
  // Deinit Testing
  digitalout_deinit(pin1);
  digitalout_deinit(pin2);
  digitalout_deinit(pin3);
  digitalout_deinit(pin4);
  
  // Complex Init Testing
  digitalout_init_config(pin1, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_config(pin2, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_config(pin3, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_config(pin4, PULL_DOWN, PUSH_PULL, LOW);
  while (1) {
    // Normal Write Testing
    // digitalout_write(pin1, GPIO_PIN_RESET);
    // digitalout_write(pin2, GPIO_PIN_RESET);
    // digitalout_write(pin3, GPIO_PIN_RESET);
    // digitalout_write(pin4, GPIO_PIN_RESET);
    // HAL_Delay(250);
    // digitalout_write(pin1, GPIO_PIN_SET);
    // digitalout_write(pin2, GPIO_PIN_SET);
    // digitalout_write(pin3, GPIO_PIN_SET);
    // digitalout_write(pin4, GPIO_PIN_SET);
    // HAL_Delay(250);
    
    // Toggle Testing
    // digitalout_toggle(pin1);
    // digitalout_toggle(pin2);
    // digitalout_toggle(pin3);
    // digitalout_toggle(pin4);
    // HAL_Delay(250);
    
    // Read Testing
    digitalout_init(Pin36);
    digitalout_init(Pin35);
    digitalout_init(Pin34);
    digitalout_init(Pin33);
    digitalout_write(pin1, digitalout_read(Pin36));
    digitalout_write(pin2, digitalout_read(Pin35));
    digitalout_write(pin3, digitalout_read(Pin34));
    digitalout_write(pin4, digitalout_read(Pin33));
    HAL_Delay(250);
  }
}
