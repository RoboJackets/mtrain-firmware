#ifndef __STM32F769I_EVAL_QSPI_H
#define __STM32F769I_EVAL_QSPI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes */
#include "stm32f7xx_hal.h"

/* QSPI Error codes */
#define QSPI_OK            ((uint8_t)0x00)
#define QSPI_ERROR         ((uint8_t)0x01)
#define QSPI_BUSY          ((uint8_t)0x02)
#define QSPI_NOT_SUPPORTED ((uint8_t)0x04)
#define QSPI_SUSPENDED     ((uint8_t)0x08)


/* Pin/port definitions for QSPI */
#define QSPI_CS_PIN         GPIO_PIN_11
#define QSPI_CS_PORT        GPIOC
#define QSPI_CLK_PIN        GPIO_PIN_2
#define QSPI_CLK_PORT       GPIOB
#define QSPI_D0_PIN         GPIO_PIN_11
#define QSPI_D0_PORT        GPIOD
#define QSPI_D1_PIN         GPIO_PIN_12
#define QSPI_D1_PORT        GPIOD
#define QSPI_D2_PIN         GPIO_PIN_2
#define QSPI_D2_PORT        GPIOE
#define QSPI_D3_PIN         GPIO_PIN_13
#define QSPI_D3_PORT        GPIOD


/*
* Flash parameters
*/
#define FLASH_SIZE              0x2000000      // 256 MBits = 32 MBytes
#define FLASH_SUBSECTOR_SIZE    0x1000         // 4 KBytes
#define FLASH_PAGE_SIZE         0x100          // 256 Bytes
#define FLASH_SUBSECTOR_COUNT   (FLASH_SIZE) / (FLASH_SUBSECTOR_SIZE)

#define FLASH_4K_SECTOR_MAX     0x10000

/*
 * Command names
 */

/* Read Device ID */
#define FLASH_CMD_RDID          0x9F    // Read ID
#define FLASH_CMD_RSFDP         0x5A    // Read JEDEC
#define FLASH_CMD_RDQID         0xAF    // Read Quad ID

/* Register Access */
#define FLASH_CMD_RDSR1         0x05    // Read Status Register 1
#define FLASH_CMD_RDSR2         0x07    // Read Status Register 2
#define FLASH_CMD_RDCR          0x35    // Read Configuration Register 1
#define FLASH_CMD_RDAR          0x65    // Read Any Register
#define FLASH_CMD_WRR           0x01    // Write Register (Status 1, Configuration 1)
#define FLASH_CMD_WRDI          0x04    // Write Disable
#define FLASH_CMD_WREN          0x06    // Write Enable
#define FLASH_CMD_WRAR          0x71    // Write Any Register
#define FLASH_CMD_4BAM          0xB7    // Enter 4 Byte Address Mode
#define FLASH_CMD_SBL           0xC0    // Set Burst Length

/* Read Flash Array */
#define FLASH_CMD_READ          0x03    // Read
#define FLASH_CMD_4READ         0x13    // Read (4 byte address)
#define FLASH_CMD_FAST_READ     0x0B    // Fast Read
#define FLASH_CMD_4FAST_READ    0x0C    // Fast Read (4 byte address)
#define FLASH_CMD_DIOR          0xBB    // Dual I/O Read
#define FLASH_CMD_4DIOR         0xBC    // Dual I/O Read (4 byte address)
#define FLASH_CMD_QIOR          0xEB    // Quad I/O Read
#define FLASH_CMD_4QIOR         0xEC    // Quad I/O Read (4 byte address)

/* Program Flash Array */
#define FLASH_CMD_PP            0x02    // Page Program
#define FLASH_CMD_4PP           0x12    // Page Program (4 byte address)

/* Erase Flash Array */
#define FLASH_CMD_P4E           0x20    // Parameter 4 kB Sector Erase
#define FLASH_CMD_4P4E          0x21    // 4 kB Sector Erase (4 byte address)
#define FLASH_CMD_SE            0xD8    // Erase 64 kB or 256 kB
#define FLASH_CMD_4SE           0xDC    // Erase 64 kB or 256 kB (4 byte address)
#define FLASH_CMD_BE            0x60    // Bulk Erase

/* Reset */
#define FLASH_CMD_RSTEN         0x66    // Software Reset Enable
#define FLASH_CMD_RESET         0x99    // Software Reset


/* Register Address Map */
#define FLASH_ADDR_SR1NV        0x00000000
#define FLASH_ADDR_CR1NV        0x00000002
#define FLASH_ADDR_CR2NV        0x00000003
#define FLASH_ADDR_CR3NV        0x00000004
#define FLASH_ADDR_CR4NV        0x00000005


#define FLASH_SR1_WIP           ((uint8_t)0b00000001)
#define FLASH_SR1_WEL           ((uint8_t)0b00000010)

#define DUMMY_CYCLES_READ_QUAD 0b1000

#define SUBSECTOR_ERASE_MAX_TIME        800
#define BULK_ERASE_MAX_TIME    480000



uint8_t BSP_QSPI_Init(void);
uint8_t BSP_QSPI_DeInit(void);
uint8_t BSP_QSPI_Read(uint8_t* pData, uint32_t ReadAddr, uint32_t Size);
uint8_t BSP_QSPI_Write(uint8_t* pData, uint32_t WriteAddr, uint32_t Size);
uint8_t BSP_QSPI_Erase_Sector(uint32_t BlockAddress);
uint8_t BSP_QSPI_Erase_Chip(void);

uint8_t BSP_print_regs(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F769I_EVAL_QSPI_H */
