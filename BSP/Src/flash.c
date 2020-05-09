#include "flash.h"

#define INT_FLASH_SIZE 0x
#define INT_FLASH_SECTOR_SIZE       0x1000        // 4 KBytes

// handles write process for multiple sectors
void flash_write_sectors() {

}

void flash_write_sector(uint32_t sector, unsigned char* buffer) {
  HAL_FLASH_Unlock();
  // This may not be correct
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
  FLASH_Erase_Sector(sector, VOLTAGE_RANGE_3);
  // get start of sector in flash address
  for (uint32_t address = sector * ) {
    HAL_FLASH_Program(TYPEPROGRAM_WORD, FlashAddress, data);
  }
  HAL_FLASH_Lock();
}

void flash_write() {

}

void flash_read() {

}
