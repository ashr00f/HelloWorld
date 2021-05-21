
#define  F_CPU  8000000
#include <util/delay.h>
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#define  delay 300
/*
typedef enum{
	sc_1,
	sc_2,
	sc_3
	
	}scaler_type;
typedef enum{
	vref_avcc,
	vref_aref,
	vref_256
	
}vref_type;

typedef struct{
	scaler_type scaler;
	vref_type vref;

	}ADC_Init_type; 

void ADC_Init(ADC_Init_type*Pinit_struct)
{
	switch(Pinit_struct->scaler)
	{
		
	}
	switch(Pinit_struct->vref)
{
}
	
}

ADC_Init_type s1=
{    sc_2,
	vref_aref};
ADC_Init_type s2=
{    sc_1,
vref_avcc};*/
int main(void)
{
	DIO_Init();
	LCD_Init();
	u8 arr[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	Create_Character(arr,3);
	LCD_WriteChar(3);
	u8 k='A',flag=0;
	u16 num=0;
	//LCD_WriteString("TEST KEYPAD");
	LCD_SetCursor(0,0);
	LCD_WriteString("D:");
	
	LCD_CursorWriteString(1,0,"B:");
	LCD_SetCursor(0,2);
	while(1)
	{
		k=KEYPAD_GetEntry();
		if (k!=NO_KEY)
		{
			
			if (k>='0'&&k<='9')
			{
				if (flag==0)
				{
					
					LCD_ClearCells(0,2,5);
					LCD_SetCursor(0,2);
					LCD_WriteNumber_4D(num);
					num=0;
					flag=1;
				}
				
				LCD_WriteChar(k);
				num=num*10+k-'0';
			}
			if (k=='=')
			{
				LCD_SetCursor(1,2);
				LCD_WriteBinary(num);
				LCD_SetCursor(1,12);
				LCD_WriteNumber_4D(num/2);
				
				flag=0;
				LCD_SetCursor(0,2);
					
			}
			if (k=='c')
			{
				LCD_Clear();
				num=0;
			}
			if (k=='*')
			{
				
			}
			
			
		}
	}	
	
}

