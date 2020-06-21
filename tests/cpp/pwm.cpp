#include "mtrain.hpp"
#include "PWM.hpp"

/**
 * Blink LEDs back and forth
 */
int main(void)
{
    DigitalOut leds[] = {(LED1), (LED2), (LED3), (LED4)};

    PWMParams params = {p31, TIM5, TIM_CHANNEL_1, 0.5};

    PWM pwm(params);

    while (true) {
        leds[0].toggle();
        HAL_Delay(100);
        leds[0].toggle();
        HAL_Delay(100000);
        pwm.set_duty_cycle(0.8);
    }
}
