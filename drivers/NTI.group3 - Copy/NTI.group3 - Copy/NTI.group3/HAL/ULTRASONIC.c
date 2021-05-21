
#include "ULTRASONIC.h"

static volatile u16 t1,t2,t3,flag=0;
u8 Reading_flag=1;
static void Func_ICU(void);
void ULTRASONIC_Init(void)
{
	Timer1_ICU_SetCallBack(Func_ICU);
}


u16 ULTRASONIC_GetDistance(ULTRASONIC_type ultra)
{
	
	u16 d,time;
	flag=0;
	TCNT1=0;
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	
	DIO_WritePin(ultra,HIGH);
	_delay_us(10);
	DIO_WritePin(ultra,LOW);
	while(flag<2);
	time=t2-t1;
	d=time/58;
	return d;
	
}

void ULTRASONIC_Start(void)
{
	
	if (flag==0)
	{
		
		flag=1;
		TCNT1=0;
		Timer1_InputCaptureEdge(RISING);
		Timer1_ICU_InterruptEnable();
		
		DIO_WritePin(PINC1,HIGH);
		_delay_us(10);
		DIO_WritePin(PINC1,LOW);
		
	}
	
}

u8 ULTRASONIC_GetDistance_NoBlock(u16*pdistance)
{
	
	u16 d,time;
	
	
	if (flag==3)
	{
		time=t2-t1;
		d=time/58;
		*pdistance=d;
		flag=0;
		return 1;
	}
	return 0;
	
}
static void Func_ICU(void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_ICU_InterruptDisable();
		flag=2;
	}
	
}