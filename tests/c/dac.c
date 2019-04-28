#include "mtrain.h"

int main(void) {
    analogout_init(PIN33);

    float value = 0;
    int forward = 0;

    while (1) {
        analogout_write(PIN33,value);
        analogout_read(PIN33);
        HAL_Delay(1);
        if (forward ==0){
            value += 0.01;
        } 
        else {
            value -= -0.01;
        }
        if (value>= 1) {
            forward == 1;

        }
        else if (value <= 0) {
            forward =0;
        }
         

    }
}
