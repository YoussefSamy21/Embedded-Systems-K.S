/*
 * main.c
 *
 *  Created on: Dec 16, 2023
 *      Author: youssef
 */


#include "LCD/LCD_INTERFACE.h"
#include "UART_Driver/UART_interface.h"
#include <util/delay.h>

/******* Testing UART Driver (Polling, Send & Receive Asynch (Interrupt)) *******/
void main()
{
	LCD_init();
	UART_Init();

	uint8 STR[100];

	UART_Send_String("Hello Terminal ... "); // Using Polling Mechanism

	sei();
	UART_Send_String_Asynch("Youssef Samy\r"); // Asynch API
	UART_Receive_String_Asynch(STR); // Asynch API
	uint8 i = 0;
	while(1)
	{
		LCD_Goto_XY(1,2);
		LCD_SEND_NUMBER(i);
		if(i == 9)
		{
			i = 0;
		}
		else
		{
			i++;
		}
		if(UART_GET_Def_Stop_Flag() == 1)
		{
			LCD_Goto_XY(1,1);
			LCD_SEND_STRING(STR);
		}
		_delay_ms(500);
	}

}
