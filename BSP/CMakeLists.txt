project(mtrain_lib LANGUAGES C ASM)

add_library(mtrain
    startup.s
    src/bsp.c
    src/interrupt_handlers.c
    src/default_handlers.c
    src/stm32f7xx_hal_msp.c
    src/usbd_cdc_interface.c
    src/qspi.c
)

target_include_directories(mtrain PUBLIC
    inc
)

set_target_properties(mtrain PROPERTIES LINK_DEPENDS "${CMAKE_SOURCE_DIR}/BSP/flash.ld")

target_link_libraries(mtrain PUBLIC DSP STM32F7xx_HAL STM32_USB_Device)
