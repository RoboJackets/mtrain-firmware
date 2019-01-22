#include "DigitalOut.hpp"

DigitalOut::DigitalOut(PinName pin, PullType pull, PinMode mode, PinSpeed speed) : pin(pin) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.number;
    pin_structure.Mode = mode;
    pin_structure.Pull = pull;
    pin_structure.Speed = speed;
    
    HAL_GPIO_Init(pin.bank, &pin_structure);
}
DigitalOut::~DigitalOut() {
    HAL_GPIO_DeInit(pin.bank, pin.number);
}

bool DigitalOut::write(int state) {
    PinState = state;
    HAL_GPIO_WritePin(pin.bank, pin.number, state != 0);
}

bool DigitalOut::toggle() {
    HAL_GPIO_TogglePin(pin.bank, pin.number);
}
