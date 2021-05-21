volatile u8 c=0;//response time calculation
main()
{
TCCR0=0x01;	
SET_BIT(TIMSK,TOIE0);
c=0; 
TCNT0=0;
_delay_us(256);
x=TCNT0;
y=c;
}
ISR(TIMER0_OVF_vect)
{
	c=TCNT0;
	
}
///////////////////////////////////////
	volatile u32 c=0;//calculate code time in ms

int main(void)
{ 
	u32 x,y;
	
sei();
	DIO_Init();
	LCD_Init();
	LCD_SetCursor1(0,0);
	//ADC_Init(VREF_AVCC,ADC_SCALER_64);
	TCCR0=0x02;	
SET_BIT(TIMSK,TOIE0);
c=0; 
TCNT0=0;
_delay_us(300);
LCD_WriteString("Ay7agabtlf3alalfady");
x=(TCNT0+(c*256)-(5*256))/1000;
y=c;

LCD_SetCursor1(1,0);
LCD_WriteNumber(x);
LCD_SetCursor1(1,6);
LCD_WriteNumber(y);
}
ISR(TIMER0_OVF_vect)
{
	c++;
	
}
/////////////////////////////////////
