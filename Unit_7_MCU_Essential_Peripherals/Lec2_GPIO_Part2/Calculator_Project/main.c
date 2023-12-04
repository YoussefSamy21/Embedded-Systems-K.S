/*
 * main.c
 *
 *  Created on: Dec 4, 2023
 *      Author: youssef
 */

#include "HAL/Keypad_Driver/Keypad_Config.h"
#include "HAL/Keypad_Driver/Keypad_Interface.h"
#include "HAL/LCD_Driver/LCD_CONFIG.h"
#include "HAL/LCD_Driver/LCD_INTERFACE.h"
#include "Utils/STD_TYPES.h"

void main()
{
	uint8 keypressed = 0, op = 0;
	uint32 num1 = 0 , num2= 0 , result = 0;

	LCD_init();
	KEYPAD_INIT();

	while (1)
	{
		keypressed = KEYPAD_GET_KEY();
		if (keypressed != '?')
		{
			LCD_SEND_DATA_8bit(keypressed);
			if (keypressed == '+' || keypressed == '-' || keypressed == '*' || keypressed == '/' )
			{
				op = keypressed;
			}
			if((keypressed>='0' && keypressed<='9') && (op==0))
			{
				num1 = (num1*10)+(keypressed - '0');
			}
			if((keypressed>='0' && keypressed<='9') && (op!=0))
			{
				num2 = (num2*10)+(keypressed - '0');
			}
			if (keypressed == '=')
			{
				switch(op)
				{
					case '+': result = num1 + num2; break;
					case '-': result = num1 - num2; break;
					case '*': result = num1 * num2; break;
					case '/': result = num1 / num2; break;
				}

				LCD_Goto_XY(1,2);
				LCD_SEND_NUMBER(result);

				// Polling until the user restart the keypad by pressing on (on/c) key, then clear the LCD
				while(keypressed != '@')
				{
					keypressed = KEYPAD_GET_KEY();
				}

				LCD_SEND_COMMAND(Clear_Display);

				// Reset all variables for next operation
				result=0 , num1 = 0 ,num2 = 0 , op = 0;
			}
		}
	}

}
