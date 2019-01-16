#include "digital_in.h"

void digitalin_init(pin_name p) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = p.pin_number;
    pin_structure.Mode = INPUT;
    
    HAL_GPIO_Init(p.bank, &pin_structure);
}

void digitalin_deinit(pin_name p) {
    HAL_GPIO_DeInit(p.bank, p.pin_number);
}

GPIO_PinState digitalin_read(pin_name p) {
    return HAL_GPIO_ReadPin(p.bank, p.pin_number);
}
