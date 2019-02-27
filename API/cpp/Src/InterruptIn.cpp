#include "InterruptIn.hpp"

InterruptFunction interrupt0 = NULL,
                  interrupt4 = NULL,
                  interrupt5 = NULL,
                  interrupt6 = NULL,
                  interrupt7 = NULL,
                  interrupt8 = NULL,
                  interrupt9 = NULL,
                  interrupt10 = NULL,
                  interrupt11 = NULL,
                  interrupt12 = NULL,
                  interrupt14 = NULL,
                  interrupt15 = NULL;

int interruptPriority = 10;
void NVICConfig(IRQn_Type IRQn) {
    HAL_NVIC_SetPriority(IRQn, interruptPriority, interruptPriority);
    HAL_NVIC_EnableIRQ(IRQn);
}

void InterruptConfig(uint16_t pin, InterruptFunction function) {
    if (pin == GPIO_PIN_0) {
        interrupt0 = function;
        NVICConfig(EXTI0_IRQn);
    } else if (pin == GPIO_PIN_4) {
        interrupt4 = function;
        NVICConfig(EXTI4_IRQn);
    } else if (pin == GPIO_PIN_5) {
        interrupt5 = function;
        NVICConfig(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_6) {
        interrupt6 = function;
        NVICConfig(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_7) {
        interrupt7 = function;
        NVICConfig(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_8) {
        interrupt8 = function;
        NVICConfig(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_9) {
        interrupt9 = function;
        NVICConfig(EXTI9_5_IRQn);
    } else if (pin == GPIO_PIN_10) {
        interrupt10 = function;
        NVICConfig(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_11) {
        interrupt11 = function;
        NVICConfig(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_12) {
        interrupt12 = function;
        NVICConfig(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_14) {
        interrupt14 = function;
        NVICConfig(EXTI15_10_IRQn);
    } else if (pin == GPIO_PIN_15) {
        interrupt15 = function;
        NVICConfig(EXTI15_10_IRQn);
    }
}
extern "C" {
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
}

InterruptIn::InterruptIn(PinName pin, InterruptFunction function, PullType pull,
    InterruptMode mode) : pin(pin), function(function) {
    GPIO_InitTypeDef pinStructure;
    pinStructure.Pin = pin.pin;
    pinStructure.Mode = mode;
    pinStructure.Pull = pull;

    HAL_GPIO_Init(pin.port, &pinStructure);
    InterruptConfig(pin.pin, function);
}
InterruptIn::~InterruptIn() {
    HAL_GPIO_DeInit(pin.port, pin.pin);
}

bool InterruptIn::read() {
    return HAL_GPIO_ReadPin(pin.port, pin.pin);
}
