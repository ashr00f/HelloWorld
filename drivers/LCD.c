
#include "LCD.h"

#if (LCD_MODE==_8_BIT)
static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);// set 8 bit mode ,font 5*7
	LCD_WriteCommand(0x0c);// cursor off  0x0f,0x0e
	LCD_WriteCommand(0x01);//clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);// increase DDRAM address

}
#elif (LCD_MODE==_4_BIT)
static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);// set 8 bit mode ,font 5*7
	LCD_WriteCommand(0x0c);// cursor off  0x0f,0x0e
	LCD_WriteCommand(0x01);//clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);// increase DDRAM address

}
#endif
/*******************************************************************/
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteNumber(u64 num)
{
	u8 i=0,arr[10],j;
	if(num==0)
	LCD_WriteData('0');
	else{
			while(num)
			{
				arr[i]=num%10+'0';
				num/=10;
				i++;
			}
			for(j=i;j>0;j--)
			{
				LCD_WriteData(arr[j-1]);
			}
		}
}
void LCD_WriteString(const char*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteData(str[i]);
	}
}

void LCD_WriteBinary(u8 num)
{		for(s8 i=7; i>=0; i--)		{			if((num>>(i))&1)			{				LCD_WriteChar('1');			}			else			{				LCD_WriteChar('0');			}		}
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
	_delay_ms(1);
}
void LCD_SetCursor(u8 line ,u8 cell)
{
	if (line==0)
	{
		LCD_WriteCommand(0x80+cell);
	}
	else if (line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);
	}
}
void LCD_WriteHex(u8 num)
{
	u8 low=num&0x0f;
	u8 high=num>>4;
	u8 hex[16]={'0','1','A','B'};
	if (high<=9)
	{
		LCD_WriteData(high+'0');
	}
	else
	{
		LCD_WriteData(high-10+'A');
	}
	LCD_WriteData(hex[high]);
	LCD_WriteData(hex[low]);
	
	
}

void Create_Character(u8 *Pattern,u8 Location)
{
	LCD_WriteCommand(0x40+Location*8);
	for (u8 i=0;i<8;i++)
	{
		LCD_WriteData(Pattern[i]);
	}
	LCD_WriteCommand(0x80);
}


void LCD_WriteNumber_4D(u16 num)
{
	
	LCD_WriteData(num%10000/1000+'0');	LCD_WriteData(num%1000/100+'0');	LCD_WriteData(num%100/10+'0');	LCD_WriteData(num%10/1+'0');

}

void LCD_CursorWriteString(u8 line,u8 cell,u8*str)
{
	LCD_SetCursor(line,cell);
	LCD_WriteString(str);
}

void LCD_ClearCells(u8 line,u8 cell,u8 num)
{
	LCD_SetCursor(line,cell);
	for (u8 i=0;i<num;i++)
	{
		LCD_WriteChar(' ');
	}
}