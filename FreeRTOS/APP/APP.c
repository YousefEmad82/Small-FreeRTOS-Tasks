/*
 * APP.c
 *
 * Created: 3/29/2023 2:52:56 PM
 *  Author: youssef's
 */ 
#include "APP.h"
/************************************************************************/
/*							 Global Variables                           */
/************************************************************************/


//UART data buffer
uint8 UART_RX_BUFFER[102];
//UART buffer counter
uint8 UART_BUFF_COUNT = 0;
//creating UART semaphore variable 
SemaphoreHandle_t xUartSemaphore;
//ADC data buffer
uint16 ADC_BUFF = 0;
//creating ADC semaphore variable
SemaphoreHandle_t xADCSemaphore;


/************************************************************************/
/*									APIs                                */
/************************************************************************/
void INIT(){
	//LCD INIT
	LCD_INIT();
	//|UART set callback
	Uart_set_callback(UART_BUFFER_STORE);
	//UART INIT
	UART_INIT();
	//ADC callback
	ADC_Set_Callback(ADC_READ_WITH_INT);
	//ADC INIT
	ADC_INIT(0);
}
void UART_BUFFER_STORE(uint8 data){
	//give semaphore
	xSemaphoreGive( xUartSemaphore );
	UART_RX_BUFFER[UART_BUFF_COUNT] = data;
	UART_BUFF_COUNT++;
}


void Lcd_Read_Uart_Task_Semaphore(){
	//take the semaphore
		uint8 i ;
		while(1){
			if( xSemaphoreTake( xUartSemaphore,2) == pdTRUE )
			{
				for(i=0;i<UART_BUFF_COUNT;i++){
					LCD_WRITE_CHAR(UART_RX_BUFFER[i]);
				}
				UART_BUFF_COUNT = 0;
			}else{}
				vTaskDelay(1000);
		}
}

void ADC_READ_WITH_INT(uint16 data){
	xSemaphoreGive(xADCSemaphore);
	ADC_BUFF = (data*5*100)/1023;
	
}
void ADC_DISPLAY_TEMP(void){
	while(1){
		LCD_clear_screen();
		if( xSemaphoreTake( xADCSemaphore,2) == pdTRUE ){
			uint16 string_data[16];
			sprintf(string_data,"T=%d",ADC_BUFF);
			LCD_WRITE_STRING(string_data);
		}
		vTaskDelay(20);
		//start conversion each time i exit the task 
		ADC_START_COV();
	}
}

void Create_Semaphore_Task_Uart(void){
	//creating the counting semaphore with 102 count all taken 
	xUartSemaphore = xSemaphoreCreateCounting(102,0);
	//creating the task 
	xTaskCreate(Lcd_Read_Uart_Task_Semaphore,NULL,250,NULL,1,NULL);
	
}

void Create_Semaphore_Task_ADC(void){
	//creating a counting semaphore of one count already taken 
	xADCSemaphore = xSemaphoreCreateCounting(1,0);
	//creating the task
	xTaskCreate(ADC_DISPLAY_TEMP,NULL,250,NULL,1,NULL);
	
}