/*
 * ADC.c
 *
 * Created: 3/1/2023 9:26:42 PM
 *  Author: youssef's
 */ 

#include "ADC_interface.h"
ADC_CONFIG ADC_Config = {DIV_2,AVCC,RIGHT};
void ADC_INIT(uint8 channel){
	//set channel to be input
	CLEAR_BIT(DDRA_REG,channel);
	
	//setting the vref
	if(ADC_Config.VREF == AVCC){
		SET_BIT(ADMUX_REG,REFS0);
		CLEAR_BIT(ADMUX_REG,REFS1);
	}
	else if(ADC_Config.VREF == AREF){
		CLEAR_BIT(ADMUX_REG,REFS0);
		CLEAR_BIT(ADMUX_REG,REFS1);
	}
	
	//setting the prescaler
	ADCSRA_REG |= ADC_Config.prescaler;
	
	//enabling the ADC
	SET_BIT(ADCSRA_REG,ADEN);
	
	//adjusting the direction of ADC DATA register
	if(ADC_Config.ADJUST_LEFT_RIGHT == LEFT){
		SET_BIT(ADMUX_REG,ADLAR);
	}
	else if(ADC_Config.ADJUST_LEFT_RIGHT == RIGHT){
		CLEAR_BIT(ADMUX_REG,ADLAR);
	}
	//checking if interrupt is enabled
	if(ADC_INTERRUPT == 1){
		SET_BIT(SREG,7);
		SET_BIT(ADCSRA_REG,ADIE);
	}
}
uint16 ADC_READ(uint8 channel){
	//initializing first five bits by 0
	ADMUX_REG &= 0xE0;
	
	//choosing the channel
	ADMUX_REG |=channel;
	 
	//starting conversion
	SET_BIT(ADCSRA_REG,ADSC);
	
	while(READ_BIT(ADCSRA_REG,ADIF) == 0);
	
	//read the converted input
	if(ADC_Config.ADJUST_LEFT_RIGHT == LEFT){
		return ADC_DATA_REGISTER>>6;
	}
	else if(ADC_Config.ADJUST_LEFT_RIGHT == RIGHT){
		return ADC_DATA_REGISTER;
	}
}
void ADC_START_COV(){
	//choosing the channel number 0 
	ADMUX_REG |=0;
	//starting conversion
	SET_BIT(ADCSRA_REG,ADSC);
}

//global callback pointer
ADC_callback_t ADC_callback_ptr = NULL ;
//setting the callback function 
void ADC_Set_Callback(ADC_callback_t ptr){
	if(ptr != NULL){
		ADC_callback_ptr = ptr;
	}
}
//ISR of ADC
ISR(ADC_INT){
	
	uint16 data = 0;
	data  = ADC_DATA_REGISTER;
	ADC_callback_ptr(data);
	
}