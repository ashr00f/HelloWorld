



#include "memorymap.h"
#include "Utils1.h"
#include "Stdtype.h"
#include "DIO_Interface.h"  
#include "MOTOR.h"
#define F_CPU   8000000
#include <util/delay.h>
#include "KeyPad.h"
#include "LC_4.h"
#include "ADC.h"
#include "Sensor.h"
#include "EX_Interrupt.h"
volatile u16 flag=0,c=0;
#include "Timer.h"
#include "UART.h"
#include "UART_Services.h"
void func(void)
{
	DIO_TogglePin(PINC0);
	_delay_ms(500);
	
}
int main ()
{
	u16 x=0,y,i=0,k,n,z;
	
	 sei();
		DIO_Init();
		LCD_Init_4();
		ADC_Init(VREF_AVCC,ADC_SCALER_64);
	/*	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
		EXI_Enable(EX_INT0);
		EXI_TriggerEdge(EX_INT1,RISING_EDGE);
		//EXI_Enable(EX_INT1);
		TIMER0_Init(TIMER0_CTC_MODE,TIMER0_SCALER_8);
		//TIMER0_OV_InterruptEnable();
		TIMER0_OC0Mode(OC0_TOGGLE);
		EXI_SetCallBack(EX_INT0,func);
	             
		//SET_BIT(TIMSK,TOIE0 );   //interupt flag ov & without it sys restart
		Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
		Timer1_OCRA1Mode(OCRB_NON_INVERTING);
		Timer1_OCRB1Mode(OCRB_NON_INVERTING);*/
		UART_init();
			u8 str[100];
			u8 str1[100];
			u8 s,num=0;
			u8 p=0;
			u32 f=0;
	
/*
		LCD_GOTO_4(0,0);
		UART_SendString("////shaimaa/////");	*/
/****************************SEND*****************/




/*
String_cutting("ledon 1",str1,&s);
LCD_GOTO_4(0,0);
LCD_WriteString_4(str1);
LCD_GOTO_4(0,7);
LCD_WriteNumber_4(s);
LCD_WriteNumber_4((u8)strCompareFaster(str1,"leddon"));*/


		while(1)       
		{
			UART_RecieveString(str);
			 p=UART_controldev(str) ;           //ledon 1
			
			if(p==1)
			{
			
			    LCD_Clear_4();
				LCD_GOTO_4(0,0);
				LCD_WriteString_4("error");
			}
			else
			{
				LCD_Clear_4();
				 LCD_GOTO_4(0,0);
				 String_cutting(str,str1,&num);
				 LCD_WriteString_4(str1);
				LCD_Writechar_4(' ');
				 LCD_WriteNumber_4(num);
			}
			
			
			/*UART_RecieveString(str);
			UART_SendStringCheckSum(str);
			LCD_GOTO_4(1,5);
			LCD_WriteString_4(str);
			*/
		
			
		
		
	
}
}
/*
ISR(TIMER0_OVF_vect)
{
	//static u16 c=0;
	c++;              //5/2=2.5/2=1.25
/*
	//c++;
	if(c%20==0)
	{
		DIO_TogglePin(PINC0);
	}
	if(c%40==0)
	{
		DIO_TogglePin(PINC1);
	}
	if(c%100==0)
	{
		DIO_TogglePin(PINC2);
	}
	if(c==200)
	c=0;*/

/*
ISR(TIMER0_OC_vect)
{
	
}*/




ISR(BAD_vect)
{
	DIO_TogglePin(PINC3);
}


