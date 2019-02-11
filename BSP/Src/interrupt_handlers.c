#include "bsp.h"

void (*interrupt0)(pin_name);
void (*interrupt4)(pin_name);
void (*interrupt5)(pin_name);
void (*interrupt6)(pin_name);
void (*interrupt7)(pin_name);
void (*interrupt8)(pin_name);
void (*interrupt9)(pin_name);
void (*interrupt10)(pin_name);
void (*interrupt11)(pin_name);
void (*interrupt12)(pin_name);
void (*interrupt13)(pin_name);
void (*interrupt14)(pin_name);
void (*interrupt15)(pin_name);

void SysTick_Handler(void)
{
    HAL_IncTick();
}

extern PCD_HandleTypeDef hpcd;

/*  */
#ifdef USE_USB_FS
void OTG_FS_IRQHandler(void)
#else
void OTG_HS_IRQHandler(void)
#endif
{
    HAL_PCD_IRQHandler(&hpcd);
}

extern QSPI_HandleTypeDef QSPIHandle;

void QUADSPI_IRQHandler(void)
{
    HAL_QSPI_IRQHandler(&QSPIHandle);
}

void EXTI0_IRQHandler(void)
{
    //Handle A0 (31)
}

void EXTI4_IRQHandler(void)
{
    //Handle B4 (35)
}

void EXTI9_5_IRQHandler(void)
{
    //Handle D5 (16)
    //Handle F6 (30)
    //Handle D7 (18)
    //Handle D8 (20)
    //Handle C9 (11)
}

void EXTI15_10_IRQHandler(void)
{
    //Handle C10 (34)
    //Handle H11 (13)
    //Handle C12 (36)
    //Handle B14 (5)
    //Handle B15 (4)
}
