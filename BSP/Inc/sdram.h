
#ifndef MTRAIN_SDRAM_H
#define MTRAIN_SDRAM_H

#include "stm32f7xx_hal.h"
#include "stm32f7xx_ll_fmc.h"
#include "stm32f7xx_hal_sdram.h"

static FMC_SDRAM_CommandTypeDef Command;
static SDRAM_HandleTypeDef sdramHandle;
static FMC_SDRAM_TimingTypeDef Timing;
static HAL_SDRAM_StateTypeDef sdramState;
/*
 * Declare instances of SDRAM pins
 *
 */

/* Pin/Port Definitions */
#define SDRAM_SDCLK_PIN         GPIO_PIN_8
#define SDRAM_SDCLK_PORT        GPIOG
#define SDRAM_SDCKE_PIN         GPIO_PIN_2
#define SDRAM_SDCKE_PORT         GPIOH
#define SDRAM_SDNE_PIN          GPIO_PIN_3
#define SDRAM_SDNE_PORT         GPIOH
#define SDRAM_SDNCAS_PIN        GPIO_PIN_15
#define SDRAM_SDNCAS_PORT       GPIOG
#define SDRAM_SDNRAS_PIN        GPIO_PIN_11
#define SDRAM_SDNRAS_PORT       GPIOF
#define SDRAM_SDNWE_PIN         GPIO_PIN_5
#define SDRAM_SDNWE_PORT        GPIOH
#define SDRAM_LDQM_PIN          GPIO_PIN_0
#define SDRAM_LDQM_PORT         GPIOE
#define SDRAM_UDQM_PIN          GPIO_PIN_1
#define SDRAM_UDQM_PORT         GPIOE
#define SDRAM_BA0_PIN           GPIO_PIN_4
#define SDRAM_BA0_PORT          GPIOG
#define SDRAM_BA1_PIN           GPIO_PIN_5
#define SDRAM_BA1_PORT          GPIOG
#define SDRAM_A0_PIN            GPIO_PIN_0
#define SDRAM_A0_PORT           GPIOF
#define SDRAM_A1_PIN            GPIO_PIN_1
#define SDRAM_A1_PORT           GPIOF
#define SDRAM_A2_PIN            GPIO_PIN_2
#define SDRAM_A2_PORT           GPIOF
#define SDRAM_A3_PIN            GPIO_PIN_3
#define SDRAM_A3_PORT           GPIOF
#define SDRAM_A4_PIN            GPIO_PIN_4
#define SDRAM_A4_PORT           GPIOF
#define SDRAM_A5_PIN            GPIO_PIN_5
#define SDRAM_A5_PORT           GPIOF
#define SDRAM_A6_PIN            GPIO_PIN_12
#define SDRAM_A6_PORT           GPIOF
#define SDRAM_A7_PIN            GPIO_PIN_13
#define SDRAM_A7_PORT           GPIOF
#define SDRAM_A8_PIN            GPIO_PIN_14
#define SDRAM_A8_PORT           GPIOF
#define SDRAM_A9_PIN            GPIO_PIN_15
#define SDRAM_A9_PORT           GPIOF
#define SDRAM_A10_PIN           GPIO_PIN_0
#define SDRAM_A10_PORT          GPIOG
#define SDRAM_A11_PIN           GPIO_PIN_1
#define SDRAM_A11_PORT          GPIOG
#define SDRAM_A12_PIN           GPIO_PIN_2
#define SDRAM_A12_PORT          GPIOG
#define SDRAM_D0_PIN            GPIO_PIN_14
#define SDRAM_D0_PORT           GPIOD
#define SDRAM_D1_PIN            GPIO_PIN_15
#define SDRAM_D1_PORT           GPIOD
#define SDRAM_D2_PIN            GPIO_PIN_0
#define SDRAM_D2_PORT           GPIOD
#define SDRAM_D3_PIN            GPIO_PIN_1
#define SDRAM_D3_PORT           GPIOD
#define SDRAM_D4_PIN            GPIO_PIN_7
#define SDRAM_D4_PORT           GPIOE
#define SDRAM_D5_PIN            GPIO_PIN_8
#define SDRAM_D5_PORT           GPIOE
#define SDRAM_D6_PIN            GPIO_PIN_9
#define SDRAM_D6_PORT           GPIOE
#define SDRAM_D7_PIN            GPIO_PIN_10
#define SDRAM_D7_PORT           GPIOE
#define SDRAM_D8_PIN            GPIO_PIN_11
#define SDRAM_D8_PORT           GPIOE
#define SDRAM_D9_PIN            GPIO_PIN_12
#define SDRAM_D9_PORT           GPIOE
#define SDRAM_D10_PIN           GPIO_PIN_13
#define SDRAM_D10_PORT          GPIOE
#define SDRAM_D11_PIN           GPIO_PIN_14
#define SDRAM_D11_PORT          GPIOE
#define SDRAM_D12_PIN           GPIO_PIN_15
#define SDRAM_D12_PORT          GPIOE
#define SDRAM_D13_PIN           GPIO_PIN_8
#define SDRAM_D13_PORT          GPIOD
#define SDRAM_D14_PIN           GPIO_PIN_9
#define SDRAM_D14_PORT          GPIOD
#define SDRAM_D15_PIN           GPIO_PIN_10
#define SDRAM_D15_PORT          GPIOD






#endif //MTRAIN_SDRAM_H
