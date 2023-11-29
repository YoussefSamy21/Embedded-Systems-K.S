/*
 * main.c
 *
 *  Created on: Nov 29, 2023
 *      Author: youssef samy
 */

#include "STD_LIBRARY.h"
#include "STD_TYPES.h"
#include "DIO_REGISTERMAP.h"
#include "DIO_INTERFACE.h"
#include "EXT_interrupt_RegMap.h"
#include "EXT_interrupt_interface.h"
#include <util/delay.h>

void func_0()
{
	DIO_uint8SetValuePIN(PORT_D , PIN_5 , PIN_HIGH);
	_delay_ms(1000);
}

void func_1()
{
	DIO_uint8SetValuePIN(PORT_D , PIN_6 , PIN_HIGH);
	_delay_ms(1000);
}


void func_2()
{
	DIO_uint8SetValuePIN(PORT_D , PIN_7 , PIN_HIGH);
	_delay_ms(1000);
}

int main()
{
	DIO_uint8SetDirectionPIN(PORT_D , PIN_5 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_D , PIN_6 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_D , PIN_7 , PIN_OUTPUT);


	EXI_SetCallBack(EX_INT0 , &func_0);
	EXI_SetCallBack(EX_INT1 , &func_1);
	EXI_SetCallBack(EX_INT2 , &func_2);

	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0 , ANY_LOGIC_CHANGE);


	EXI_Enable(EX_INT1);
	EXI_TriggerEdge(EX_INT1 , RISING_EDGE);

	EXI_Enable(EX_INT2);
	EXI_TriggerEdge(EX_INT2 , FALLING_EDGE);

	sei();  // enable the global interrupt

	while(1)
	{
		DIO_uint8SetValuePIN(PORT_D , PIN_5 , PIN_LOW);
		DIO_uint8SetValuePIN(PORT_D , PIN_6 , PIN_LOW);
		DIO_uint8SetValuePIN(PORT_D , PIN_7 , PIN_LOW);
	}

	return 0;

}