/*
void func1(void)
{
	DIO_TogglePin(PINC0);
	flag=1;
}
void func2(void)
{
	DIO_TogglePin(PINC1);
	flag=1;
}


int main ()
{
	sei();
	DIO_Init();
	LCD_Init_4();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT1,RISING_EDGE);
	EXI_Enable(EX_INT1);
	LCD_WriteString_4("INTERUPT");
	//INT0_Fptr=func1; //kda hykon global w dh m4 s7 ay 7d y access
	 EXI_SetCallBack(EX_INT0,func1);
	_delay_ms(1000);
	LCD_Clear_4();
	
	while(1)
	{
		LCD_GOTO_4(0,10);
		LCD_WriteNumber_4(x);
		x++;
		_delay_ms(300);
		if(x==10)
		{
			EXI_SetCallBack(EX_INT0,func2);
			x=0;
		}
		if(x==5)
		{
			EXI_SetCallBack(EX_INT0,func1);
			
		}
		LCD_GOTO_4(0,0);
		LCD_WriteString_4("shaimaa");
		if(flag==1)
		{
			
			LCD_GOTO_4(1,0);
			LCD_WriteString_4("into");
		}
		if(flag==2)
		{
			LCD_GOTO_4(1,0);
			LCD_WriteString_4("int1");
		}
		
	}
}*/
	/*ISR(INT0_vect)
	{
		DIO_TogglePin(PINC0);
		x=9;
		flag++;
	}
	ISR(INT1_vect)
	{
		DIO_TogglePin(PINC1);
		x=0;
		flag=2;
	}*/
	
		
  
  
	/*ADC_Init(VREF_AVCC,ADC_SCALER_64);
	u8 k,op=0,flag=0,eqflag=0,negflag=0;//,OpFlag=0;
	f32 result=0,num3=0;
	f32 num1=0,num2=0;
	LCD_GOTO_4(0,6);
	LCD_WriteString_4("CASIO");
	while(1)
	{
		
		k=KEYPAD_GETENTRY();
		
		if(k>='0'&&k<='9'&&flag==0)
		{
			//OpFlag = 1;
			num1=num1*10+k-'0';
			if(negflag==1)
			{
				LCD_GOTO_4(0,1);
				LCD_WriteNumber_4(num1);
				negflag=0;
				num1*=-1;
			}
			else
			{
				LCD_Clear_4();
				LCD_GOTO_4(0,0);
				LCD_WriteNumber_4(num1);
				
			}
			eqflag=0;
			flag=1;	
		}*/
	/*	else if(eqflag==0&&flag==0&&k!='-')
		{
		
		}*/
		/*else if(k=='+'||k=='-'||k=='*'||k=='/' )
		{
			if(eqflag==1)
			{
				eqflag =0;
				LCD_Clear_4();
				num1=num3;
				//LCD_SetCursor(0,0);
				LCD_WriteFloat(num1);
				op=k;
				//LCD_SetCursor(0,5);
				LCD_Writechar_4(k);
				flag=1;
				
			}
			
			else if(eqflag==0&&flag==0&&k=='-')
			{
			
			    negflag=1;
			   // flag=1;
				//LCD_SetCursor(0,0);
				LCD_Writechar_4(k);
			
				
			}
			
			else
			{
				if(op=='+'||op=='-'||op=='*'||op=='/' )
				{
					LCD_ShiftCursorLeft();
				}
				op=k;
				//LCD_SetCursor(0,5);
				LCD_Writechar_4(k);
				flag=1;
			}
		}
		else if(k>='0'&&k<='9'&&flag==1)
		{
			if(op=='-'){
			num2=num2*10+k-'0';
			//LCD_GOTO_4(0,7);
			LCD_WriteNumber_4(k-'0');
			
			}
			else
			{
				num2=num2*10+k-'0';
				//LCD_GOTO_4(0,7);
				LCD_WriteNumber_4(num2);
			}
		}
		if(k=='=')
		{
			if(eqflag!=1)
			{
				LCD_GOTO_4(1,0);
				result=0;
				switch(op)
				{
					case '+':
					result=(num1+num2);
					LCD_WriteFloat(result);
					break;
					case '-':
					result=(s32)num1-(num2);
					LCD_WriteFloat(result);
					break;
					case '*':
					result=num1*num2;
					LCD_WriteFloat(result);
					break;
					case '/':
					if(num2==0)
					{
						LCD_WriteString_4("infinity");
					}
					else
					{
						result=(f32)num1/num2;
						LCD_WriteFloat(result);
					}
					break;
					default:
					LCD_WriteString_4("ERROR");
					break;
				}
				num1=0;
				num2=0;
				num3=result;
				eqflag=1;
				flag=0;
				op=0;
				//OpFlag=1;
			}	
		}
		if(k=='c')
		{
			LCD_Clear_4();
			LCD_GOTO_4(0,0);
			num1=0;
			num2=0;
			num3=0;
			eqflag=0;
			flag=0;
			op=0;
			//OpFlag=0;
		}
	}
	}*/







	


	

	
		

	
	


