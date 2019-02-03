#include "InterruptIn.hpp"

InterruptIn::InterruptIn(PinName pin, PullType pull, InterruptMode mode)
: pin(pin) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = mode;
    pin_structure.Pull = pull;
    
    HAL_GPIO_Init(pin.port, &pin_structure);
}
InterruptIn::~InterruptIn() {
    HAL_GPIO_DeInit(pin.port, pin.pin);
}

bool InterruptIn::read() {
    return HAL_GPIO_ReadPin(pin.port, pin.pin);
}
