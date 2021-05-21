#include "ADC.h"


static u8 Reading_Flag=1;

void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler)
{
	// v ref
	switch( vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	//adjust reading right
	CLR_BIT(ADMUX,ADLAR);
	//prescaler
	ADCSRA=ADCSRA&0xf8;//0b11111000
	ADCSRA=ADCSRA|scaler;
	
	
//ADC enable
SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(ADC_Channel_type ch)
{
	//select channel
	ADMUX=ADMUX&0XE0;//0B11100000
	ADMUX=ADMUX|ch;
	
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	//
	while(READ_BIT(ADCSRA,ADSC));//busy wait polling
	//get read
	return ADC;
}

void ADC_StartConversion(ADC_Channel_type ch)
{
	if (Reading_Flag==1)
	{
		//select channel
		ADMUX=ADMUX&0XE0;//0B11100000
		ADMUX=ADMUX|ch;
		
		//start conversion
		SET_BIT(ADCSRA,ADSC);
		Reading_Flag=0;
	}
	
	
	
}
u16 ADC_GetRead(void)
{
		while(READ_BIT(ADCSRA,ADSC));//busy wait polling
		Reading_Flag=1;
		return ADC;
}
u8 ADC_GetReadNoBlock(u16*pdata)//periodic check
{
	if (READ_BIT(ADCSRA,ADSC)==0)
	{
		*pdata=ADC;
		Reading_Flag=1;
		return 1;
	}
	else
	{
		return 0;
	}
}

u16 ADC_GetReadFromInterrupt(void)
{
	return ADC;
}