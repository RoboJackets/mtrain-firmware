#include "mtrain.h"

typedef enum {
    PUSH_PULL = GPIO_MODE_OUTPUT_PP,
    OPEN_DRAIN = GPIO_MODE_OUTPUT_OD
} output_mode;

typedef enum {
    P0 = GPIO_PIN_0,
    P1 = GPIO_PIN_1,
    P2 = GPIO_PIN_2,
    P3 = GPIO_PIN_3,
    P4 = GPIO_PIN_4,
    P5 = GPIO_PIN_5,
    P6 = GPIO_PIN_6,
    P7 = GPIO_PIN_7,
    P8 = GPIO_PIN_8,
    P9 = GPIO_PIN_9,
    P10 = GPIO_PIN_10,
    P11 = GPIO_PIN_11,
    P12 = GPIO_PIN_12,    
    P13 = GPIO_PIN_13,
    P14 = GPIO_PIN_14,
    P15 = GPIO_PIN_15
} pin;

//https://www.st.com/resource/en/datasheet/stm32f765bg.pdf Page 159
typedef enum {
    NO_PULL = GPIO_NOPULL,
    PULL_UP = GPIO_PULLUP,
    PULL_DOWN = GPIO_PULLDOWN
} pull_type;

//https://www.st.com/resource/en/datasheet/stm32f765bg.pdf Page 162-163
typedef enum {
    LOW = GPIO_SPEED_FREQ_LOW,
    MEDIUM = GPIO_SPEED_FREQ_MEDIUM,
    HIGH = GPIO_SPEED_FREQ_HIGH,
    VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH
} speed;

// Inspired by https://os.mbed.com/docs/v5.10/apis/digitalout.html
void digitalout_init(pin p, pull_type t, output_mode o, speed s);
void digitalout_write(pin p, GPIO_PinState s);
GPIO_PinState digitalout_read(pin p);

