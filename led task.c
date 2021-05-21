# include "MemoryMap.h"
# define F_CPU 8000000
# include <util/delay.h>
#define delay 200
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
				    while(1)
				   {
					   if(!READ_BIT(PIND,2))
					   {
						   break;
					   }
					 
					    PORTB<<=1;
						_delay_ms(delay);
					    if(PORTB==0)
					    {
						    PORTB=0x01;
							_delay_ms(delay);
							
					    }
				    } 
				   }
				 
		if(!READ_BIT(PIND,2))
		{ 
				while(!READ_BIT(PIND,2));

			while(1)
			{
				if(!READ_BIT(PIND,2))
				{
					break;
				}
		   PORTB>>=1;
		   			   _delay_ms(delay);

		   if(PORTB==0)
		   {
			   PORTB=0x80;
			    _delay_ms(delay);
		   }
		}
		}
	}
			
}
////////////////////////////////////////////////////
# include "MemoryMap.h"
# define F_CPU 8000000
# include <util/delay.h>
#define delay 200
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
	
		while(!READ_BIT(PIND,2))
		       {
				_delay_ms(delay);
		 	    PORTB<<=1;
			    if(PORTB==0)
			    {
			    PORTB=0x01;						
			    }
			   } 	 
		while(!READ_BIT(PIND,3))
		{ 
			_delay_ms(delay);
		   PORTB>>=1;
		   if(PORTB==0)
		   {
			   PORTB=0x80;
		   }
		}
	}
			
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


