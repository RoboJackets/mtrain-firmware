// Primarily taken from https://stackoverflow.com/questions/54977350/jump-to-system-bootloader-from-user-code-with-stm32f042k6

#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_flash_ex.h"

// #define SYSTEM_MEMORY_ADDRESS          0x1FF00000
#define SYSTEM_MEMORY_ADDRESS          0x00100000

HAL_StatusTypeDef SB_SystemBootloaderJump()
{
    typedef void (*pFunction)(void);
    pFunction JumpToApplication;

    // __HAL_RCC_USART1_FORCE_RESET();
    // HAL_Delay(5);
    // __HAL_RCC_USART1_RELEASE_RESET();
    // HAL_Delay(5);

    // #if defined(USE_HAL_DRIVER)
    HAL_RCC_DeInit();
    // #endif /* defined(USE_HAL_DRIVER) */
    // #if defined(USE_STDPERIPH_DRIVER)
    //     RCC_DeInit();
    // #endif /* defined(USE_STDPERIPH_DRIVER) */
    SysTick->CTRL = 0;
    SysTick->LOAD = 0;
    SysTick->VAL = 0;

    /**
     * Step: Disable all interrupts
     */
    __disable_irq();

    /* ARM Cortex-M Programming Guide to Memory Barrier Instructions.*/
    __DSB();

    // Remap to use Boot_add0 again???
    // SET_BIT(SYSCFG->MEMRMP, 0x1);
    SYSCFG->MEMRMP = 0x01;

    /* Remap is bot visible at once. Execute some unrelated command! */
    __DSB();
    __ISB();


    // // nDBANK(bit) = 1, Boot(pin) = 0 and BOOT_ADD0(optionbyte) = 0x0040
    // FLASH_OBProgramInitTypeDef pOBInit;
    // /* Get the Option byte configuration */
    // HAL_FLASHEx_OBGetConfig(&pOBInit);

    // /* nDBOOT0=0 */
    // pOBInit.USERConfig &= ~(OB_DUAL_BOOT_DISABLE);

    // // nDBANK = 1
    // pOBInit.USERConfig |= (OB_NDBANK_SINGLE_BANK);

    // // Set boot address to system boot loader
    // pOBInit.BootAddr0 = OB_BOOTADDR_SYSTEM;

    // /** HAL_FLASHEx_OBProgram && HAL_FLASHEx_OBErase
    //   * HAL_FLASH_OB_Unlock() should be called before to unlock the options bytes
    //   */
    // if(HAL_FLASH_OB_Unlock() != HAL_OK)
    // {
    //     return HAL_ERROR;
    // }

    // /* Write changed option bytes */
    // if(HAL_FLASHEx_OBProgram(&pOBInit))
    // {
    //     return HAL_ERROR;
    // }

    JumpToApplication = (void (*)(void)) (*((uint32_t *) ((SYSTEM_MEMORY_ADDRESS + 4))));

    /* Initialize user application's Stack Pointer */
    __set_MSP(*(__IO uint32_t*) SYSTEM_MEMORY_ADDRESS);

    JumpToApplication();
    return HAL_OK;
}


int main() {
    SB_SystemBootloaderJump();
    return 0;
}
