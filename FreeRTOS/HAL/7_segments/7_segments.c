/*
 * 7_segments.c
 *
 * Created: 3/25/2023 12:12:07 PM
 *  Author: youssef's
 */ 
#include "seven_segments.h"
#include "../../MCAL/DIO/DIO_Interface.h"
//numbers display on PORT_D
char array[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

//APIs
void SevenSegmentsInit(){
	DIO_vSetPortDirection(SEVEN_SEGMENTS_PORT ,OUTPUT);
	DIO_vWritePort(SEVEN_SEGMENTS_PORT ,HIGH);
}

void SevenSegmentsDisplayNumber(uint8 number){
	DIO_vWritePortValue(SEVEN_SEGMENTS_PORT,array[number]);
}