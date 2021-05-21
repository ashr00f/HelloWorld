/*
 * UART_Services.h
 *
 * Created: 3/31/2021 1:21:43 AM
 *  Author: Shima'
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"



void UART_SendByte(u8 data);
u8 UART_RecieveByte(void);
u8 UART_RecieveByte_Periodic(u8*pdata);
void UART_SendString(u8*str);
void UART_RecieveString(u8*str);
void UART_SendNumber(u32 num);
u32 UART_RecieveNumber(void);
void UART_SendStringCheckSum(u8*str);
u8 UART_RecieveStringCheckSum(u8*str);
u8 UART_controldev(u8*str);
u8 strCompareFaster(u8 *str1, u8 *str2);
void String_cutting(u8*str,u8*str1,u8*num);



#endif /* UART_SERVICES_H_ */