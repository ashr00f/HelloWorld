# include "MemoryMap.h"
# define F_CPU 8000000
# include <util/delay.h>

int main(void)
{
    DDRB=0XFF;
	
	DDRC=0X0F;
	
    while (1) 
    {
    char i;
		PORTB=0X01;
		_delay_ms(300);
		for(i=0;i<8;i++)
		{
		
		 PORTB=(1<<i);
			_delay_ms(300);	
		}
		//PORTB=0x80;
		_delay_ms(300);
		for(i=0;i<8;i++)
		{
			PORTB=(0x80>>i);
			_delay_ms(300);
		}

	}
}
/////////////////////////////////////////////////////////////
# include "MemoryMap.h"
# define F_CPU 8000000
# include <util/delay.h>

int main(void)
{
    DDRB=0XFF;
	
	DDRC=0X0F;
	
    while (1) 
    { char i;
		PORTB=0X00;
		_delay_ms(300);
		for(i=0;i<4;i++)
		{
		
		 PORTB=~PORTB;
			_delay_ms(300);	
		}
		PORTB=0x0F;
		_delay_ms(300);
		for(i=0;i<4;i++)
		{
			 PORTB=~PORTB;
			 _delay_ms(300);
		}
		
		PORTB=0x33;
		_delay_ms(300);
			for(i=0;i<4;i++)
			{
				 PORTB=~PORTB;
				 _delay_ms(300);
			}
			PORTB=0x55;
			_delay_ms(300);
			for(i=0;i<4;i++)
			{
				 PORTB=~PORTB;
				 _delay_ms(300);
			}
	}
}
/////////////////////////////////////////////////////////////
# include "MemoryMap.h"
# define F_CPU 8000000
# include <util/delay.h>

int main(void)
{
    DDRB=0XFF;
	
	DDRC=0X0F;
	
    while (1) 
    {

char i;
		PORTB=0X01;
		_delay_ms(300);
		for(i=1;i<=8;i++)
		{
		
		 PORTB=PORTB+(1<<i);
			_delay_ms(300);	
		}
		PORTB=0xFF;
		_delay_ms(300);
		for(i=0;i<8;i++)
		{
			PORTB=PORTB-(0x80>>i);
			_delay_ms(300);
		}
		
		    PORTB=0x81;
		    _delay_ms(300);
			for(i=1;i<4;i++)
			{
				PORTB=PORTB+(1<<i)+(0x80>>i);
				_delay_ms(300);
			}
			PORTB=0xFF;
			_delay_ms(300);
			for(i=4;i>0;i--)
			{
				PORTB=PORTB-(1<<(i-1))-(0x80>>(i-1));
				_delay_ms(300);
			}
				PORTB=0x81;
				_delay_ms(300);
				for(i=1;i<4;i++)
				{
					PORTB=PORTB+(1<<i)+(0x80>>i);
					_delay_ms(300);
				}
				PORTB=0xFF;
				_delay_ms(300);
				for(i=4;i>0;i--)
				{
					PORTB=PORTB-(1<<(i-1))-(0x80>>(i-1));
					_delay_ms(300);
				}
	}
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//set clear bits led
# include "MemoryMap.h"
# define F_CPU 8000000
# include <util/delay.h>
# define SET_BIT(reg,bit) (reg=reg|(1<<bit))
# define CLR_BIT(reg,bit) (reg=reg&~(1<<bit))
# define READ_BIT(reg,bit) ((reg>>bit)&1)
int main(void)
{
    DDRB=0XFF;
	
	DDRD=0X00;
	DDRC=0xFF;
	PORTD=0xFF;
	PORTB=0xFF;
    while (1) 
    { 
	
		if(! READ_BIT(PIND,2))
		{
			PORTB=SET_BIT(PORTB,0);
			PORTC=SET_BIT(PORTC,0);
		}
		else if (! READ_BIT(PIND,3))
		{
			PORTB=CLR_BIT(PORTB,0);
			PORTC=CLR_BIT(PORTC,0);
		}
		if( !READ_BIT(PIND,4))
		{
			PORTB=SET_BIT(PORTB,5);
			PORTC=SET_BIT(PORTC,1);
		}
		else if (! READ_BIT(PIND,5))
		{
			PORTB=CLR_BIT(PORTB,5);
			PORTC=CLR_BIT(PORTC,1);
		}
		
		
		
    }
	
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
if(!READ_BIT(PIND,3))
		{
			if(0==f1)
			{if(0x01==PORTB)
				{
					PORTB=0x80;
					
				}
				
				PORTB=PORTB>>1;
				f1=1;
				
			}
		}
		else
		{
			
			f1=0;
		}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
int main(void)
{
	char f=0,f1=0,f2=0;
    DDRB=0XFF;
	
	DDRD=0X00;
	DDRC=0xFF;
	PORTD=0xFF;
	PORTB=0x00;
    while (1) 
    { 
	
		if(!READ_BIT(PIND,2))
		       {
				   while(!READ_BIT(PIND,2));
				   PORTB<<=1;
				   if(PORTB==0)
				   {
					   PORTB=0x01;
				   }
			   }
		if(!READ_BIT(PIND,3))
		{
		 while(!READ_BIT(PIND,3));
		   PORTB>>=1;
		   if(PORTB==0)
		   {
			   PORTB=0x80;
		   }
		}
	}		


