/*
 * _7_segments.h
 *
 * Created: 3/25/2023 12:12:00 PM
 *  Author: youssef's
 */ 


#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"
#define SEVEN_SEGMENTS_PORT            PORT_D





void SevenSegmentsInit();
void SevenSegmentsDisplayNumber(uint8 number);




#endif /* SEVEN_SEGMENTS_H_ */