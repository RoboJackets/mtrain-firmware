#include "mtrain.h"

int main(void) {
    analog_out_init(PIN33);

    analogout_write(PIN33, 0.5);
}

