
#include "SEGMENT.h"


static u8 SegNumbers[]={ 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

#if (SEGMENT_MODE==NORMAL)
void SEGMENT_Display(unsigned char n)
{
	unsigned char x=n%10;
	unsigned char y=n/10;
	
	DIO_WritePort(SEGMENT_PORT,SegNumbers[x]);
	DIO_WritePort(SEGMENT_PORT2,SegNumbers[y]<<1);

}
#elif (SEGMENT_MODE==MPX)
void SEGMENT_Display(unsigned char n)
{
	unsigned char x=n%10;
	unsigned char y=n/10;
	 DIO_WritePin(S_EN1,HIGH);
     DIO_WritePin(S_EN2,LOW);
	DIO_WritePort(SEGMENT_PORT,SegNumbers[y]);
	_delay_ms(1);
	DIO_WritePin(S_EN1,LOW);
	DIO_WritePin(S_EN2,HIGH);
	DIO_WritePort(SEGMENT_PORT,SegNumbers[x]);
	_delay_ms(1);
}
#else
void SEGMENT_Display(unsigned char n)
{
	unsigned char x=n%10;
	unsigned char y=n/10;
	
	DIO_WritePort(SEGMENT_PORT,x|y<<4);
}
#endif