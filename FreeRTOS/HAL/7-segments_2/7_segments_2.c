/*
 * _7_segments_2.c
 *
 * Created: 3/25/2023 12:43:53 PM
 *  Author: youssef's
 */ 
#include "seven_segments_2.h"
#include "../../MCAL/DIO/DIO_Interface.h"
//numbers display on PORT_D
char array2[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

//APIs
void SevenSegments2Init(){
	DIO_vSetPortDirection(SEVEN_SEGMENTS2_PORT ,OUTPUT);
}

void SevenSegments2DisplayNumber(uint8 number){
	DIO_vWritePortValue(SEVEN_SEGMENTS2_PORT,array2[number]);
}