#include "interrupt_in.h"

void interruptin_init(pin_name pin) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = GPIO_MODE_IT_RISING_FALLING;
    pin_structure.Pull = GPIO_NOPULL;
    
    HAL_GPIO_Init(pin.port, &pin_structure);
}

void interruptin_init_ex(pin_name pin, pull_type pull, interrupt_mode mode) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = mode;
    pin_structure.Pull = pull;
    
    HAL_GPIO_Init(pin.port, &pin_structure);
}

void interruptin_deinit(pin_name pin) {
    HAL_GPIO_DeInit(pin.port, pin.pin);
}
