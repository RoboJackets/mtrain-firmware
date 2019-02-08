#include "SPI.hpp"
#include "stm32f7xx_ll_spi.h"

// TODO: cleanup
SPI::SPI(SpiBus spiBus, int hz) {
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    switch (spiBus) {
        case SpiBus::SpiBus2:
            spiHandle.Instance = SPI2;

            __HAL_RCC_SPI2_CLK_ENABLE();

            // Configure SPI2 SCK
            GPIO_InitStruct.Pin       = GPIO_PIN_12;
            GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
            GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
            GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
            GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
            HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

            // Configure SPI2 MISO
            GPIO_InitStruct.Pin = GPIO_PIN_14;
            HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

            // Configure SPI2 MOSI
            GPIO_InitStruct.Pin = GPIO_PIN_15;
            HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

            HAL_NVIC_SetPriority(SPI2_IRQn, 1, 0);
            HAL_NVIC_EnableIRQ(SPI2_IRQn);
            break;
        case SpiBus::SpiBus3:
            spiHandle.Instance = SPI3;
            break;
        case SpiBus::SpiBus5:
            spiHandle.Instance = SPI5;

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

            HAL_NVIC_SetPriority(SPI5_IRQn, 1, 0);
            HAL_NVIC_EnableIRQ(SPI5_IRQn);
            break;
        default:
            break;
    }

    int prescale = fPCLK/hz;
    for (int i = 1; i <= 8; i++) {
        if (prescale <= 1 << i) {
            // TODO: is this correct?
            spiHandle.Init.BaudRatePrescaler = i << 3;
            break;
        }
    }

    spiHandle.Init.Mode              = SPI_MODE_MASTER; // Be able to specify
    spiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
    spiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
    spiHandle.Init.CLKPolarity       = SPI_POLARITY_LOW;
    spiHandle.Init.CLKPhase          = SPI_PHASE_1EDGE;
    spiHandle.Init.NSS               = SPI_NSS_SOFT;
    // TODO: remove below line
    spiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
    spiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB; // Be able to specify?
    spiHandle.Init.TIMode            = SPI_TIMODE_DISABLE;
    spiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
    spiHandle.Init.CRCPolynomial     = 7;

    HAL_SPI_Init(&spiHandle);
}

void SPI::frequency(int hz) {
    int prescale = fPCLK/hz;
    for (int i = 1; i <= 8; i++) {
        if (prescale <= 1 << i) {
            // TODO: is this correct?
            LL_SPI_SetBaudRatePrescaler(spiHandle.Instance, i << 3);
            return;
        }
    }
}

uint8_t SPI::transmit(uint8_t data) {
    LL_SPI_Enable(spiHandle.Instance);
    /* Wait for TX queue to empty */
    while (!LL_SPI_IsActiveFlag_TXE(spiHandle.Instance)) { }
    LL_SPI_TransmitData8(spiHandle.Instance, data);
    /* Wait for RX queue to fill */
    while (!LL_SPI_IsActiveFlag_RXNE(spiHandle.Instance)) { }
    return LL_SPI_ReceiveData8(spiHandle.Instance);
}

std::vector<uint8_t> SPI::transmit(std::vector<uint8_t>& data) {
    int size = data.size();
    std::vector<uint8_t> dataOut(size);
    LL_SPI_Enable(spiHandle.Instance);

    int pos = 0;
    while (pos < size) {
        if (LL_SPI_GetTxFIFOLevel(spiHandle.Instance) < 3 &&
                LL_SPI_GetRxFIFOLevel(spiHandle.Instance) < 3) {
            LL_SPI_TransmitData8(spiHandle.Instance, data[pos]);
            pos++;
        }

        if (LL_SPI_IsActiveFlag_RXNE(spiHandle.Instance)) {
            dataOut[pos] = LL_SPI_ReceiveData8(spiHandle.Instance);
        }
    }

    return dataOut;
}

// TODO: don't think this links correctly
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance == SPI2) {
        // TODO: needed?
        __HAL_RCC_SPI2_FORCE_RESET();
        __HAL_RCC_SPI2_RELEASE_RESET();

        // Deconfigure SPI2 SCK
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_12);
        // Deconfigure SPI2 MISO
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_14);
        // Deconfigure SPI2 MOSI
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_15);
    }
}