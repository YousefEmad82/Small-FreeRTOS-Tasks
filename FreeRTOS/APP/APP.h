/*
 * APP.h
 *
 * Created: 3/29/2023 2:53:06 PM
 *  Author: youssef's
 */ 


#ifndef APP_H_
#define APP_H_
#include "FreeRTOS.h"
#include "task.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/UART/UART_Interface.h"
#include "semphr.h"
#include "queue.h"
#include "stdio.h"
#include "../MCAL/ADC/ADC_interface.h"
/************************************************************************/
/*							 Global Variables                           */
/************************************************************************/
//creating UART semaphore variable
extern SemaphoreHandle_t xUartSemaphore;

//creating ADC semaphore variable
extern SemaphoreHandle_t xADCSemaphore;


/************************************************************************/
/*									APIs                                */
/************************************************************************/
void INIT();
void UART_BUFFER_STORE(uint8 data);
void Lcd_Read_Uart_Task_Semaphore(void);
void ADC_DISPLAY_TEMP(void);
void ADC_READ_WITH_INT(uint16 data);
void Create_Semaphore_Task_ADC(void);
void Create_Semaphore_Task_Uart(void);
#endif /* APP_H_ */