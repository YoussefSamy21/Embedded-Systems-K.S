/*
 * ADC_interface.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Youssef Samy
 */

#include "ADC_interface.h"

static void(*ADC_Fptr)(void) = NULLPTR;

void ADC_INIT(ADC_Vref_type vref, ADC_SCALER_type scaler)
{
	// *****Vref******
	switch(vref)
	{
	case VREF_AVCC:
		CLEAR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;

	case VREF_AREF:
		CLEAR_BIT(ADMUX,REFS1);
		CLEAR_BIT(ADMUX,REFS0);
		break;
	case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	}

	ADCSRA = ADCSRA & 0xF8;
	ADCSRA = ADCSRA | scaler;

	// *****Right adjust******
	CLEAR_BIT(ADMUX,ADLAR);

	// *****Enable******
	SET_BIT(ADCSRA,ADEN);
}

/**************************************************************/

uint16 ADC_START_CONVERSION(ADC_CHANNEL_type channel)
{
	// *****Select Channel******
	ADMUX = ADMUX & 0xE0;	// same idea as the prescaler selection clearing the least 5 bits to avoid overwriting channels
	ADMUX = ADMUX | channel;

	// *****Start Conversion*****
	SET_BIT(ADCSRA,ADSC);

	while(GET_BIT(ADCSRA,ADSC)); //When the conversion is complete, it returns to zero

	return ADC;

}

void ADC_Interrupt_Enable()
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_Interrupt_Disable()
{
	CLEAR_BIT(ADCSRA,ADIE);
}

void ADC_SetCallBack(void(*LocalPtr)(void))
{
	ADC_Fptr = LocalPtr;
}
ISR(ADC_vect)
{
	if(ADC_Fptr != NULLPTR)
	{
		ADC_Fptr();
	}
}


// Periodic Check (No Block) , the aim of this function to not block or delaying the main function
uint8 ADC_GetRead_NoBlock(ADC_CHANNEL_type channel , uint16 *ptr_data)
{
	uint8 status;
	//select channel
	ADMUX = ADMUX & 0xE0;
	ADMUX = ADMUX | channel;
	//Start Conversion
	SET_BIT(ADCSRA,ADSC);
	if(GET_BIT(ADCSRA,ADSC)== 0) //When the conversion is complete, it returns to zero
	{
		*ptr_data = ADC;
		status = 1;
	}
	else
	{
		status = 0;
	}
	return status;
}


