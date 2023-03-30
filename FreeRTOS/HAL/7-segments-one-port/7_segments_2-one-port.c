/*
 * _7_segments_2.c
 *
 * Created: 3/25/2023 12:43:53 PM
 *  Author: youssef's
 */ 
#include "seven_segments_one_port.h"
#include "../../MCAL/DIO/DIO_Interface.h"
//numbers display on PORT_D
char array1_one_port[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

//APIs
void SevenSegments2DisplayNumberOnePort(uint8 number){
	DIO_vWritePort(SEVEN_SEGMENTS_PORT,array1_one_port[number]);
}
