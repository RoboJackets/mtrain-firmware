/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
/*                                                                       */
/*   Portions COPYRIGHT 2016 STMicroelectronics                          */
/*   Portions Copyright (C) 2014, ChaN, all right reserved               */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

/**
  ******************************************************************************
  * @file    diskio.c
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    23-December-2016
  * @brief   FatFs low level disk I/O module.
  ******************************************************************************
  * @attention
  *
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ff_gen_drv.h"
#include "qspi.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern Disk_drvTypeDef  disk;
// TODO Global status var
/* static volatile DSTATUS stat = STA_NOINIT; */

/* Private function prototypes -----------------------------------------------*/

DSTATUS qspi_flash_initialize (BYTE);
DSTATUS qspi_flash_status (BYTE);
DRESULT qspi_flash_read (BYTE, BYTE*, DWORD, UINT);
#if _USE_WRITE == 1
DRESULT qspi_flash_write (BYTE, const BYTE*, DWORD, UINT);
#endif /* _USE_WRITE == 1 */
#if _USE_IOCTL == 1
DRESULT qspi_flash_ioctl (BYTE, BYTE, void*);
#endif  /* _USE_IOCTL == 1 */

const Diskio_drvTypeDef  qspi_flash_driver =
  {
    qspi_flash_initialize,
    qspi_flash_status,
    qspi_flash_read,
#if  _USE_WRITE == 1
    qspi_flash_write,
#endif /* _USE_WRITE == 1 */

#if  _USE_IOCTL == 1
    qspi_flash_ioctl,
#endif /* _USE_IOCTL == 1 */
  };




/* Private functions ---------------------------------------------------------*/




/**
  * @brief  Gets Disk Status
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS qspi_flash_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{

  if (drv){
    return STA_NOINIT;		/* Supports only drive 0 */
  }

  // zero is good here
  DSTATUS stat;
  return stat;
}

/**
  * @brief  Initializes a Drive
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS qspi_flash_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
  if (drv){
    return STA_NOINIT;		/* Supports only drive 0 */
  }

  DSTATUS stat = RES_OK;


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
DRESULT qspi_flash_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	        /* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
  if (drv) {
    return RES_PARERR;
  }

  DRESULT res;
  // TODO Check qspi ready?

  // convert sector to address for qspi and then count to size by doing 4kb times count
  uint32_t addr = sector * FLASH_SUBSECTOR_SIZE;
  uint32_t size = count * FLASH_SUBSECTOR_SIZE;
  if (BSP_QSPI_Read(buff, addr, size) != QSPI_OK) {
    res = RES_ERROR;
  }

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
DRESULT qspi_flash_write (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count        	/* Number of sectors to write */
)
{
  if (drv) {
    return RES_PARERR;
  }

  uint32_t addr = sector * FLASH_SUBSECTOR_SIZE;
  uint32_t size = count * FLASH_SUBSECTOR_SIZE;
  if (BSP_QSPI_Write(buff, addr, size) != QSPI_OK) {
    res = RES_ERROR;
  }

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
DRESULT qspi_flash_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
  if (drv) {
    return RES_PARERR;
  }

  if (Stat & STA_NOINIT) return RES_NOTRDY;

  DRESULT res;
  switch(cmd) {
  case 0:
    // CTRL_SYNC
    // Makes sure that the device has finished pending write process. If the disk I/O layer or storage device has a write-back cache, the cached data not written back must be flushed to the media immediately. Nothing to do for this command if each write operation to the media is completed within the disk_write function.

    break;

  case 1:
    //GET_SECTOR_COUNT
    return FLASH_SECTOR_COUNT;
    break;

  case 2:
    //GET_SECTOR_SIZE
    return FLASH_SECTOR_SIZE;
    break;

  case 2:
    //GET_BLOCK_SIZE
    //These should be the 16k sectors as they make up the bulk of storage
    return FLASH_SECTOR_SIZE * 4;
    break;

  case 3:
    //CTRL_TRIM
    // not defining this right now but should do the following
    // Informs the device the data on the block of sectors is no longer needed and it can be erased. The sector block is specified in an LBA_t array {<Start LBA>, <End LBA>} pointed by buff. This is an identical command to Trim of ATA device. Nothing to do for this command if this funcion is not supported or not a flash memory device. FatFs does not check the result code and the file function is not affected even if the sector block was not erased well. This command is called on remove a cluster chain and in the f_mkfs function. It is required when FF_USE_TRIM == 1.

    break;
  }


  return res;
}
#endif /* _USE_IOCTL == 1 */

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
