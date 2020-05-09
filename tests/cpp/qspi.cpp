#include "mtrain.hpp"
#include "qspi.h"

int main(void)
{
  HAL_Delay(3000);
  printf("test write\r\n");
  uint8_t writeData[] = "hello world";
  uint32_t size = sizeof(writeData);
  uint8_t readData [size];

  uint32_t addr = 0x0BB80;
  uint32_t blockAddr = 0x0;

  if (addr < FLASH_4K_SECTOR_MAX) {
    blockAddr = addr / FLASH_SUBSECTOR_SIZE;
  } else {
    blockAddr = ((addr - FLASH_4K_SECTOR_MAX) / FLASH_SECTOR_SIZE) + FLASH_SUBSECTOR_COUNT;
  }

  BSP_QSPI_Erase_Sector(blockAddr);
  BSP_QSPI_Write(writeData, addr, size);
  BSP_QSPI_Read(readData, addr, size);

  printf("write data length should be %d\r\n", sizeof(writeData));
  printf("written data was %s\r\n", (char*)writeData);
  printf("read data was %s\r\n", (char*)readData);

}
