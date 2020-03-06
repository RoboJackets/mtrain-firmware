add_library(FatFs STATIC
  src/ff.c
  src/ff_gen_drv.c
  src/diskio.c
  src/option/unicode.c
  src/option/syscall.c
)


# Include HAL configuration from BSP
target_include_directories(FatFs PUBLIC src/)
target_include_directories(FatFs PUBLIC ${CMAKE_SOURCE_DIR}/BSP/config/fatfs/)
target_include_directories(FatFs PUBLIC ${CMAKE_SOURCE_DIR}/BSP/Inc/)


target_sources(FatFs PUBLIC
    ${CMAKE_SOURCE_DIR}/BSP/Src/qspi.c
    ${CMAKE_SOURCE_DIR}/BSP/Inc/qspi.h
    )


target_link_libraries(FatFs PUBLIC STM32F7xx_HAL )
