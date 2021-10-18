#pragma once

#include  <unistd.h>

class Delay {
    public:
        /** Current tick in sysclock ticks
         * @return current tick
         */
        uint32_t DWT_GetTick();
        /**
         *
         * @return
         */
        uint64_t DWT_SysTick_To_us();
        /** Delay routine
         *
         * @param ticks Number of clock cycles to delay for
         */
        void DWT_Delay_Sys(uint32_t ticks);
        /**
         * Delay routine itself.
         * Time is in microseconds (1/1000000th of a second), not to be
         * confused with millisecond (1/1000th).
         *
         * No need to check an overflow. Let it just tick :)
         *
         * @param uint32_t us  Number of microseconds to delay for
         */
        void static DWT_Delay(uint32_t us);
};

