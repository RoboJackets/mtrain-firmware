#include "interrupt_in.h"

void (*interrupt0)() = NULL;
void (*interrupt4)() = NULL;
void (*interrupt5)() = NULL;
void (*interrupt6)() = NULL;
void (*interrupt7)() = NULL;
void (*interrupt8)() = NULL;
void (*interrupt9)() = NULL;
void (*interrupt10)() = NULL;
void (*interrupt11)() = NULL;
void (*interrupt12)() = NULL;
void (*interrupt13)() = NULL;
void (*interrupt14)() = NULL;
void (*interrupt15)() = NULL;

void interruptin_init(pin_name pin, void (*function)()) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = GPIO_MODE_IT_RISING;
    pin_structure.Pull = GPIO_NOPULL;
    
    HAL_GPIO_Init(pin.port, &pin_structure);
    interrupt_config(pin.pin, function);
}

void interruptin_init_ex(pin_name pin, pull_type pull, interrupt_mode mode,
    void (*function)()) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = mode;
    pin_structure.Pull = pull;
    
    HAL_GPIO_Init(pin.port, &pin_structure);
    interrupt_config(pin.pin, function);
}

void interruptin_deinit(pin_name pin) {
    HAL_GPIO_DeInit(pin.port, pin.pin);
}

int digitalin_read(pin_name pin) {
    return HAL_GPIO_ReadPin(pin.port, pin.pin);
}

void interrupt_config(uint16_t pin, void (*function)()) {
    if (pin == GPIO_PIN_0) {
        interrupt0 = function;
        HAL_NVIC_SetPriority(EXTI0_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    } else if (pin == GPIO_PIN_4) {
        interrupt4 = function;
        HAL_NVIC_SetPriority(EXTI4_IRQn, 10, 10);
        HAL_NVIC_EnableIRQ(EXTI4_IRQn);
    }
}

void EXTI0_IRQHandler(void)
{
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET) { // Handles A0 (31)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
      (interrupt0)();
    }
}

void EXTI4_IRQHandler(void)
{
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_4) != RESET) { // Handles B4 (35)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_4);
      (interrupt4)();
    }
}

void EXTI9_5_IRQHandler(void)
{
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_5) != RESET) { // Handles D5 (16)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_5);
      (interrupt5)();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_6) != RESET) { // Handles F6 (30)
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);
        (interrupt6)();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_7) != RESET) { // Handles D7 (18)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_7);
      (interrupt7)();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_8) != RESET) { // Handles D8 (20)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_8);
      (interrupt8)();
    } else if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_9) != RESET) { // Handles C9 (11)
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_9);
      (interrupt9)();
    }
}

void EXTI15_10_IRQHandler(void)
{
    //Handle C10 (34)
    //Handle H11 (13)
    //Handle C12 (36)
    //Handle B14 (5)
    //Handle B15 (4)
}
