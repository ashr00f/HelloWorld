
#include "MOTOR.h"

void MOTOR_CW(MOTOR_type motor)
{
	if (motor==M1)
	{
		DIO_WritePin(IN1,HIGH);
		DIO_WritePin(IN2,LOW);
	}
	else if (motor==M2)
	{
		DIO_WritePin(IN3,HIGH);
		DIO_WritePin(IN4,LOW);
	}
	
	
}

void MOTOR_CCW(MOTOR_type motor)
{
	DIO_WritePin(IN1,LOW);
	DIO_WritePin(IN2,HIGH);
}
void MOTOR_Stop(MOTOR_type motor)
{
	DIO_WritePin(IN1,LOW);
	DIO_WritePin(IN2,LOW);
}