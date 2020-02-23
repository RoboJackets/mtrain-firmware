#include <stdio.h>
#include <string.h>
/* #include "ff.h"         /\* Declarations of sector size *\/ */
/* #include "diskio.h"     /\* Declarations of disk functions *\/ */
#include "ff_gen_drv.h"
#include "mynewdisk_diskio.h"

FATFS mynewdiskFatFs; /* File system object for User logical drive */
FIL MyFile;
/* File object */
char mynewdiskPath[4]; /* User logical drive path */

int main(void)
{
  uint32_t wbytes; /* File write counts */
  uint8_t wtext[] = "text to write logical disk"; /* File write buffer */

  if(FATFS_LinkDriver(&qspi_flash_driver, mynewdiskPath) == 0)
    {
      if(f_mount(&mynewdiskFatFs, (TCHAR const*)mynewdiskPath, 0) == FR_OK)
        {
          if(f_open(&MyFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
            {
              if(f_write(&MyFile, wtext, sizeof(wtext), (void *)&wbytes) == FR_OK);
              {
                f_close(&MyFile);
              }
            }
        }
    }
  FATFS_UnLinkDriver(mynewdiskPath);
}
