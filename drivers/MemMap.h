/*
 * MemMap.h
 *
 * Created: 3/4/2021 3:28:23 PM
 *  Author: khaliid
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define DDRA (*(volatile unsigned char*)0X3A)
#define PINA (*(volatile unsigned char*)0X39)
#define PORTA (*(volatile unsigned char*)0X3B)

#define DDRB (*(volatile unsigned char*)0X37)
#define PINB (*(volatile unsigned char*)0X36)
#define PORTB (*(volatile unsigned char*)0X38)


#define DDRC (*(volatile unsigned char*)0X34)
#define PINC (*(volatile unsigned char*)0X33)
#define PORTC (*(volatile unsigned char*)0X35)

#define DDRD (*(volatile unsigned char*)0X31)
#define PIND (*(volatile unsigned char*)0X30)
#define PORTD (*(volatile unsigned char*)0X32)



#endif /* MEMMAP_H_ */