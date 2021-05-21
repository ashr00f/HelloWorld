

#include "UART_Services.h"

#include "LCD.h"


void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_SendByte(str[i]);
	}
}

void UART_ReceiveString(u8*str)
{
 u8 i=0;
 str[i]=UART_ReceiveByte();
	for (;str[i]!=13;)
	{
		i++;
		str[i]=UART_ReceiveByte();
	}
	str[i]=0;	

}


void UART_SendNumber(u32 num)
{
	UART_SendByte((u8)num);
	UART_SendByte((u8)(num>>8));
	UART_SendByte((u8)(num>>16));
	UART_SendByte((u8)(num>>24));
/*	u8*p=(u8*)&num;
	UART_SendByte(p[0]);
	UART_SendByte(p[1]);
	UART_SendByte(p[2]);
	UART_SendByte(p[3]);*/
	
}
u32 UART_ReceiveNumber(void)
{
	u8 b1=UART_ReceiveByte();
	u8 b2=UART_ReceiveByte();
	u8 b3=UART_ReceiveByte();
	u8 b4=UART_ReceiveByte();
	u32 num =b1|(u32)b2<<8|(u32)b3<<16|(u32)b4<<24;
	/*
	u32 num;
	u8*p=(u8*)&num;
	p[0]=UART_ReceiveByte();
	p[1]=UART_ReceiveByte();
	p[2]=UART_ReceiveByte();
	p[3]=UART_ReceiveByte();*/
	return num;
}



void UART_SendStringCheckSum(u8*str)
{
	u8 i,l=0;
	u16 sum=0;
	for (l=0;str[l];l++);
	UART_SendByte(l);
	for (i=0;str[i];i++)
	{
		UART_SendByte(str[i]);
		sum+=str[i];
	}
	UART_SendByte(sum);
	UART_SendByte(sum>>8);

}
u8 UART_ReceiveStringCheckSum(u8*str)
{
	u16 sum_rece=0,sum_cal=0;
	u8 i=0, lens=UART_ReceiveByte();
	for (i=0;i<lens;i++)
	{
		str[i]=UART_ReceiveByte();
		sum_cal+=str[i];
	}
	u8 b1=UART_ReceiveByte();
	u8 b2=UART_ReceiveByte();
	sum_rece=b1|(u16)b2<<8;
	/***********************************/
	LCD_SetCursor(0,4);
	LCD_WriteNumber(lens);
	LCD_WriteChar('-');
	LCD_WriteNumber(sum_rece);
	LCD_WriteChar('-');
	LCD_WriteNumber(sum_cal);
	
	
	sum_cal++;
	
	if (sum_cal==sum_rece)
	{
		return 1;
	}
	return 0;
}