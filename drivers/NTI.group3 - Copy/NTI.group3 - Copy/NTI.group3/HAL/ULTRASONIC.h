

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "DIO_Interface.h"
#include "Timers.h"

#define  F_CPU  8000000
#include <util/delay.h>

typedef enum{
	ULTRA_1=PINC1,
	ULTRA_2=PINC2,
	ULTRA_3=PINC7,
	ULTRA_4=PINC4
	}ULTRASONIC_type;



void ULTRASONIC_Init(void);
u16 ULTRASONIC_GetDistance(ULTRASONIC_type ultra);

void ULTRASONIC_Start(void);
u8 ULTRASONIC_GetDistance_NoBlock(u16*pdistance);

#endif /* ULTRASONIC_H_ */