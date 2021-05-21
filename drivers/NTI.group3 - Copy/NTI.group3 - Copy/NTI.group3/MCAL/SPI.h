
#ifndef SPI_H_
#define SPI_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"


void SPI_InitMaster(void);
void SPI_InitSlave(void);

u8 SPI_SendReceive(u8 data);
u8 SPI_Receive_Perodic(u8*pdata);
u8 SPI_ReceiveNoBlock(void);
void SPI_SendNoBlock(u8 data);

void SPI_InterruptEnable(void);

#endif /* SPI_H_ */