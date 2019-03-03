#include "DigitalIn.hpp"

DigitalIn::DigitalIn(PinName pin, PullType pull) : pin(pin) {
    GPIO_InitTypeDef pinStructure;
    pinStructure.Pin = pin.pin;
    pinStructure.Pull = pull;
    pinStructure.Mode = GPIO_MODE_INPUT;

    HAL_GPIO_Init(pin.port, &pinStructure);
}
DigitalIn::~DigitalIn() {
    HAL_GPIO_DeInit(pin.port, pin.pin);
}

bool DigitalIn::read() {
    return HAL_GPIO_ReadPin(pin.port, pin.pin);
}
