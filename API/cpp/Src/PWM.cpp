#include <PWM.hpp>


/**
  * @brief TIM5 Initialization Function
  * @param None
  * @retval None
  */
PWM::PWM(PWMParams params) {
    this->params = params;

    htim.Instance = params.timer;
    htim.Init.Prescaler = 1080;
    htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim.Init.Period = 2000; // difference between pulse width and this determines duty cycles. Means the maximum pulse is 2000 as well
    htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    if (HAL_TIM_PWM_Init(&htim) != HAL_OK) // Call to hal cals MspInit
    {
        Error_Handler();
    }

    GPIO_Init(params.pin_name, &htim);

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }


    // TODO replace this section with a call to set duty cycle
    sConfigOC.OCMode = TIM_OCMODE_PWM1; // TODO CHECK THIS LINE AS THIS MAY BE THE WRONG OUTPUT
    sConfigOC.Pulse = static_cast<uint32_t>(params.duty_cycle * htim.Init.Period);
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    if (HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, params.channel) != HAL_OK)
    {
        Error_Handler();
    }

    // Do we want this to start on init?
    HAL_TIM_PWM_Start(&htim, params.channel);

}


PWM::~PWM() {
    if (HAL_TIM_PWM_DeInit(&htim) != HAL_OK) {
        Error_Handler();
    }
}

void PWM::set_duty_cycle(float duty_cycle) {
    HAL_TIM_PWM_Stop(&htim, params.channel);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;// TODO CHECK THIS LINE AS THIS MAY BE THE WRONG OUTPUT
    sConfigOC.Pulse = static_cast<uint32_t>(duty_cycle * htim.Init.Period);
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    if (HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, params.channel) != HAL_OK)
    {
        Error_Handler();
    }

    HAL_TIM_PWM_Start(&htim, params.channel);

}

void PWM::GPIO_Init(PinName pin, TIM_HandleTypeDef* htim) {
    // Example code usually does gpio clock init here but the bsp file just does starts all of htem at once
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = pin.pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    if (pin.port == GPIOA) {
        switch (pin.pin) {
        case 8:
            GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
            break;

        case 11:
            GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
            break;

        case 6:
            if(htim->Instance==TIM3) {
                GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF9_TIM13;
            }
            break;
        }
    } else if (pin.port == GPIOB) {
        switch (pin.pin) {
        case 15:
            if(htim->Instance==TIM1) {
                GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
            } else if (htim->Instance==TIM8) {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF9_TIM12;
            }
            break;

        case 14:
            if(htim->Instance==TIM1) {
                GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
            } else if (htim->Instance==TIM8) {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF9_TIM12;
            }
            break;

        case 9:
            if(htim->Instance==TIM4) {
                GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM11;
            }
            break;

        case 8:
            if(htim->Instance==TIM4) {
                GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM10;
            }
            break;

        case 6:
            GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
            break;

        case 7:
            GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
            break;

        case 4:
            GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
            break;

        }
    } else if (pin.port == GPIOC) {
        switch (pin.pin) {
        case 6:
            if(htim->Instance==TIM3) {
                GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
            }
            break;

        case 7:
            if(htim->Instance==TIM3) {
                GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
            }
            break;
        case 8:
            if(htim->Instance==TIM3) {
                GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
            }
            break;
        case 9:
            if(htim->Instance==TIM3) {
                GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
            } else {
                GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
            }
            break;
        }

    } else if (pin.port == GPIOF) {
        switch (pin.pin) {
        case 9:
            GPIO_InitStruct.Alternate = GPIO_AF9_TIM14;
            break;
        case 8:
            GPIO_InitStruct.Alternate = GPIO_AF9_TIM13;
            break;
        case 7:
            GPIO_InitStruct.Alternate = GPIO_AF3_TIM11;
            break;
        case 6:
            GPIO_InitStruct.Alternate = GPIO_AF3_TIM10;
            break;
        }
    } else if (pin.port == GPIOH) {
        switch (pin.pin) {
        case 10:
            GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
            break;
        case 11:
            GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
            break;
        case 12:
            GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
            break;
        }
    } else if (pin.port == GPIOI) {
        if (pin.pin == 0) {
            GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
        }
    }


    HAL_GPIO_Init(pin.port, &GPIO_InitStruct);
}


/**
* @brief TIM_PWM MSP Initialization
* Called as part of HAL_TIM_PWM_Init(&htim)
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
    if (htim_pwm->Instance == TIM1) {
        __HAL_RCC_TIM1_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM2) {
        __HAL_RCC_TIM2_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM3) {
        __HAL_RCC_TIM3_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM4) {
        __HAL_RCC_TIM4_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM5) {
        __HAL_RCC_TIM5_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM6) {
        __HAL_RCC_TIM6_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM7) {
        __HAL_RCC_TIM7_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM8) {
        __HAL_RCC_TIM8_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM9) {
        __HAL_RCC_TIM9_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM10) {
        __HAL_RCC_TIM10_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM11) {
        __HAL_RCC_TIM11_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM12) {
        __HAL_RCC_TIM12_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM13) {
        __HAL_RCC_TIM13_CLK_ENABLE();
    } else if (htim_pwm->Instance == TIM14) {
        __HAL_RCC_TIM14_CLK_ENABLE();
    }
}


/**
* @brief TIM_PWM MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* htim_pwm) {
    if (htim_pwm->Instance == TIM1) {
        __HAL_RCC_TIM1_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM2) {
        __HAL_RCC_TIM2_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM3) {
        __HAL_RCC_TIM3_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM4) {
        __HAL_RCC_TIM4_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM5) {
        __HAL_RCC_TIM5_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM6) {
        __HAL_RCC_TIM6_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM7) {
        __HAL_RCC_TIM7_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM8) {
        __HAL_RCC_TIM8_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM9) {
        __HAL_RCC_TIM9_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM10) {
        __HAL_RCC_TIM10_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM11) {
        __HAL_RCC_TIM11_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM12) {
        __HAL_RCC_TIM12_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM13) {
        __HAL_RCC_TIM13_CLK_DISABLE();
    } else if (htim_pwm->Instance == TIM14) {
        __HAL_RCC_TIM14_CLK_DISABLE();
    }
}


void PWM::Error_Handler() {

}
