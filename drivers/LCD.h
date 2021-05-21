
#ifndef LCD_H_
#define LCD_H_

#define  F_CPU   16000000
#include <util/delay.h>
#include "StdTypes.h"
#include "DIO_Interface.h"

#define  _4_BIT   0
#define  _8_BIT   1


/***************************************************/
#define  LCD_MODE   _4_BIT



#define  RS         PINA1
#define  EN         PINA2
#define  LCD_PORT   PA

#define  D7   PINA6
#define  D6   PINA5
#define  D5   PINA4
#define  D4   PINA3




void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumber(u64 num);
void LCD_WriteString(const char*str);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);
void LCD_WriteNumber_4D(u16 num);


void LCD_Clear(void);
void LCD_SetCursor(u8 line ,u8 cell);
void Create_Character(u8 *Pattern,u8 Location);
void LCD_GoTo(u8 line,u8 x);


void LCD_CursorWriteString(u8 line,u8 cell,u8*str);
void LCD_ClearCells(u8 line,u8 cell,u8 num);

#endif /* LCD_H_ */