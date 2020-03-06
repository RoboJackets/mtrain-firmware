#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f7xx_hal.h"
#include "qspi.h"

// USB Stuff
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_cdc.h"
#include "usbd_cdc_interface.h"
#include "usbd_msc.h"
#include "usbd_cdc_interface.h"

// FAT Stuff
#include "ff.h"
#include "ff_gen_drv.h"
#include "diskio.h"     /* Declarations of disk functions */

#define USE_USB_FS

extern void bsp_config(void);

void SystemClock_Config(void);
void Error_Handler(void);
void MPU_Config(void);
void CPU_CACHE_Enable(void);
void DWT_Config(void);
void RTC_Config(void);

#ifdef __cplusplus
}
#endif

#endif
