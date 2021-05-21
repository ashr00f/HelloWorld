/*
 * UART_Services.c
 *
 * Created: 3/31/2021 1:20:30 AM
 *  Author: Shima'
 */ 

#include "UART_Services.h"
#include "DIO_Interface.h"
void UART_SendByte(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));    //busy wait
	UDR=data;
}
u8 UART_RecieveByte(void)
{
	while(!READ_BIT(UCSRA,RXC));    //busy wait
	return UDR;
}
u8 UART_RecieveByte_Periodic(u8*pdata)  //PERIODIC
{
	if((READ_BIT(UCSRA,RXC)))
	{
		*pdata=UDR;
		return 1;
		
	}
	else
	return 0;
}

void UART_SendString(u8*str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		UART_SendByte(str[i]);
	}
	UART_SendByte(13);    //0d \r\n
	UART_SendByte(10); 
}
void UART_RecieveString(u8*str)
{
	u8 i=0;
	str[0]=UART_RecieveByte();
	for(i=0;str[i]!=10;)
	{
		i++;
		str[i]=UART_RecieveByte();
	}
	str[i]=0;
}
void UART_SendNumber(u32 num)

{
	UART_SendByte((u8)(num));
	UART_SendByte((u8)(num>>8));
	UART_SendByte((u8)(num>>16));
	UART_SendByte((u8)(num>>24));
	
}
u32 UART_RecieveNumber(void)
{
	u8 n1=UART_RecieveByte();
	u8 n2=UART_RecieveByte();
	u8 n3=UART_RecieveByte();
	u8 n4=UART_RecieveByte();
	u32 num=n1|((u32)n2<<8)|((u32)n3<<16)|((u32)n4<<24);
	return num;
}
void UART_SendStringCheckSum(u8*str) //send lens w data w check
{
	u8 l,i=0;
	u16 sum=0;
	for(l=0;str[l];l++);
	UART_SendByte(l);
  for(i =0;str[i];i++){
         UART_SendByte(str[i]);
		 sum+=str[i];
}
    UART_SendByte(sum);
	UART_SendByte(sum>>8);
}
u8 UART_RecieveStringCheckSum(u8*str)
{
	u8 len=UART_RecieveByte();
	u8 i=0;
	u16 sum_rec=0,sum_calc=0;
	for(i=0;i<len;i++)
	{
		str[i]=UART_RecieveByte();
		sum_calc+=str[i];
		
		
	}     
	u8 b1=UART_RecieveByte();
	u8 b2=UART_RecieveByte();
	sum_rec=b1|(u16)b2<<8;
	if(sum_calc==sum_rec)
	return 1;
else
return 0;


}

void String_cutting(u8*str,u8*str1,u8*num)
{
	u8 i;
	*num=0;
	
	for(i=0;str[i];i++)
	{
		if(str[i]!=' ')
		{
			str1[i]=str[i];
	    }
		else
		{
			 str1[i]=0;
			 i++;
			 break;
			
		}
	}
	 *num=str[i]-'0';	
}

u8 strCompareFaster(u8 *str1, u8 *str2){	u8 i = 0, flag = 1;	while ((str1[i] || str2[i]) && flag)	{		if (str1[i] != str2[i])		{			flag = 0;		}		i++;	}	return flag;}

u8 UART_controldev(u8*str)
{
	u8 arr[100];
	u8 num,flag=0;
String_cutting(str,arr,&num);
if(strCompareFaster(arr,"ledon"))
{
	switch(num)
	{
		case 1:
		DIO_WritePin(PINC0,HIGH);
		break;
		case 2:
		DIO_WritePin(PINC1,HIGH);
		break;
		case 3:
		DIO_WritePin(PINC2,HIGH);
		break;
		default:flag=1;
	}
}
else if(strCompareFaster(arr,"ledtog"))
{
	switch(num)
	{
		case 1:
		DIO_TogglePin(PINC0);
		break;
		case 2:
		DIO_TogglePin(PINC1);
		break;
		case 3:
		DIO_TogglePin(PINC2);
		break;
		default:flag=1;
		
	}
}
else if(strCompareFaster(arr,"ledoff"))
{
	switch(num)
	{
		case 1:
		DIO_WritePin(PINC0,LOW);
		break;
		case 2:
		DIO_WritePin(PINC1,LOW);
		break;
		case 3:
		DIO_WritePin(PINC2,LOW);
		break;
		default:flag=1;
		
	}
}
else{
flag=1;
}
return flag;
}