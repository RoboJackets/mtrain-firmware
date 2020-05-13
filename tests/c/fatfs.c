#include "mtrain.h"
#include "ff.h"         /* Declarations of sector size */
#include "diskio.h"     /* Declarations of disk functions */
#include "ff_gen_drv.h"

FATFS FatFs; /* File system object for User logical drive */
DIR dir;
FIL File;
/* File object */
char mynewdiskPath[4]; /* User logical drive path */
extern Diskio_drvTypeDef qspi_flash_driver;


int main(void)
{
  HAL_Delay(3000);
  uint32_t wbytes; /* File write counts */
  uint8_t wtext[] = "text to write logical disk"; /* File write buffer */
  uint32_t rbytes; /* File write counts */
  uint8_t rtext[sizeof(wtext)];

  FRESULT status = FR_OK;


  /* if(FATFS_LinkDriver(&qspi_flash_driver, mynewdiskPath) != 0) */
  /* { */
  /* } */


  status = f_mount(&FatFs, "", 0);
  if( status != FR_OK)
  {
    printf("FS NOT Mounted\r\n");
    printf("Error: %u \r\n", status);
    return 1;
  }
  printf("FS Mounted\r\n");

  /* Format the default drive with default parameters */
  /* status = f_mkfs("", 0, _MAX_SS); */
  /* printf("FS Formatted\r\n"); */

  /* res = f_opendir(&dir, "/"); */
  /* if(res != FR_OK) { */
  /*   printf("f_opendir() failed, res = %d\r\n", res); */
  /*   return; */
  /* } */

  status = f_open(&File, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE);
  if( status != FR_OK)
  {
    printf("File NOT opened\r\n");
    printf("Error: %u \r\n", status);
    return 1;
  }
  printf("File opened\r\n");


  status = f_write(&File, wtext, sizeof(wtext), (void *)&wbytes);
  if( status != FR_OK)
  {
    printf("Text NOT written \r\n");
    printf("Error: %u \r\n", status);
    return 1;
  }
  printf("Text written \r\n");


  status = f_read(&File, rtext, sizeof(rtext), (void *)&rbytes);
  if( status != FR_OK)
  {
    printf("Text NOT read \r\n");
    printf("Error: %u \r\n", status);
    return 1;
  }
  printf("Text read \r\n");


  status = f_close(&File);
  if( status != FR_OK)
  {
    printf("File NOT closed \r\n");
    printf("Error: %u \r\n", status);
    return 1;
  }
  printf("File closed \r\n");

  FATFS_UnLinkDriver(mynewdiskPath);

  printf("text read during process %s\r\n", rtext);
}
