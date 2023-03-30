/*
 * FreeRTOS.c
 *
 * Created: 3/26/2023 9:43:39 PM
 * Author : youssef's
 */ 

#include "APP/APP.h"
int main(void)
{
	
	INIT();
	//Create_Semaphore_Task_ADC();
	Create_Semaphore_Task_Uart();
	vTaskStartScheduler();
	
    while (1) 
    {	
	    
		
    }
}

