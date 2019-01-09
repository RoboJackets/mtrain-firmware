#include "DigitalOut.h"

void digitalout_init_config(pin_name p, pull_type t, output_mode o, speed s) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = p.pin_number;
    pin_structure.Mode = o;
    pin_structure.Pull = t;
    pin_structure.Speed = s;
    
    HAL_GPIO_Init(p.bank, pin_structure);
}

void digitalout_init(pin_name p) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = p.pin_number;
    pin_structure.Mode = PULL_UP;
    pin_structure.Pull = OPEN_DRAIN;
    pin_structure.Speed = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(p.bank, pin_structure);
}

void digitalout_deinit(pin_name p){
    HAL_GPIO_DeInit(p.bank, p.pin_number);
}

void digitalout_write(pin_name p, GPIO_PinState s) {
    
}

GPIO_PinState digitalout_read(pin_name p) {
    
}
