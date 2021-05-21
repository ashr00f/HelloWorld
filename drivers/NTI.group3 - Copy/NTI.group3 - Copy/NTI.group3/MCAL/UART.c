

#include "UART.h"


void UART_Init(void)
{
	//frame 
	//NORMAL SPEED
	CLR_BIT(UCSRA,U2X);
	//baud rate  9600  normal speed
	UBRRL=51;
	//ENABLE
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}

void UART_SendByte(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE)); //busy w8
	UDR=data;
}
u8 UART_ReceiveByte(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}