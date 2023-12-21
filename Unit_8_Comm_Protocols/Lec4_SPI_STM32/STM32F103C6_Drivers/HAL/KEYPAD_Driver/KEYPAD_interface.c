/*
 * LCD_interface.c
 *
 *  Created on: Dec 7, 2023
 *      Author: youssef
 */

#include "KEYPAD_Config.h"
#include "KEYPAD_interface.h"

uint8_t keypad_rows[KEYPAD_ROWS] = {R1,R2,R3,R4};
uint8_t keypad_columns[KEYPAD_COLUMNS] = {C1,C2,C3,C4};


void KEYPAD_INIT(void)
{
	GPIO_PinConfig_t Pin_Config;
	uint8_t i;
	// Set Rows -> Input,PullUp
	for(i=0; i<KEYPAD_ROWS;i++)
	{
		Pin_Config.GPIO_PinNumber = keypad_rows[i];
		Pin_Config.GPIO_MODE = GPIO_MODE_INPUT_PU;
		MCAL_GPIO_Init(KEYPAD_PORT , &Pin_Config);
	}

	// Set Columns -> Output , PushPull
	for(i=0; i<KEYPAD_COLUMNS;i++)
	{
		Pin_Config.GPIO_PinNumber = keypad_columns[i];
		Pin_Config.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(KEYPAD_PORT , &Pin_Config);
	}
}

uint8_t KEYPAD_GET_KEY(void)
{

	uint8_t i,j;
	uint8_t keys[KEYPAD_ROWS][KEYPAD_COLUMNS] = KPD_KEYS;

	for (i=0 ; i<KEYPAD_COLUMNS; i++)
	{
		// Set all the columns to high
		MCAL_GPIO_WritePin(KEYPAD_PORT, C1 , GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C2 , GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C3 , GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, C4 , GPIO_PIN_SET);

		// Set column[i] to low
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_columns[i] , GPIO_PIN_RESET);

		// Loop on every row to see if a key is pressed
		for(j=0 ; j< KEYPAD_ROWS ; j++)
		{
			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_rows[j]) == GPIO_PIN_RESET)
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_rows[j]) == GPIO_PIN_RESET);	// for single press
				return keys[j][i];
			}
		}

	}

	return '?';

}

