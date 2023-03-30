/*
 * _7_segments_2.h
 *
 * Created: 3/25/2023 12:44:19 PM
 *  Author: youssef's
 */ 


#ifndef SEVEN_SEGMENTS_2_H_
#define SEVEN_SEGMENTS_2_H_
#include "../../LIB_FOLDER/common_macros.h"
#include "../../LIB_FOLDER/std_types.h"

#define SEVEN_SEGMENTS2_PORT            PORT_C





void SevenSegments2Init();
void SevenSegments2DisplayNumber(uint8 number);



#endif /* SEVEN_SEGMENTS_2_H_ */