#include <PWM.hpp>


/**
  * @brief TIM5 Initialization Function
  * @param None
  * @retval None
  */
PWM::PWM() {

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  TIM_HandleTypeDef htim5;

  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 1080;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 2000-1; // difference between pulse width and this determines duty cycles. Means the maximum pulse is 2000 as well
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim5) != HAL_OK) // Call to hal cals MspInit
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_TIM_MspPostInit(&htim5);

}



void PWM::GPIO_Init(TIM_HandleTypeDef* htim) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(htim->Instance==TIM5) {
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }
}


/**
* @brief TIM_PWM MSP Initialization
* Called as part of HAL_TIM_PWM_Init(&htim)
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
  switch (htim_pwm->Instance) {
  case TIM1 :
    __HAL_RCC_TIM1_CLK_ENABLE();
    break;
  case TIM2 :
    __HAL_RCC_TIM2_CLK_ENABLE();
    break;
  case TIM3 :
    __HAL_RCC_TIM3_CLK_ENABLE();
    break;
  case TIM4 :
    __HAL_RCC_TIM4_CLK_ENABLE();
    break;
  case TIM5 :
    __HAL_RCC_TIM5_CLK_ENABLE();
    break;
  case TIM6 :
    __HAL_RCC_TIM6_CLK_ENABLE();
    break;
  case TIM7 :
    __HAL_RCC_TIM7_CLK_ENABLE();
    break;
  case TIM8 :
    __HAL_RCC_TIM8_CLK_ENABLE();
    break;
  case TIM9 :
    __HAL_RCC_TIM9_CLK_ENABLE();
    break;
  case TIM10 :
    __HAL_RCC_TIM10_CLK_ENABLE();
    break;
  case TIM11 :
    __HAL_RCC_TIM11_CLK_ENABLE();
    break;
  case TIM12 :
    __HAL_RCC_TIM12_CLK_ENABLE();
    break;
  case TIM13 :
    __HAL_RCC_TIM13_CLK_ENABLE();
    break;
  case TIM14 :
    __HAL_RCC_TIM14_CLK_ENABLE();
    break;
  }

}


/**
* @brief TIM_PWM MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* htim_pwm) {
  switch (htim_pwm->Instance) {
  case TIM1 :
    __HAL_RCC_TIM1_CLK_DISABLE();
    break;
  case TIM2 :
    __HAL_RCC_TIM2_CLK_DISABLE();
    break;
  case TIM3 :
    __HAL_RCC_TIM3_CLK_DISABLE();
    break;
  case TIM4 :
    __HAL_RCC_TIM4_CLK_DISABLE();
    break;
  case TIM5 :
    __HAL_RCC_TIM5_CLK_DISABLE();
    break;
  case TIM6 :
    __HAL_RCC_TIM6_CLK_DISABLE();
    break;
  case TIM7 :
    __HAL_RCC_TIM7_CLK_DISABLE();
    break;
  case TIM8 :
    __HAL_RCC_TIM8_CLK_DISABLE();
    break;
  case TIM9 :
    __HAL_RCC_TIM9_CLK_DISABLE();
    break;
  case TIM10 :
    __HAL_RCC_TIM10_CLK_DISABLE();
    break;
  case TIM11 :
    __HAL_RCC_TIM11_CLK_DISABLE();
    break;
  case TIM12 :
    __HAL_RCC_TIM12_CLK_DISABLE();
    break;
  case TIM13 :
    __HAL_RCC_TIM13_CLK_DISABLE();
    break;
  case TIM14 :
    __HAL_RCC_TIM14_CLK_DISABLE();
    break;
  }

}
