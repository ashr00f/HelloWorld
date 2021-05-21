
#include "KeyPad.h"


/*****************************************************************/
static u8 KeysArray[ROWS][COLS]= {{'7','8','9','/'},
						          {'4','5','6','*'},
							      {'1','2','3','-'},
						          {'c','0','=','+'}};
/*****************************************************************/


u8 KEYPAD_GetEntry(void)
{
	u8 r,c,key=NO_KEY;
	DIO_WritePin(FIRST_OUT,HIGH);
	DIO_WritePin(FIRST_OUT+1,HIGH);
	DIO_WritePin(FIRST_OUT+2,HIGH);
	DIO_WritePin(FIRST_OUT+3,HIGH);
	
	for (r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUT+r,LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_ReadPin(FIRST_IN+c)==LOW)
			{
				key= KeysArray[r][c];
				while(DIO_ReadPin(FIRST_IN+c)==LOW);
			}
		}
		DIO_WritePin(FIRST_OUT+r,HIGH);
	}
	
	return key;

}