#include "mtrain.hpp"

#include "bsp.h"
#include  <unistd.h>

#include "PinDefs.hpp"

USBD_HandleTypeDef USBD_Device;

// Doesn't crash
// DigitalOut l1 = DigitalOut(LED2);

int main() {
    USBD_Init(&USBD_Device, &VCP_Desc, 0);
    USBD_RegisterClass(&USBD_Device, USBD_CDC_CLASS);
    USBD_CDC_RegisterInterface(&USBD_Device, &USBD_CDC_fops);
    USBD_Start(&USBD_Device);

    // Crashes
    //DigitalOut l1 = DigitalOut(LED2);

    // Doesn't crash
    //GPIO_InitTypeDef pin_structure = {};
    //pin_structure.Pin = LED2.pin;
    //pin_structure.Mode = PinMode::PushPull;
    //pin_structure.Pull = PullType::PullNone;
    //pin_structure.Speed = PinSpeed::Low;
    
    //HAL_GPIO_Init(LED2.port, &pin_structure);

    fflush(stdout);

    for (;;) {
        HAL_Delay(5);

        printf("t\r\n");
        fflush(stdout);
    }

  while (true) { }
}

extern "C" {

int _write(int file, char *data, int len)
{
    if (file == STDOUT_FILENO) {
        USBD_CDC_SetTxBuffer(&USBD_Device, (uint8_t*)data, len);
        USBD_CDC_TransmitPacket(&USBD_Device);
    }
    return 0;
}
}