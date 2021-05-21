
#define  F_CPU  8000000
#include <util/delay.h>
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "ADC.h"
#define  delay 300
#include "EX_Interrupt.h"
#include "Timers.h"
#include "ULTRASONIC.h"
#include "UART.h"
#include "UART_Services.h"
#include "SPI.h"
#include "WDT.h"

u16 TEMP_Read(void){	u16 adc=ADC_Read(CH_0);	u16 volt =((u32 )5000*adc)/1024;	u16 temp = volt;	return temp;}


int main(void)
{
	
	//SLAVE
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	UART_Init();
	//sei();
		
	u8 x=0,y='1',z;
		LCD_WriteString("Slave ");
	SPI_InitSlave();
	

	while(1)
	{
		
		LCD_SetCursor(0,10);
		LCD_WriteNumber(x);
		x++;
		if (x==10)
		{
			x=0;
		}
		z=SPI_SendReceive(y);
		LCD_SetCursor(1,0);
		LCD_WriteChar(z);
		_delay_ms(200);
		
	}	
	
}


/*
ISR(TIMER0_OVF_vect)
{
	static u8 flag=0;
	if (flag==0)
	{
		DIO_WritePin(PINC0,HIGH);
		TCNT0=196;
		flag=1;
	}
	else if (flag==1)
	{
		DIO_WritePin(PINC0,LOW);
		TCNT0=116;
		flag=0;
	}
	
}*/
/*
ISR(TIMER0_OVF_vect)
{
	static u8 c=0;
	TCNT0=6;
	c++;
	if (c%20==0)
	{
		DIO_TogglePin(PINC0);
	}
	if (c%40==0)
	{
		DIO_TogglePin(PINC1);
	}
	if (c%100==0)
	{
		DIO_TogglePin(PINC2);
	}
	if (c==200)
	{
		c=0;
	}
	
	
}

ISR(TIMER0_OVF_vect)
{
	static u8 c=0,c2=0;
	TCNT0=6;
	c2++;
	if (c2==20)
	{
		c++;
		c2=0;
		DIO_TogglePin(PINC0);
		if (c%2==0)
		{
			DIO_TogglePin(PINC1);
		}
		if (c%5==0)
		{
			DIO_TogglePin(PINC2);
		}
		if (c==10)
		{
			c=0;
		}
	}
	
		
	
	
}*/