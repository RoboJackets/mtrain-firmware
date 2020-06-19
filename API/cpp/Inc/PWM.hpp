#pragma once

#include "PinDefs.hpp"

class PWM {
    private:
        PWMParams params;
        TIM_HandleTypeDef htim;
        TIM_MasterConfigTypeDef sMasterConfig;
        TIM_OC_InitTypeDef sConfigOC;

    public:
        PWM(PWMParams params);
        ~PWM();

        void set_duty_cycle(float duty_cycle);
        void GPIO_Init(PinName pin, TIM_HandleTypeDef* htim);
        void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm);
        void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* htim_pwm);
        void Error_Handler();
};
