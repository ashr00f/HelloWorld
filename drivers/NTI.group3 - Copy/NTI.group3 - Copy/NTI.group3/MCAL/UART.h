
#ifndef UART_H_
#define UART_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"


void UART_Init(void);

void UART_SendByte(u8 data);
u8 UART_ReceiveByte(void);





#endif /* UART_H_ */