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
    // pwm.set_duty_cycle(0.8);

    int id = 0;
    bool forward = true;

    while (true) {
        leds[id].toggle();
        HAL_Delay(100);
        leds[id].toggle();

        if (id == 3) {
            forward = false;
        } else if (id == 0) {
            forward = true;
        }
        id += forward ? 1 : -1;
    }
}
