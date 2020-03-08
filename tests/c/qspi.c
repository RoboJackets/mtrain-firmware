#include "mtrain.h"
#include "bsp.h"

int main(void)
{
  HAL_Delay(3000);
  printf("test write\r\n");
  uint8_t writeData[] = "hello world";
  uint32_t size = sizeof(writeData);
  uint8_t readData [size];

  uint32_t addr_min = 0x0;
  uint32_t addr_max = 0x1FFFFFF - size - 1;


  BSP_QSPI_Write(writeData, addr_min, size);
  BSP_QSPI_Read(readData, addr_min, size);

  printf("write data length should be %d\r\n", size);
  printf("written data was %s\r\n", (char*)writeData);
  printf("read data was %s\r\n", (char*)readData);
  // assert equals

  HAL_Delay(1000);

  BSP_QSPI_Write(writeData, addr_max, size);
  BSP_QSPI_Read(readData, addr_max, size);

  printf("write data length should be %d\r\n", size);
  printf("written data was %s\r\n", (char*)writeData);
  printf("read data was %s\r\n", (char*)readData);
  // assert equals

  HAL_Delay(3000);
  return 0;
}
