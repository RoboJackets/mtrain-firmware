#include "pin_defs.h"


DAC_HandleTypeDef    DacHandle;

//static DAC_HandleTypeDef DAC_Handle[2];
//static DAC_ChannelConfTypeDef DAC_ChannelConf;

void analogout_init(pin_name pin) {


    /**
    remember to check struct */


    GPIO_InitTypeDef GPIO_InitStruct = {};

    GPIO_InitStruct.Pin = pin.pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    
    
    
    //UP TO HERE IS FINE 
    //REMEBER TO GIVE PARAMETERS
    HAL_GPIO_Init(pin.port, &GPIO_InitStruct);

    //put _start here

    // todo: is this right?
    __HAL_RCC_DAC_CLK_ENABLE();

    DacHandle.Instance = DAC1;

    DAC_ChannelConfTypeDef sConfig;
    

    //Set dac option 

    sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
    sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;


    if(HAL_DAC_ConfigChannel(&DacHandle, &sConfig, DAC_CHANNEL_1) != HAL_OK)
    {
        while(1) {};
        
    };
    
    if(HAL_DAC_Start(&DacHandle, DAC_CHANNEL_1) != HAL_OK)
    {
        
        while(1) {};
        
    } ;
    

}


void analogout_write(pin_name pin, float value) {
        //check value
        //need a dac variable 
        uint32_t analog_value;
        if (value < 0 ) {
            analog_value = 0;
        } else if(value > 1) {
            analog_value = 1;
        } else {
            analog_value = value * 0xFFF;
        }
        //set 12 bit value right aligned

    
    if(HAL_DAC_SetValue(&DacHandle, DAC_CHANNEL_1, DAC_ALIGN_12B_R, analog_value) != HAL_OK){
            while(1) {};
           
        };


        
   
}
float analogout_read(pin_name pin ) {
    // if(HAL_GPIO_ReadPin == HAL_OK) {
    //return HAL_DAC_GetValue(pin.port, pin.pin); //look into how to inplement
    
        return HAL_GPIO_ReadPin(pin.port, pin.pin);
    // }
    
    //while(1) {};

}
void analog_out_deinit(pin_name pin) {
    __HAL_RCC_DAC_RELEASE_RESET();
    __HAL_RCC_DAC_FORCE_RESET();

    
    HAL_GPIO_DeInit(pin.port, pin.pin);


  /*##-4- Disable the NVIC for DMA ###########################################*/
  //HAL_NVIC_DisableIRQ(DACx_DMA_IRQn);


}
