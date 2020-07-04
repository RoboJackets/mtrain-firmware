
#ifndef MTRAIN_SDRAM_H
#define MTRAIN_SDRAM_H

#include "stm32f7xx_hal.h"
#include "stm32f7xx_ll_fmc.h"
#include "stm32f7xx_hal_sdram.h"

static FMC_SDRAM_CommandTypeDef Command = {};
static SDRAM_HandleTypeDef sdramHandle = {};
static FMC_SDRAM_TimingTypeDef Timing = {};
static HAL_SDRAM_StateTypeDef sdramState = {};


// Will need to be isolated from this filed when we move to mjackets api
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
    /** FMC GPIO Configuration
        PE1   ------> FMC_NBL1
        PE0   ------> FMC_NBL0
        PG15   ------> FMC_SDNCAS
        PD0   ------> FMC_D2
        PD1   ------> FMC_D3
        PF0   ------> FMC_A0
        PF1   ------> FMC_A1
        PF2   ------> FMC_A2
        PF3   ------> FMC_A3
        PG8   ------> FMC_SDCLK
        PF4   ------> FMC_A4
        PH5   ------> FMC_SDNWE
        PH3   ------> FMC_SDNE0
        PF5   ------> FMC_A5
        PH2   ------> FMC_SDCKE0
        PD15   ------> FMC_D1
        PD10   ------> FMC_D15
        PD14   ------> FMC_D0
        PD9   ------> FMC_D14
        PD8   ------> FMC_D13
        PF12   ------> FMC_A6
        PG1   ------> FMC_A11
        PF15   ------> FMC_A9
        PG2   ------> FMC_A12
        PF13   ------> FMC_A7
        PG0   ------> FMC_A10
        PE8   ------> FMC_D5
        PG5   ------> FMC_BA1
        PG4   ------> FMC_BA0
        PF14   ------> FMC_A8
        PF11   ------> FMC_SDNRAS
        PE9   ------> FMC_D6
        PE11   ------> FMC_D8
        PE14   ------> FMC_D11
        PE7   ------> FMC_D4
        PE10   ------> FMC_D7
        PE12   ------> FMC_D9
        PE15   ------> FMC_D12
        PE13   ------> FMC_D10
    */


#define REFRESH_COUNT                    ((uint32_t)0x0672)   /* SDRAM refresh counter (108Mhz SD clock) */
/**
 * @brief  MT48LC16M16A2 Mode Register Defines
 */
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)


uint8_t BSP_SDRAM_Init(void);
void BSP_SDRAM_MspInit(void);
void BSP_SDRAM_Init_Sequence(void);
static void HAL_FMC_MspDeInit(void);


#endif //MTRAIN_SDRAM_H
