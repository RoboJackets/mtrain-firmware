#include "Delay.hpp"
#include "stm32f7xx_hal.h"

uint32_t Delay::DWT_GetTick() {
    volatile uint32_t curTick = DWT->CYCCNT;
    return curTick;
}

uint64_t Delay::DWT_SysTick_To_us() {
    volatile uint64_t ratio = SystemCoreClock/1000000L;
    return ratio;
}

void Delay::DWT_Delay_Sys(uint32_t ticks) {
    volatile uint32_t startTick = DWT->CYCCNT;
    do {} while (DWT->CYCCNT - startTick < ticks);
}

void Delay::DWT_Delay(uint32_t us) {
    volatile uint32_t delayTicks = us * (SystemCoreClock/1000000L);
    volatile uint32_t startTick = DWT->CYCCNT;

    do {} while (DWT->CYCCNT - startTick < delayTicks);
}