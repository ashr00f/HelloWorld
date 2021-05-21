
#include "SPI.h"


void SPI_InitMaster(void)
{
	//master 
	SET_BIT(SPCR,MSTR);
	//clock
	//F_CPU/4
	
	//enable
	SET_BIT(SPCR,SPE);
}
void SPI_InitSlave(void)
{
	CLR_BIT(SPCR,MSTR);
	
	
	SET_BIT(SPCR,SPE);
}


u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	
	while(!READ_BIT(SPSR,SPIF));

	return SPDR;
}

void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}

u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}

u8 SPI_Receive_Perodic(u8*pdata)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}

void SPI_InterruptEnable(void)
{
	SET_BIT(SPCR,SPIE);
}

u8 SPI_SendReceive_RunTimeOut(u8 data,u8*pdata_re,u8 time)
{
	SPDR=data;
	u16 c=0;
	while(!READ_BIT(SPSR,SPIF)&&(c<time))
	{
		c++;
		_delay_us(1);
	}
		if (READ_BIT(SPSR,SPIF))
		{
			*pdata_re=SPDR;
			return 1;
		}
			return 0;
}