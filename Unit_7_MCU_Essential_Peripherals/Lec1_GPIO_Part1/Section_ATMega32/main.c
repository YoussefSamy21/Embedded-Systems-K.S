/*
 * main.c
 *
 *  Created on: Dec 2, 2023
 *      Author: youssef
 */

#include "Utils/STD_LIBRARY.h"
#include "Utils/STD_TYPES.h"
#include "MCAL/DIO_REGISTERMAP.h"
#include "MCAL/DIO_INTERFACE.h"
#include <util/delay.h>>

#define TASK_1_3LEDS_TOGGLE							0
#define TASK_2_BUTTON_LEDS_							1
#define TASK_3_7SEGMENT								2
#define TASK_RUNNING						TASK_1_3LEDS_TOGGLE

void main(void)
{
	// LED PINS & BUZZER
	DIO_uint8SetDirectionPIN(PORT_D , PIN_4 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_D , PIN_5 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_D , PIN_6 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_D , PIN_7 , PIN_OUTPUT);

	// Button Pins
	DIO_uint8SetDirectionPIN(PORT_D , PIN_0 , PIN_INPUT);
	DIO_uint8SetDirectionPIN(PORT_D , PIN_1 , PIN_INPUT);
	DIO_uint8SetDirectionPIN(PORT_D , PIN_2 , PIN_INPUT);


	DIO_uint8SetDirectionPIN(PORT_C , PIN_2 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_C , PIN_3 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_C , PIN_4 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_C , PIN_5 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_C , PIN_6 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_C , PIN_7 , PIN_OUTPUT);

	uint8 i,j,flag = 4;

	while(1)
	{
		// Task 1
		#if TASK_RUNNING == TASK_1_3LEDS_TOGGLE
		for(i=5;i<=7;i++)
		{
			SET_BIT(PORTD,i);
			_delay_ms(1000);
		}
		for(i=7;i>=5;i--)
		{
			CLEAR_BIT(PORTD,i);
			_delay_ms(1000);
		}
		// Task2
		#elif TASK_RUNNING ==  TASK_2_BUTTON_LEDS_
		if (GET_BIT(PIND,0) == 1)
				{
					if(flag == 7)
					{
						flag=4;
						SET_BIT(PORTD,4);
					}
					else
					{
						flag++;
						SET_BIT(PORTD,flag);
					}
					while (GET_BIT(PIND,0) == 1); // Multi-Pressing
				}



		// Task3
		#elif TASK_RUNNING ==   TASK_3_7SEGMENT
		for (i=0 ; i<10 ; i++)
				{
					for (j=0 ; j<10 ; j++)
					{
						PORTC = 0b1011 | (i<<4);
						_delay_ms(750);
						PORTC = 0b0111 | (j<<4);
						_delay_ms(750);
					}
				}




		#endif


	}

}
