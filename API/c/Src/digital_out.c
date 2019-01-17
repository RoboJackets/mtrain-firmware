#include "digital_out.h"

void digitalout_init(pin_name pin) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.number;
    pin_structure.Mode = OPEN_DRAIN;
    pin_structure.Pull = PULL_UP;
    pin_structure.Speed = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(pin.bank, &pin_structure);
}

void digitalout_init_ex(pin_name pin, pull_type pull, pin_mode mode, pin_speed speed) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.number;
    pin_structure.Mode = mode;
    pin_structure.Pull = pull;
    pin_structure.Speed = speed;
    
    HAL_GPIO_Init(pin.bank, &pin_structure);
}

void digitalout_deinit(pin_name pin) {
    HAL_GPIO_DeInit(pin.bank, pin.number);
}

void digitalout_write(pin_name pin, GPIO_PinState state) {
    HAL_GPIO_WritePin(pin.bank, pin.number, state);
}

void digitalout_toggle(pin_name pin) {
    return HAL_GPIO_TogglePin(pin.bank, pin.number);
}

GPIO_PinState digitalout_read(pin_name pin) {
    return HAL_GPIO_ReadPin(pin.bank, pin.number);
}
