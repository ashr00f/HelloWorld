//7 seg muutiplixer one button increment and decrement
int main(void)
{
	char i,f=0,f1=0,f2=0;
	int j;
    DDRB=0XFF;
	
	DDRD=0X00;
	DDRC=0xFF;
	PORTC=0xc0;
	DDRA=0xff;
	PORTD=0xFF;
	PORTB=0x00;
    while (1) 
 { 
	 if(!READ_BIT(PIND,2))
	 {
		  while(!READ_BIT(PIND,2));
		 f1=f1^1;
	 }
	 
	 
	  if(1==f1)
	{
		  while(1)
	  {
		    while(!READ_BIT(PIND,2));
		    f++;
	   for(j=0;j<500;j++)
		 {
			 if(!READ_BIT(PIND,2))
			 {
				 break;
				
			 }
		   segm_disp_mx(f);
		   
		   }
		   if (100==f)
		   {
			   f=0;
		   }
		   if(!READ_BIT(PIND,2))
		   {
			   break;
		   }
	  }
    }
	  
   if(0==f1)
    {
		while(1)
	  {
	    while(!READ_BIT(PIND,2));
		 if (0==f)
		 {
			 f=100;
		 }
		 
	    f--;
	    for(j=0;j<500;j++)
	    {
			if(!READ_BIT(PIND,2))
			{
				break;
				
			}
		    segm_disp_mx(f);
	    }
		if(!READ_BIT(PIND,2))
		{
			break;
		}
	 }
  }
	
}

}	
///////////////////////////////////////////////////////////
//set fun
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

//////////////////////////////////////////////////////////
# define WRITE_BIT(reg,bit,value) (reg=((reg&~(1<<bit))|(value<<bit)))

/////////////////////////////////////////////////////////
// control 8 led with 3 bins 
   while (1) 
 { 
	
	SET_BIT(PORTB,1);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
SET_BIT(PORTB,0);
_delay_ms(10);
CLR_BIT(PORTB,0);
CLR_BIT(PORTB,1);
		SET_BIT(PORTB,0);
		_delay_ms(10);
		CLR_BIT(PORTB,0);
		SET_BIT(PORTB,0);
		_delay_ms(10);
		CLR_BIT(PORTB,0);
			SET_BIT(PORTB,1);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	CLR_BIT(PORTB,1);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	 SET_BIT(PORTB,2);
	 _delay_ms(10);
	 CLR_BIT(PORTB,2);
	 _delay_ms(300);
	
}
/////////////////////////////////////////////////////
   while (1) 
 { 
	
	SET_BIT(PORTB,1);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
SET_BIT(PORTB,0);
_delay_ms(10);
CLR_BIT(PORTB,0);

CLR_BIT(PORTB,1);
		SET_BIT(PORTB,0);
		_delay_ms(10);
		CLR_BIT(PORTB,0);
		SET_BIT(PORTB,0);
		_delay_ms(10);
		CLR_BIT(PORTB,0);
			SET_BIT(PORTB,1);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	CLR_BIT(PORTB,1);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	SET_BIT(PORTB,0);
	_delay_ms(10);
	CLR_BIT(PORTB,0);
	 SET_BIT(PORTB,2);
	 _delay_ms(10);
	 CLR_BIT(PORTB,2);
	 _delay_ms(300);
	 
	 SET_BIT(PORTB,1);
	 SET_BIT(PORTB,0);
	 _delay_ms(10);
	 CLR_BIT(PORTB,0);
	  CLR_BIT(PORTB,1);
	   SET_BIT(PORTB,0);
	   _delay_ms(10);
	   CLR_BIT(PORTB,0);
	    SET_BIT(PORTB,1);
	    SET_BIT(PORTB,0);
	    _delay_ms(10);
	    CLR_BIT(PORTB,0);
	    CLR_BIT(PORTB,1);
	    SET_BIT(PORTB,0);
	    _delay_ms(10);
	    CLR_BIT(PORTB,0);
			 SET_BIT(PORTB,1);
			 SET_BIT(PORTB,0);
			 _delay_ms(10);
			 CLR_BIT(PORTB,0);
			 CLR_BIT(PORTB,1);
			 SET_BIT(PORTB,0);
			 _delay_ms(10);
			 CLR_BIT(PORTB,0);
			 SET_BIT(PORTB,1);
			 SET_BIT(PORTB,0);
			 _delay_ms(10);
			 CLR_BIT(PORTB,0);
			 CLR_BIT(PORTB,1);
			 SET_BIT(PORTB,0);
			 _delay_ms(10);
			 CLR_BIT(PORTB,0);
	 SET_BIT(PORTB,2);
	 _delay_ms(10);
	 CLR_BIT(PORTB,2);
	 _delay_ms(300);
	 
	
}  
//////////////////////////////////////////
// 7seg BCD switch inc & dec with 1 button
   while (1) 
 { 
	     if(!READ_BIT(PIND,2))
		   {
			   while(!READ_BIT(PIND,2));
			   f1=f1^1;
		   }
		   
		   
		   if(1==f1)
		   {
			   while(1)
			   {
					   segm_disp_bcd(f);
					   _delay_ms(300);
					   
					   f++;
				   if (100==f)
				   {
					   f=0;
				   }
				   if(!READ_BIT(PIND,2))
				   {
					   break;
				   }
			   }
		   }
		   
		   if(0==f1)
		   {
			   while(1)
			   {
				    segm_disp_bcd(f);
					_delay_ms(300);
					 
					
				   if (0==f)
				   {
					   f=100;
				   }   
				    f--;
				   if(!READ_BIT(PIND,2))
				   {
					   break;
				   }
			   }
		   }
		   
	   
	

}
