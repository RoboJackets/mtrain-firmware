#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "usbd_cdc.h"
#include "usbd_cdc_interface.h"
#include "usbd_main.h"
#include "qspi.h"

extern void bsp_config(void);

void SystemClock_Config(void);
void Error_Handler(void);
void MPU_Config(void);
void CPU_CACHE_Enable(void);
void DWT_Config(void);

uint8_t USB_DFU_ongoing(void);
void USB_DFU_Deinit(void);
void USB_DFU_Init(void);

#ifdef __cplusplus
}
#endif

#endif
