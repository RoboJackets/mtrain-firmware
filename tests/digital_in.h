#include "mtrain.h"

typedef struct {
    GPIO_TypeDef* bank;
    uint16_t pin_number;
} pin_name;

#define Pin3 (pin_name) {GPIOA, GPIO_PIN_8}
#define Pin4 (pin_name) {GPIOB, GPIO_PIN_15}
#define Pin5 (pin_name) {GPIOB, GPIO_PIN_14}
#define Pin6 (pin_name) {GPIOA, GPIO_PIN_12}
#define Pin7 (pin_name) {GPIOA, GPIO_PIN_11}
#define Pin8 (pin_name) {GPIOC, GPIO_PIN_6}
#define Pin9 (pin_name) {GPIOC, GPIO_PIN_7}
#define Pin10 (pin_name) {GPIOC, GPIO_PIN_8}
#define Pin11 (pin_name) {GPIOC, GPIO_PIN_9}
#define Pin12 (pin_name) {GPIOH, GPIO_PIN_10}
#define Pin13 (pin_name) {GPIOH, GPIO_PIN_11}
#define Pin14 (pin_name) {GPIOH, GPIO_PIN_12}
#define Pin15 (pin_name) {GPIOI, GPIO_PIN_0}
#define Pin16 (pin_name) {GPIOD, GPIO_PIN_5}
#define Pin17 (pin_name) {GPIOD, GPIO_PIN_6}
#define Pin18 (pin_name) {GPIOD, GPIO_PIN_7}
#define Pin19 (pin_name) {GPIOB, GPIO_PIN_9}
#define Pin20 (pin_name) {GPIOB, GPIO_PIN_8}
#define Pin25 (pin_name) {GPIOB, GPIO_PIN_6}
#define Pin26 (pin_name) {GPIOB, GPIO_PIN_7}
#define Pin27 (pin_name) {GPIOF, GPIO_PIN_9}
#define Pin28 (pin_name) {GPIOF, GPIO_PIN_8}
#define Pin29 (pin_name) {GPIOF, GPIO_PIN_7}
#define Pin30 (pin_name) {GPIOF, GPIO_PIN_6}
#define Pin31 (pin_name) {GPIOA, GPIO_PIN_0}
#define Pin32 (pin_name) {GPIOA, GPIO_PIN_6}
#define Pin33 (pin_name) {GPIOA, GPIO_PIN_4}
#define Pin34 (pin_name) {GPIOC, GPIO_PIN_10}
#define Pin35 (pin_name) {GPIOB, GPIO_PIN_4}
#define Pin36 (pin_name) {GPIOC, GPIO_PIN_12}

// https://www.st.com/resource/en/datasheet/stm32f765bg.pdf Page 159
typedef enum { NO_PULL = GPIO_NOPULL, PULL_UP = GPIO_PULLUP, PULL_DOWN = GPIO_PULLDOWN } pull_type;

typedef enum { PUSH_PULL = GPIO_MODE_OUTPUT_PP, OPEN_DRAIN = GPIO_MODE_OUTPUT_OD, INPUT = GPIO_MODE_INPUT } pin_mode;

// https://www.st.com/resource/en/datasheet/stm32f765bg.pdf Page 162-163
typedef enum { LOW = GPIO_SPEED_FREQ_LOW, MEDIUM = GPIO_SPEED_FREQ_MEDIUM, HIGH = GPIO_SPEED_FREQ_HIGH, VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH } speed;

// Inspired by https://os.mbed.com/docs/v5.10/apis/digitalin.html
void digitalin_init(pin_name p);
void digitalin_deinit(pin_name p);
GPIO_PinState digitalin_read(pin_name p);
