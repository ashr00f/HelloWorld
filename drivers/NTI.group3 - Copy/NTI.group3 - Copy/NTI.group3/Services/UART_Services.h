
#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_


#include "UART.h"

void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);
void UART_SendNumber(u32 num);
u32 UART_ReceiveNumber(void);




void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);

#endif /* UART_SERVICES_H_ */