
#ifndef SEGMENT_H_
#define SEGMENT_H_

#define  F_CPU   8000000
#include <util/delay.h>
#include "DIO_Interface.h"
#define  MPX    0
#define  NORMAL 1
#define  BCD    2

/*******************pin config*******************/

#define   SEGMENT_MODE    BCD

#define   SEGMENT_PORT      PB
#define   SEGMENT_PORT2     PA

#define    S_EN1    PINC6
#define    S_EN2    PINC7

void SEGMENT_Display(u8 num);




#endif /* SEGMENT_H_ */