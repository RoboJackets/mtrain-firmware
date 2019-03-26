#pragma once

#include "PinDefs.hpp"

#include <vector>
#include <optional>

typedef enum SpiBus {
    SpiBus2,
    SpiBus3,
    SpiBus5,
} SpiBus;

// typedef enum SpiPrescale {
//     SpiPrescale2 = SPI_BAUDRATEPRESCALER_2,
//     SpiPrescale4 = SPI_BAUDRATEPRESCALER_4,
//     SpiPrescale8 = SPI_BAUDRATEPRESCALER_8,
//     SpiPrescale16 = SPI_BAUDRATEPRESCALER_16,
//     SpiPrescale32 = SPI_BAUDRATEPRESCALER_32,
//     SpiPrescale64 = SPI_BAUDRATEPRESCALER_64,
//     SpiPrescale128 = SPI_BAUDRATEPRESCALER_128,
//     SpiPrescale256 = SPI_BAUDRATEPRESCALER_256,
// } SpiPrescale;

constexpr int fPCLK = 108'000'000; // Hz

class SPI {
public:
    SPI(SpiBus spiBus, std::optional<PinName> cs = std::nullopt, int hz = 1'000'000);
    ~SPI();

    void format(int bits, int mode = 0);
    // TODO: make more clear is is set in steps
    void frequency(int hz);

    void transmit(uint8_t data);
    void transmit(std::vector<uint8_t>& data);

    void transmitDMA(std::vector<uint8_t>& data);

    uint8_t transmitReceive(uint8_t data);
    std::vector<uint8_t> transmitReceive(std::vector<uint8_t>& data);

private:
    SPI_HandleTypeDef spiHandle;
    std::optional<PinName> chipSelect;
};

void SPI_Init(SpiBus spiBus, PinName chipSelect, int hz);
uint8_t transmitReceive(uint8_t data, PinName chipSelect, SPI_TypeDef* spiInstance);