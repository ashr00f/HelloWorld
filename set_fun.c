# define DDRAA  0
# define PORTAA 1
# define DDRBB 2
# define PORTBB 3
# define DDRCC 4
# define PORTCC 5
# define DDRDD 6
# define PORTDD 7

void SET_BIT_F(unsigned char reg_num,unsigned char pin)
{
	switch (reg_num)
	{
		case 0 :
		    DDRA=DDRA|(1<<pin);
		break;
		case 1 :
			PORTA=PORTA|(1<<pin);
		break;
		case 2 :
			DDRB=DDRB|(1<<pin);
		break;
		case 3 :
		PORTB=PORTB|(1<<pin);
		break;
		case 4 :
		DDRC=DDRC|(1<<pin);
		break;
		case 5 :
		PORTC=PORTC|(1<<pin);
		break;
		case 6 :
		DDRD=DDRD|(1<<pin);
		break;
		case 7 :
		PORTD=PORTD|(1<<pin);
		break;
	} 
	
}
