#include "DigitalOut.h"

void digitalout_init_config(pin_name p, pull_type t, output_mode o, speed s) {
    __HAL_RCC_GPIOx_CLK_ENABLE();
    
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = p.pin_number;
    pin_structure.Mode = o;
    pin_structure.Pull = t;
    pin_structure.Speed = s
    
    HAL_GPIO_Init(p.bank, );
}

void digitalout_init(pin_name p) {
    
}
void digitalout_write(pin_name p, GPIO_PinState s) {
    
}
GPIO_PinState digitalout_read(pin_name p) {
    
}
