#include "digital_in.h"

void digitalin_init_config(pin_name p, pull_type t, speed s) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = p.pin_number;
    pin_structure.Mode = INPUT;
    pin_structure.Pull = t;
    pin_structure.Speed = s;
    
    HAL_GPIO_Init(p.bank, &pin_structure);
}

void digitalin_init(pin_name p) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = p.pin_number;
    pin_structure.Mode = INPUT;
    pin_structure.Pull = PULL_UP;
    pin_structure.Speed = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(p.bank, &pin_structure);
}

void digitalin_deinit(pin_name p) {
    HAL_GPIO_DeInit(p.bank, p.pin_number);
}

GPIO_PinState digitalin_read(pin_name p) {
    return HAL_GPIO_ReadPin(p.bank, p.pin_number);
}
