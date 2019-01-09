#include "mtrain.h"

typedef struct {
    GPIO_TypeDef* bank;
    uint16_t pin_number;
} pin_name;

#define Pin3 (struct pin_name) {GPIOA, GPIO_PIN_8}
#define Pin4 (struct pin_name) {GPIOB, GPIO_PIN_15}
#define Pin5 (struct pin_name) {GPIOB, GPIO_PIN_14}
#define Pin6 (struct pin_name) {GPIOA, GPIO_PIN_12}
#define Pin7 (struct pin_name) {GPIOA, GPIO_PIN_11}
#define Pin8 (struct pin_name) {GPIOC, GPIO_PIN_6}
#define Pin9 (struct pin_name) {GPIOC, GPIO_PIN_7}
#define Pin10 (struct pin_name) {GPIOC, GPIO_PIN_8}
#define Pin11 (struct pin_name) {GPIOC, GPIO_PIN_9}
#define Pin12 (struct pin_name) {GPIOH, GPIO_PIN_10}
#define Pin13 (struct pin_name) {GPIOH, GPIO_PIN_11}
#define Pin14 (struct pin_name) {GPIOH, GPIO_PIN_12}
#define Pin15 (struct pin_name) {GPIOI, GPIO_PIN_0}
#define Pin16 (struct pin_name) {GPIOD, GPIO_PIN_5}
#define Pin17 (struct pin_name) {GPIOD, GPIO_PIN_6}
#define Pin18 (struct pin_name) {GPIOD, GPIO_PIN_7}
#define Pin19 (struct pin_name) {GPIOB, GPIO_PIN_9}
#define Pin20 (struct pin_name) {GPIOB, GPIO_PIN_8}
#define Pin25 (struct pin_name) {GPIOB, GPIO_PIN_6}
#define Pin26 (struct pin_name) {GPIOB, GPIO_PIN_7}
#define Pin27 (struct pin_name) {GPIOF, GPIO_PIN_9}
#define Pin28 (struct pin_name) {GPIOF, GPIO_PIN_8}
#define Pin29 (struct pin_name) {GPIOF, GPIO_PIN_7}
#define Pin30 (struct pin_name) {GPIOF, GPIO_PIN_6}
#define Pin31 (struct pin_name) {GPIOA, GPIO_PIN_0}
#define Pin32 (struct pin_name) {GPIOA, GPIO_PIN_6}
#define Pin33 (struct pin_name) {GPIOA, GPIO_PIN_4}
#define Pin34 (struct pin_name) {GPIOC, GPIO_PIN_10}
#define Pin35 (struct pin_name) {GPIOB, GPIO_PIN_4}
#define Pin36 (struct pin_name) {GPIOC, GPIO_PIN_12}

// https://www.st.com/resource/en/datasheet/stm32f765bg.pdf Page 159
typedef enum { NO_PULL = GPIO_NOPULL, PULL_UP = GPIO_PULLUP, PULL_DOWN = GPIO_PULLDOWN } pull_type;

typedef enum { PUSH_PULL = GPIO_MODE_OUTPUT_PP, OPEN_DRAIN = GPIO_MODE_OUTPUT_OD } output_mode;

// https://www.st.com/resource/en/datasheet/stm32f765bg.pdf Page 162-163
typedef enum { LOW = GPIO_SPEED_FREQ_LOW, MEDIUM = GPIO_SPEED_FREQ_MEDIUM, HIGH = GPIO_SPEED_FREQ_HIGH, VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH } speed;

// Inspired by https://os.mbed.com/docs/v5.10/apis/digitalout.html
void digitalout_init_config(pin_name p, pull_type t, output_mode o, speed s);
void digitalout_init(pin_name p);
void digitalout_deinit(pin_name p);
void digitalout_write(pin_name p, GPIO_PinState s);
GPIO_PinState digitalout_read(pin_name p);
