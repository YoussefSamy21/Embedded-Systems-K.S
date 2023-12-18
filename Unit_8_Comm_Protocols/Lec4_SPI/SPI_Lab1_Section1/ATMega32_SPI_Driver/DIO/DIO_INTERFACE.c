/*
 * DIO_INTERFACE.c
 *
 *  Created on: Sep 16, 2022
 *      Author: youssef
 */

#include "DIO_INTERFACE.h"

void DIO_uint8SetDirectionPIN(PORT_NAME Copy_Port,PIN_NAME Copy_Pin,PIN_DIR Copy_Dir)
{
	uint8 DIO_L_ErrorCode;
	if (Copy_Pin>=0 && Copy_Pin<=7)
	{
		if (Copy_Dir==PIN_OUTPUT)
			{
				switch(Copy_Port)
				{
					case PORT_A: SET_BIT(DDRA,Copy_Pin);break;
					case PORT_B: SET_BIT(DDRB,Copy_Pin);break;
					case PORT_C: SET_BIT(DDRC,Copy_Pin);break;
					case PORT_D: SET_BIT(DDRD,Copy_Pin);break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else if (Copy_Dir==PIN_INPUT)
			{
				switch(Copy_Port)
				{
					case PORT_A: CLEAR_BIT(DDRA,Copy_Pin);break;
					case PORT_B: CLEAR_BIT(DDRB,Copy_Pin);break;
					case PORT_C: CLEAR_BIT(DDRC,Copy_Pin);break;
					case PORT_D: CLEAR_BIT(DDRD,Copy_Pin);break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else
			DIO_L_ErrorCode=1;
	}
	else
	{
		DIO_L_ErrorCode=1;
	}
}

/*----------------------------------------------------------------------------------*/

void DIO_uint8SetDirectionPort(PORT_NAME Copy_Port,PORT_DIR Copy_Dir)
{
		uint8 DIO_L_ErrorCode;
		if (Copy_Dir==PORT_OUTPUT)
			{
				switch(Copy_Port)
				{
					case PORT_A:DDRA=PORT_OUTPUT;break;
					case PORT_B:DDRB=PORT_OUTPUT;break;
					case PORT_C:DDRC=PORT_OUTPUT;break;
					case PORT_D:DDRD=PORT_OUTPUT;break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else if (Copy_Dir==PORT_INPUT)
			{
				switch(Copy_Port)
				{
					case PORT_A: DDRA=PORT_INPUT;break;
					case PORT_B: DDRB=PORT_INPUT;break;
					case PORT_C: DDRC=PORT_INPUT;break;
					case PORT_D: DDRD=PORT_INPUT;break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else
			DIO_L_ErrorCode=1;
	}


/*---------------------------------------------------------------------------------------------*/

void DIO_uint8SetValuePIN(PORT_NAME Copy_Port,PIN_NAME Copy_Pin,PIN_VALUE Copy_Value)
{
	uint8 DIO_L_ErrorCode;
	if (Copy_Pin>=0 && Copy_Pin<=7)
	{
		if (Copy_Value==PIN_HIGH)
			{
				switch(Copy_Port)
				{
					case PORT_A: SET_BIT(PORTA,Copy_Pin);break;
					case PORT_B: SET_BIT(PORTB,Copy_Pin);break;
					case PORT_C: SET_BIT(PORTC,Copy_Pin);break;
					case PORT_D: SET_BIT(PORTD,Copy_Pin);break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else if (Copy_Value==PIN_LOW)
			{
				switch(Copy_Port)
				{
					case PORT_A: CLEAR_BIT(PORTA,Copy_Pin);break;
					case PORT_B: CLEAR_BIT(PORTB,Copy_Pin);break;
					case PORT_C: CLEAR_BIT(PORTC,Copy_Pin);break;
					case PORT_D: CLEAR_BIT(PORTD,Copy_Pin);break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else
			DIO_L_ErrorCode=1;
	}
	else
	{
		DIO_L_ErrorCode=1;
	}
}

/*-------------------------------------------------------------------------------------*/

void DIO_uint8SetValuePort(PORT_NAME Copy_Port,PORT_VALUE Copy_Value)
{
		uint8 DIO_L_ErrorCode;
		if (Copy_Value==PORT_HIGH)
			{
				switch(Copy_Port)
				{
					case PORT_A:PORTA=PORT_HIGH;break;
					case PORT_B:PORTB=PORT_HIGH;break;
					case PORT_C:PORTC=PORT_HIGH;break;
					case PORT_D:PORTD=PORT_HIGH;break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else if (Copy_Value==PORT_LOW)
			{
				switch(Copy_Port)
				{
					case PORT_A: PORTA=PORT_LOW;break;
					case PORT_B: PORTB=PORT_LOW;break;
					case PORT_C: PORTC=PORT_LOW;break;
					case PORT_D: PORTD=PORT_LOW;break;
					default: DIO_L_ErrorCode=1;break;
				}
			}
		else
			DIO_L_ErrorCode=1;
}

/*-------------------------------------------------------------------------------------*/

void DIO_uint8Set_SpecificValue_Port(PORT_NAME Copy_Port,uint8 Copy_Value)
{
	uint8 DIO_L_ErrorCode;
	/* Check on the Required PORT Number */
	switch(Copy_Port)
	{
		case PORT_A:PORTA=Copy_Value;break;
		case PORT_B:PORTB=Copy_Value;break;
		case PORT_C:PORTC=Copy_Value;break;
		case PORT_D:PORTD=Copy_Value;break;
		default: DIO_L_ErrorCode=1;break;
	}

}

/*------------------------------------------------------------------------*/

void DIO_uint8Set_SpecificValue_Port_Direction(PORT_NAME Copy_Port,uint8 Copy_Dir)
{
	uint8 DIO_L_ErrorCode;
		/* Check on the Required PORT Number */
		switch(Copy_Port)
		{
			case PORT_A:DDRA=Copy_Dir;break;
			case PORT_B:DDRB=Copy_Dir;break;
			case PORT_C:DDRC=Copy_Dir;break;
			case PORT_D:DDRD=Copy_Dir;break;
			default: DIO_L_ErrorCode=1;break;
		}
}

/*------------------------------------------------------------------------*/

PIN_VALUE DIO_uint8Read_PIN(PIN_Reg_NAME Copy_Port,PIN_NAME Copy_Pin)
{
	PIN_VALUE Copy_Value;
	uint8 DIO_L_ErrorCode;

	if(Copy_Port <= PIN_D && Copy_Pin <= PIN_7)
	{
		switch(Copy_Port)
			{
				case PIN_A:Copy_Value = GET_BIT(PINA,Copy_Pin); break;
				case PIN_B:Copy_Value = GET_BIT(PINB,Copy_Pin); break;
				case PIN_C:Copy_Value = GET_BIT(PINC,Copy_Pin); break;
				case PIN_D:Copy_Value = GET_BIT(PIND,Copy_Pin); break;
				default: DIO_L_ErrorCode=1; break;
			}
	}
	else
	{
		DIO_L_ErrorCode=1;
	}

	return Copy_Value;

}


