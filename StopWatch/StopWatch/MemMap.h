/*
 * MemMap.h
 *
 *  Created on: Mar 3, 2021
 *      Author: Administrator
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_



#define SET_BIT(VAR,BITNO)				(VAR)|=(1<<(BITNO))
#define CLR_BIT(VAR,BITNO)				(VAR)&=~(1<<(BITNO))
#define TOG_BIT(VAR,BITNO) 				(VAR)^=(1<<(BITNO))
#define GET_BIT(VAR,BITNO)    			((VAR>>BITNO)&1)


/*****************************************************************************/
/***************		Macros for PORTA		******************************/
#define DDRA							*((volatile unsigned char*)0x3A)
#define PORTA   						*((volatile unsigned char*)0x3B)
#define PINA    						*((volatile unsigned char*)0x39)
/***************		Macros for PORTB		******************************/
#define DDRB		            		*((volatile unsigned char*)0x37)
#define PORTB   						*((volatile unsigned char*)0x38)
#define PINB    						*((volatile unsigned char*)0x36)
/***************		Macros for PORTC		******************************/
#define DDRC    						*((volatile unsigned char*)0x34)
#define PORTC   						*((volatile unsigned char*)0x35)
#define PINC    						*((volatile unsigned char*)0x33)
/***************		Macros for PORTD		******************************/
#define DDRD    						*((volatile unsigned char*)0x31)
#define PORTD   						*((volatile unsigned char*)0x32)
#define PIND    						*((volatile unsigned char*)0x30)
/*****************************************************************************/

#endif /* MEMMAP_H_ */
