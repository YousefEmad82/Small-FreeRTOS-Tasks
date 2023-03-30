/*
 * SEVEN_SEGMENTS_ONE_PORT_H_
 *
 * Created: 3/25/2023 12:12:00 PM
 *  Author: yousef
 */ 


#ifndef SEVEN_SEGMENTS_ONE_PORT_H_
#define SEVEN_SEGMENTS_ONE_PORT_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"
#define SEVEN_SEGMENTS_PORT            PORT_D





void SevenSegmentsInitOnePort(void);
void SevenSegmentsDisplayNumberOnePort(uint8 number);
void SevenSegments2DisplayNumberOnePort(uint8 number);



#endif /* SEVEN_SEGMENTS_ONE_PORT_H_ */
