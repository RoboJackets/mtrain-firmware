#include "InterruptIn.hpp"

InterruptFunction interrupt0 = NULL;
InterruptFunction interrupt4 = NULL;
InterruptFunction interrupt5 = NULL;
InterruptFunction interrupt6 = NULL;
InterruptFunction interrupt7 = NULL;
InterruptFunction interrupt8 = NULL;
InterruptFunction interrupt9 = NULL;
InterruptFunction interrupt10 = NULL;
InterruptFunction interrupt11 = NULL;
InterruptFunction interrupt12 = NULL;
InterruptFunction interrupt14 = NULL;
InterruptFunction interrupt15 = NULL;

void interrupt_config(uint16_t pin, InterruptFunction function) {
    if (pin == GPIO_PIN_0) {
        interrupt0 = function;
        HAL_NVIC_SetPriority(EXTI0_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    } else if (pin == GPIO_PIN_4) {
        interrupt4 = function;
        HAL_NVIC_SetPriority(EXTI4_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI4_IRQn);
    } else if (pin == GPIO_PIN_5) {
        interrupt5 = function;
        HAL_NVIC_SetPriority(EXTI9_5_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_6) {
        interrupt6 = function;
        HAL_NVIC_SetPriority(EXTI9_5_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_7) {
        interrupt7 = function;
        HAL_NVIC_SetPriority(EXTI9_5_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_8) {
        interrupt8 = function;
        HAL_NVIC_SetPriority(EXTI9_5_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_9) {
        interrupt9 = function;
        HAL_NVIC_SetPriority(EXTI9_5_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_10) {
        interrupt10 = function;
        HAL_NVIC_SetPriority(EXTI15_10_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_11) {
        interrupt11 = function;
        HAL_NVIC_SetPriority(EXTI15_10_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_12) {
        interrupt12 = function;
        HAL_NVIC_SetPriority(EXTI15_10_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_14) {
        interrupt14 = function;
        HAL_NVIC_SetPriority(EXTI15_10_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_15) {
        interrupt15 = function;
        HAL_NVIC_SetPriority(EXTI15_10_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    }
}

void EXTI0_IRQHandler(void)
{
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET) { // Handles A0 (31)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
      interrupt0();
    }
}

void EXTI4_IRQHandler(void)
{
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_4) != RESET) { // Handles B4 (35)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_4);
      interrupt4();
    }
}

void EXTI9_5_IRQHandler(void)
{
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_5) != RESET) { // Handles D5 (16)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_5);
      interrupt5();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_6) != RESET) { // Handles F6 (30)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);
      interrupt6();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_7) != RESET) { // Handles D7 (18)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_7);
      interrupt7();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_8) != RESET) { // Handles D8 (20)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_8);
      interrupt8();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_9) != RESET) { // Handles C9 (11)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_9);
      interrupt9();
    }
}

void EXTI15_10_IRQHandler(void)
{
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_10) != RESET) { // Handle C10 (34)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_10);
      interrupt10();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_11) != RESET) { // Handle H11 (13)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_11);
      interrupt11();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_12) != RESET) { // Handle C12 (36)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_12);
      interrupt12();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_14) != RESET) { // Handle B14 (5)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_14);
      interrupt14();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_15) != RESET) { // Handle B15 (4)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_15);
      interrupt15();
    }
}

InterruptIn::InterruptIn(PinName pin, InterruptFunction function, PullType pull,
    InterruptMode mode) : pin(pin), function(function) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = mode;
    pin_structure.Pull = pull;

    HAL_GPIO_Init(pin.port, &pin_structure);
    interrupt_config(pin.pin, function);
}
InterruptIn::~InterruptIn() {
    HAL_GPIO_DeInit(pin.port, pin.pin);
}

bool InterruptIn::read() {
    return HAL_GPIO_ReadPin(pin.port, pin.pin);
}
