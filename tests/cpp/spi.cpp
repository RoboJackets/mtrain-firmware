#include "SPI.hpp"
#include "mtrain.hpp"
#include <vector>

#include "stm32f7xx_ll_spi.h"


int main(void) {
    // SCB_DisableICache();
    // SCB_DisableDCache();
    {
        // SCB_CleanDCache();
        SPI spi2(SpiBus5, p26, 2'000'000);
        // SCB_CleanDCache();

        int i = 0;
        for (int i = 0; i <= 100; i++) {
            spi2.transmitReceive(i);
        }

        // SPI_Init(SpiBus5, p26, 2'000'000);
        // transmitReceive(10, p26, SPI5);
        
        spi2.frequency(8'000'000);

        std::vector<uint8_t> nums;
        for (int i = 1; i <= 100; i++) {
            nums.push_back(i);
        }
        spi2.transmitReceive(nums);
        
        // HAL_Delay(1);

        spi2.frequency(1);
        for (uint8_t i = 0; i <= 100; i++) {
            spi2.transmit(i);
        }

        spi2.frequency(15'000'000);
        spi2.transmit(nums);
    }

    uint64_t unused64 = 0;
    uint32_t unused32 = 0;
    // //                                 // e0
    uint64_t unused1 = 11;          // none
    uint64_t unused2 = 11;          // e0
    uint64_t unused3 = 11;          // none
    uint64_t unused4 = 11;          // none
    // uint64_t unused5 = 11;          // e0
    // uint64_t unused6 = 11;          // e0
    // uint64_t unused7 = 11;          // none
    // uint64_t unused8 = 11;          // e0
    // uint64_t unused9 = 11;          // none
    // uint64_t unused10 = 11;         // e0
    // uint64_t unused11 = 11;         // none
    // uint64_t unused12 = 11;         // e1
    // uint64_t unused13 = 11;         // none
    // uint64_t unused14 = 11;         // none
    // uint64_t unused15 = 11;         // none
    while (true) { }
}


// extern "C" {

// int main() {
//     // int i = 0;


//     GPIO_InitTypeDef  GPIO_InitStruct;
//     SPI_HandleTypeDef spiHandle;
//     SpiBus spiBus = SpiBus5;
//     PinName chipSelect = p26;
//     int hz = 2'000'000;

//     // if (chipSelect) {
//         GPIO_InitStruct.Pin = chipSelect.pin;
//         GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//         GPIO_InitStruct.Pull = GPIO_NOPULL;
//         GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        
//         HAL_GPIO_Init(chipSelect.port, &GPIO_InitStruct);
//         HAL_GPIO_WritePin(chipSelect.port, chipSelect.pin, (GPIO_PinState)1);
//     // }
    
//     switch (spiBus) {
//         case SpiBus::SpiBus2:
//             spiHandle.Instance = SPI2;

//             __HAL_RCC_SPI2_CLK_ENABLE();

//             // Configure SPI2 SCK
//             GPIO_InitStruct.Pin       = GPIO_PIN_12;
//             GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
//             GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
//             GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
//             GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
//             HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//             // Configure SPI2 MISO
//             GPIO_InitStruct.Pin = GPIO_PIN_14;
//             HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//             // Configure SPI2 MOSI
//             GPIO_InitStruct.Pin = GPIO_PIN_15;
//             HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//             HAL_NVIC_SetPriority(SPI2_IRQn, 1, 0);
//             HAL_NVIC_EnableIRQ(SPI2_IRQn);
//             break;
//         case SpiBus::SpiBus3:
//             spiHandle.Instance = SPI3;
//             break;
//         case SpiBus::SpiBus5:
//             spiHandle.Instance = SPI5;

//             __HAL_RCC_SPI5_CLK_ENABLE();

//             // Configure SPI5 SCK
//             GPIO_InitStruct.Pin       = GPIO_PIN_7;
//             GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
//             GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
//             GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
//             GPIO_InitStruct.Alternate = GPIO_AF5_SPI5;
//             HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

//             // Configure SPI5 MISO
//             GPIO_InitStruct.Pin = GPIO_PIN_8;
//             HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

//             // Configure SPI5 MOSI
//             GPIO_InitStruct.Pin = GPIO_PIN_9;
//             HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

//             HAL_NVIC_SetPriority(SPI5_IRQn, 1, 0);
//             HAL_NVIC_EnableIRQ(SPI5_IRQn);
//             break;
//         default:
//             break;
//     }

//     spiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
//     // TODO: repeated code
//     int prescale = fPCLK/hz;
//     for (int i = 1; i <= 8; i++) {
//         if (prescale <= 1 << i) {
//             spiHandle.Init.BaudRatePrescaler = (i-1) << 3;
//             break;
//         }
//     }

//     spiHandle.Init.Mode              = SPI_MODE_MASTER; // Be able to specify
//     spiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
//     spiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
//     spiHandle.Init.CLKPolarity       = SPI_POLARITY_LOW;
//     spiHandle.Init.CLKPhase          = SPI_PHASE_1EDGE;
//     spiHandle.Init.NSS               = SPI_NSS_SOFT;
//     spiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB; // Be able to specify?
//     spiHandle.Init.TIMode            = SPI_TIMODE_DISABLE;
//     spiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
//     spiHandle.Init.CRCPolynomial     = 7;

//     HAL_SPI_Init(&spiHandle);


//     uint8_t data = 10;


//     // if (chipSelect) {
//         HAL_GPIO_WritePin(chipSelect.port, chipSelect.pin, (GPIO_PinState)0);
//     // }

//     SPI5->CR1 |= SPI_CR1_SPE;

//     /* Wait for TX queue to empty */
//     while (READ_BIT(spiHandle.Instance->SR, SPI_SR_TXE) == 0) {}
//     *(__IO uint8_t *)&spiHandle.Instance->DR = data;
//     /* Wait for RX queue to fill */
//     while (!LL_SPI_IsActiveFlag_RXNE(spiHandle.Instance)) { }
//     uint8_t recievedData = spiHandle.Instance->DR;

//     // if (chipSelect) {
//         HAL_GPIO_WritePin(chipSelect.port, chipSelect.pin, (GPIO_PinState)1);
//     // }
//     return recievedData;
// }

// }