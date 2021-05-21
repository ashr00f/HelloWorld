
	u8 i,a=255;

	DIO_Init();
	LCD_Init();
/*	LCD_SetCursor1(0,0);
	LCD_WriteString("Char:");
	LCD_SetCursor1(1,0);
	LCD_WriteString("ASCI:");
	/*
	 new_item_set(arr_man,0);
	 new_item_set(arr_deadman,1);
	 LCD_SetCursor1(1,1);
	   LCD_WriteChar(0);
	    LCD_SetCursor1(1,16);
	    LCD_WriteChar(0);
		 for(i=3;i<=16;i++)
		 {
			 LCD_SetCursor1(1,i);
			 LCD_WriteChar(126);
			  LCD_SetCursor1(1,i-1);
			   LCD_WriteChar(128);
			 _delay_ms(300);		 
		 }
		 LCD_SetCursor1(1,16);
		 LCD_WriteChar(1);
		 */
 while (1)
 {
	 
	/* LCD_SetCursor1(0,5);
	 LCD_WriteChar(a);
	 _delay_ms(300);
	 LCD_SetCursor1(1,5);
	 LCD_WriteHex(a);
	 LCD_WriteString("   ");
	 _delay_ms(300);
	 a--;
	 if('A'==a)
	 {
		 a='0';
	 }
	*/
	animation1("WE WON !!!");
}