#include "mtrain.h"
#include "digital_out.h"

int main(void)
{
  // Basic Init Testing
  digitalout_init(LED1);
  digitalout_init(LED2);
  digitalout_init(LED3);
  digitalout_init(LED4);
  
  // Deinit Testing
  digitalout_deinit(LED1);
  digitalout_deinit(LED2);
  digitalout_deinit(LED3);
  digitalout_deinit(LED4);
  
  // Complex Init Testing
  digitalout_init_config(LED1, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_config(LED2, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_config(LED3, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_config(LED4, PULL_DOWN, PUSH_PULL, LOW);
  while (1) {
    // Normal Write Testing
    // digitalout_write(LED1, GPIO_PIN_RESET);
    // digitalout_write(LED2, GPIO_PIN_RESET);
    // digitalout_write(LED3, GPIO_PIN_RESET);
    // digitalout_write(LED4, GPIO_PIN_RESET);
    // HAL_Delay(250);
    // digitalout_write(LED1, GPIO_PIN_SET);
    // digitalout_write(LED2, GPIO_PIN_SET);
    // digitalout_write(LED3, GPIO_PIN_SET);
    // digitalout_write(LED4, GPIO_PIN_SET);
    // HAL_Delay(250);
    
    // Toggle Testing
    digitalout_toggle(LED1);
    digitalout_toggle(LED2);
    digitalout_toggle(LED3);
    digitalout_toggle(LED4);
    HAL_Delay(250);
    
    // Read Testing
    // digitalout_init(PIN36);
    // digitalout_init(PIN35);
    // digitalout_init(PIN34);
    // digitalout_init(PIN33);
    // digitalout_write(LED1, digitalout_read(PIN36));
    // digitalout_write(LED2, digitalout_read(PIN35));
    // digitalout_write(LED3, digitalout_read(PIN34));
    // digitalout_write(LED4, digitalout_read(PIN33));
    // HAL_Delay(250);
  }
}
