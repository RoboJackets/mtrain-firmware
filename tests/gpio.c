#include "mtrain.h"
#include "digital_out.h"
#include "digital_in.h"

int main(void)
{ 
  // Basic Init Testing
  digitalout_init(LED1);
  digitalout_init(LED2);
  digitalout_init(LED3);
  digitalout_init(LED4);
  
  // Deinit Testing
  // digitalout_deinit(LED1);
  // digitalout_deinit(LED2);
  // digitalout_deinit(LED3);
  // digitalout_deinit(LED4);
  
  // Complex Init Testing
  digitalout_init_ex(LED1, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_ex(LED2, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_ex(LED3, PULL_DOWN, PUSH_PULL, LOW);
  digitalout_init_ex(LED4, PULL_DOWN, PUSH_PULL, LOW);
    
  // Basic Init Testing
  // digitalin_init(PIN36);
  // digitalin_init(PIN35);
  // digitalin_init(PIN34);
  // digitalin_init(PIN33);
  
  // Deinit Testing
  // digitalin_deinit(PIN36);
  // digitalin_deinit(PIN35);
  // digitalin_deinit(PIN34);
  // digitalin_deinit(PIN33);
  
  // Complex Init Testing
  digitalin_init_ex(PIN36, PULL_DOWN);
  digitalin_init_ex(PIN35, PULL_DOWN);
  digitalin_init_ex(PIN34, PULL_DOWN);
  digitalin_init_ex(PIN33, PULL_DOWN);
  while (1) {
    //Read Testing
    digitalout_write(LED1, digitalin_read(PIN36));
    digitalout_write(LED2, digitalin_read(PIN35));
    digitalout_write(LED3, digitalin_read(PIN34));
    digitalout_write(LED4, digitalin_read(PIN33));
    HAL_Delay(10);
  }
}
