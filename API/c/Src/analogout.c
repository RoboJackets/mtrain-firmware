#include <mtrain.h>


DAC_HandleTypeDef    DacHandle;
static DAC_ChannelConfTypeDef sConfig;
const uint8_t aEscalator8bit[6] = {0x0, 0x33, 0x66, 0x99, 0xCC, 0xFF};
__IO uint8_t ubSelectedWavesForm = 1;
__IO uint8_t ubKeyPressed = SET;


//static DAC_HandleTypeDef DAC_Handle[2];
static DAC_ChannelConfTypeDef DAC_ChannelConf;

void analog_out_init(pin_name pin) {


    /**
    remember to check struct */


    GPIO_InitTypeDef          GPIO_InitStruct;


    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.Pin = pin.pin;
    GPIO_InitStruct.Mode = GPIO_MOODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    
    
    //UP TO HERE IS FINE 
    //REMEBER TO GIVE PARAMETERS
    HAL_GPIO_Init(pin.port, &GPIO_InitStruct);

    //put _start here

    // todo: is this right?
    __HAL_RCC_DAC_CLK_ENABLE();\

    DacHandle.instance = DAC1;

    DAC_ChannelConfTypeDef sConfig;
    

    //Set dac option 

    sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
    sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;


    HAL_DAC_ConfigChannel(&DacHandle, &sConfig, DAC_CHANNEL_1);
    
    HAL_DAC_Start(&DacHandle, DAC_CHANNEL_1);

}

void analogout_Write(pin_name pin, float value) {
        //check value
        //need a dac variable 
        uinit32_t analog_value;
        if (analog_value < 0 ) {
            analag_value = 0;
        } else if(analog_value > 1) {
            analog_value == 1;
        } else {
            analog_value = vlaue * 0xFFF;
        }
        //set 12 bit value right aligned
       
   
        HAL_DAC_SetValue(&DacHandle, DAC_CHANNEL_1, DAC_ALIGN_12B_R, analog_value);
   
}


void analog_read() {

}


void analog_out_deinit(pin_name pin) {
    DACx_FORCE_RESET();
    DACx_RELEASE_RESET();

    HAL_GPIO_DeInit(DACX_)

    HAL_GPIO_DeInit(DACx_CHANNEL_GPIO_PORT, DACx_CHANNEL_PIN);

  

  /*##-4- Disable the NVIC for DMA ###########################################*/
  //HAL_NVIC_DisableIRQ(DACx_DMA_IRQn);


}
