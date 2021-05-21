/* ADC_StartConversion(CH_0);
	 //some code
	 if(ADC_GetReadNoBlock(&x))
	 {
		 LCD_SetCursor1(0,0);
		 LCD_WriteNumber(x);
	 }*/
	 
	/* x=ADC_Read(CH_0);
	  LCD_SetCursor1(1,0);
	  LCD_WriteNumber_4D(((u32)x*5000/1024));
	
		key=KEYPAD_GetEntry();
		if (key!=NO_KEY)
		{
			
			if (key>='0'&&key<='9')
			{
				if (flag==0)
				{
					
					LCD_ClearCells(0,2,5);
					LCD_SetCursor(0,2);
					LCD_WriteNumber_4D(num);
					num=0;
					flag=1;
				}
				
				LCD_WriteChar(key);
				num=num*10+key-'0';
			}
			if (key=='=')
			{
				LCD_SetCursor(1,2);
				LCD_WriteBinary(num);
				LCD_SetCursor(1,12);
				LCD_WriteNumber_4D(num/2);
				
				flag=0;
				LCD_SetCursor(0,2);
				
			}
			if (key=='c')
			{
				LCD_Clear();
				num=0;
			}
			if (key=='*')
			{
				
			}
			
			
		} 
	
	
/*	 _delay_ms(200);
if(x<300)
{
DIO_writePin(PINC0,HIGH);
DIO_writePin(PINC1,HIGH);
DIO_writePin(PINC2,HIGH);
}
else if(x>300&&x<350)
{
	DIO_writePin(PINC0,HIGH);
	DIO_writePin(PINC1,HIGH);
	DIO_writePin(PINC2,LOW);
}
else if(x>350&&x<400)
{
	DIO_writePin(PINC0,HIGH);
	DIO_writePin(PINC1,LOW);
	DIO_writePin(PINC2,LOW);
}
else if(x>400)
{
	DIO_writePin(PINC0,LOW);
	DIO_writePin(PINC1,LOW);
	DIO_writePin(PINC2,LOW);
}
*/
