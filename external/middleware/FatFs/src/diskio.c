/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "ff_gen_drv.h"
#include "qspi.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern unsigned char* RamDisk;
extern Disk_drvTypeDef  disk;
// TODO Global status var
static volatile DSTATUS stat = STA_NOINIT;

/* Private function prototypes -----------------------------------------------*/


const Diskio_drvTypeDef  ram_driver =
  {
    disk_initialize,
    disk_status,
    disk_read,
#if  _USE_WRITE == 1
    disk_write,
#endif /* _USE_WRITE == 1 */

#if  _USE_IOCTL == 1
    disk_ioctl,
#endif /* _USE_IOCTL == 1 */
  };



/* Private functions ---------------------------------------------------------*/



/**
  * @brief  Gets Disk Status
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
  stat = STA_NOINIT;

  if (pdrv){
    return stat;		/* Supports only drive 0 */
  }

  stat &= ~STA_NOINIT;

  return stat;
}

/**
  * @brief  Initializes a Drive
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
  stat = STA_NOINIT;

  // fail
  if (pdrv){
    return stat;		/* Supports only drive 0 */
  }

  if (!RamDisk){
    return stat;		/* if memory was not allocated for the ramdisk */
  }

  // success
  stat &= ~STA_NOINIT;
  return stat;
}

/**
  * @brief  Reads Sector(s)
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data buffer to store read data
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to read (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	        /* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
  DRESULT res = RES_OK;

  if (pdrv) {
    return RES_PARERR;
  }
  // TODO param check for oversize


  BYTE* addr = (sector * RAM_SECTOR_SIZE) + RamDisk;
  uint32_t size = count * RAM_SECTOR_SIZE;
  memcpy(buff, addr, size);

  res = RES_ERROR;

  return res;
}

/**
  * @brief  Writes Sector(s)
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  */
#if _USE_WRITE == 1
DRESULT disk_write (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
  BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count        	/* Number of sectors to write */
)
{
  DRESULT res = RES_OK;

  if (pdrv) {
    return RES_PARERR;
  }
  // TODO param check for oversize


  BYTE* addr = (sector * RAM_SECTOR_SIZE) + RamDisk;
  uint32_t size = count * RAM_SECTOR_SIZE;
  memcpy(addr, buff, size);

  return res;
}
#endif /* _USE_WRITE == 1 */

/**
  * @brief  I/O control operation
  * @param  pdrv: Physical drive number (0..)
  * @param  cmd: Control code
  * @param  *buff: Buffer to send/receive control data
  * @retval DRESULT: Operation result
  */
#if _USE_IOCTL == 1
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
  DRESULT res = RES_OK;

  if (pdrv) {
    return RES_PARERR;
  }

  if (stat & STA_NOINIT) return RES_NOTRDY;

  switch(cmd) {
  case 0:
    // CTRL_SYNC
    // Makes sure that the device has finished pending write process. If the disk I/O layer or storage device has a write-back cache, the cached data not written back must be flushed to the media immediately. Nothing to do for this command if each write operation to the media is completed within the disk_write function.

    break;

  case 1:
    //GET_SECTOR_COUNT
    return RAM_SECTOR_COUNT;
    break;

  case 2:
    //GET_SECTOR_SIZE
    return RAM_SECTOR_SIZE;
    break;

  case 3:
    //GET_BLOCK_SIZE
    return RAM_SECTOR_SIZE;
    break;

  case 4:
    //CTRL_TRIM
    // not defining this right now but should do the following
    // Informs the device the data on the block of sectors is no longer needed and it can be erased. The sector block is specified in an LBA_t array {<Start LBA>, <End LBA>} pointed by buff. This is an identical command to Trim of ATA device. Nothing to do for this command if this funcion is not supported or not a flash memory device. FatFs does not check the result code and the file function is not affected even if the sector block was not erased well. This command is called on remove a cluster chain and in the f_mkfs function. It is required when FF_USE_TRIM == 1.
    // TODO HAVE THIS DO A FULL WRITE TO FLASH

    break;
  }


  return res;
}
#endif /* _USE_IOCTL == 1 */


// TODO finish implementation of realtime clock
/**
  * @brief  Gets Time from RTC
  * @param  None
  * @retval Time in DWORD
  */
__weak DWORD get_fattime (void)
{
  RTC_HandleTypeDef rtc;
  RTC_TimeTypeDef time;
  uint32_t format;
  RTC_DateTypeDef sDate;

  /* typedef struct */
  /* { */
  /*   RTC_TypeDef                 *Instance;  /\*!< Register base address    *\/ */

  /*   RTC_InitTypeDef             Init;       /\*!< RTC required parameters  *\/ */

  /*   HAL_LockTypeDef             Lock;       /\*!< RTC locking object       *\/ */

  /*   __IO HAL_RTCStateTypeDef    State;      /\*!< Time communication state *\/ */

  /* }RTC_HandleTypeDef; */


  /* __IO uint32_t TR;         /\*!< RTC time register,                                         Address offset: 0x00 *\/ */
  /* __IO uint32_t DR;         /\*!< RTC date register,                                         Address offset: 0x04 *\/ */

  /* if (HAL_RTC_GetTime(RTC_HandleTypeDef *hrtc, &time, uint32_t Format) != HAL_OK) { */

  /* } */


  /* if (HAL_RTC_GetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format) != HAL_OK) { */

  /* } */

  return 0;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
