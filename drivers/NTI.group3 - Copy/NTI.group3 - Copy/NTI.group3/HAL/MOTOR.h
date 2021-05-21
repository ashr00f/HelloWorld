
#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO_Interface.h"

/**********************pin config************************/
#define  IN1  PINC0
#define  IN2  PINC2

#define  IN3  PINC6
#define  IN4  PINC7


#define  MOTOR  M2
/********************************************************/
typedef enum{
	M1,
	M2,
	M3,
	M4
	}MOTOR_type;


void MOTOR_CW(MOTOR_type motor);
void MOTOR_CCW(MOTOR_type motor);
void MOTOR_Stop(MOTOR_type motor);
/*
void MOTOR2_CW(void);
void MOTOR2_CCW(void);
void MOTOR2_Stop(void);
*/
#endif /* MOTOR_H_ */