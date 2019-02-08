#include "SPI.hpp"
#include "mtrain.hpp"
#include <vector>

int main(void) {
    SPI spi2(SpiBus5);

    for (int i = 1; i <= 100; i++) {
        spi2.transmit(i);
    }

    HAL_Delay(100);

    std::vector<uint8_t> nums;
    for (int i = 1; i <= 100; i++) {
        nums.push_back(i);
    }
    spi2.transmit(nums);

}