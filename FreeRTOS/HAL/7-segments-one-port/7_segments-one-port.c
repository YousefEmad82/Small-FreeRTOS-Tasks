/*
 * 7_segments.c
 *
 * Created: 3/25/2023 12:12:07 PM
 *  Author: yasmin
 */ 
#include "seven_segments_one_port.h"
#include "../../MCAL/DIO/DIO_Interface.h"
//numbers display on PORT_D
char array2_one_port[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
//APIs


void SevenSegmentsDisplayNumberOnePort(uint8 number){
	DIO_vWritePort(SEVEN_SEGMENTS_PORT,array2_one_port[number]);
}
