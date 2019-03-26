

#include "pin_defs.h"
#include "stm32f7xx_ll_spi.h"

// typedef enum SpiBus {
//     SpiBus2,
//     SpiBus3,
//     SpiBus5,
// } SpiBus;

// #define fPCLK 108000000


int main() {
    // int i = 0;


    GPIO_InitTypeDef  GPIO_InitStruct;
    // SPI_HandleTypeDef spiHandle;
    // SpiBus spiBus = SpiBus5;
    pin_name chipSelect = PIN26;

    // CS
    GPIO_InitStruct.Pin = chipSelect.pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    
    HAL_GPIO_Init(chipSelect.port, &GPIO_InitStruct);
    HAL_GPIO_WritePin(chipSelect.port, chipSelect.pin, (GPIO_PinState)1);
    
    // spiHandle.Instance = SPI5;

    __HAL_RCC_SPI5_CLK_ENABLE();

    // Configure SPI5 SCK
    GPIO_InitStruct.Pin       = GPIO_PIN_7;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI5;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    // Configure SPI5 MISO
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    // Configure SPI5 MOSI
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    // HAL_NVIC_SetPriority(SPI5_IRQn, 1, 0);
    // HAL_NVIC_EnableIRQ(SPI5_IRQn);

    // spiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;

    // spiHandle.Init.Mode              = SPI_MODE_MASTER; // Be able to specify
    // spiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
    // spiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
    // spiHandle.Init.CLKPolarity       = SPI_POLARITY_LOW;
    // spiHandle.Init.CLKPhase          = SPI_PHASE_1EDGE;
    // spiHandle.Init.NSS               = SPI_NSS_SOFT;
    // spiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB; // Be able to specify?
    // spiHandle.Init.TIMode            = SPI_TIMODE_DISABLE;
    // spiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
    // spiHandle.Init.CRCPolynomial     = 7;

    // HAL_SPI_Init(&spiHandle);

    // Disable SPI
    SPI5->CR1 &= (~SPI_CR1_SPE);
    SPI5->CR1 = (SPI_MODE_MASTER | SPI_DIRECTION_2LINES | SPI_POLARITY_LOW |
                 SPI_PHASE_1EDGE | SPI_BAUDRATEPRESCALER_128 | SPI_FIRSTBIT_MSB |
                 SPI_CRCCALCULATION_DISABLE);
    // SPI5->CR1 |= SPI_CR1_CRCL;
    SPI5->CR2 = (((SPI_NSS_SOFT >> 16) & SPI_CR2_SSOE) | SPI_TIMODE_DISABLE | SPI_DATASIZE_8BIT | SPI_RXFIFO_THRESHOLD_QF);
    CLEAR_BIT(SPI5->I2SCFGR, SPI_I2SCFGR_I2SMOD);
    

    uint8_t data = 10;


    // // if (chipSelect) {
        HAL_GPIO_WritePin(chipSelect.port, chipSelect.pin, (GPIO_PinState)0);
    // // }

    // // HAL_SPI_Transmit(&spiHandle, &data, 1, 10);
    // // while(HAL_SPI_GetState(&spiHandle) != HAL_SPI_STATE_READY);

    SPI5->CR1 |= SPI_CR1_SPE;

    /* Wait for TX queue to empty */
    // while (READ_BIT(spiHandle.Instance->SR, SPI_SR_TXE) == 0) {}
    while (SPI5->SR & SPI_SR_TXE == 0) {}
    *(__IO uint8_t *)&SPI5->DR = data;
    /* Wait for RX queue to fill */
    // while (!LL_SPI_IsActiveFlag_RXNE(spiHandle.Instance)) { }
    while (SPI5->SR & SPI_SR_RXNE != 0) { }
    uint8_t recievedData = SPI5->DR;

    // // if (chipSelect) {
        HAL_GPIO_WritePin(chipSelect.port, chipSelect.pin, (GPIO_PinState)1);
    // }
    // return recievedData;

    uint32_t ii = 0;
    uint64_t iii = 0;
    uint64_t iiii = 0;
    uint64_t iiiii = 0;
    uint64_t iiiiii = 0;
    // uint64_t iiiiiii = 0;
    // uint64_t iiiiiiii = 0;
    // uint64_t iiiiiiiii = 0;
    // uint64_t iiiiiiiiii = 0;

    while(1) {

    }

}
