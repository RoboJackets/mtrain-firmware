
project(FatFs LANGUAGES C)


add_library(FatFs STATIC
  src/diskio.c
  src/ff.c
  src/ff_gen_drv.c
  # src/ffconf.h
)


target_include_directories(FatFs PUBLIC
  src/
  )


# Include HAL configuration from BSP
# target_include_directories(FatFs PUBLIC ${CMAKE_SOURCE_DIR}/BSP/config/usb)


# target_sources(STM32_USB_Device PUBLIC
#     ${CMAKE_SOURCE_DIR}/BSP/config/usb/usbd_conf.c
#     ${CMAKE_SOURCE_DIR}/BSP/config/usb/usbd_desc.c
#     )


target_link_libraries(FatFs PUBLIC STM32F7xx_HAL)
