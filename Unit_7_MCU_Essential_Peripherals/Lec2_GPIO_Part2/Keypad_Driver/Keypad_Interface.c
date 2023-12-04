/*
 * Keypad_Interface.c
 *
 *  Created on: Dec 4, 2023
 *      Author: youssef
 */
#include "Utils/STD_TYPES.h"
#include "Utils/STD_LIBRARY.h"
#include <util/delay.h>
#include "MCAL/DIO_INTERFACE.h"
#include "MCAL/DIO_REGISTERMAP.h"
#include "Keypad_Config.h"
#include "Keypad_Interface.h"



uint8 keypad_rows[KEYPAD_ROWS] = {R1,R2,R3,R4};
uint8 keypad_columns[KEYPAD_COLUMNS] = {C1,C2,C3,C4};


void KEYPAD_INIT(void)
{
	// Set Rows -> Input
	DIO_uint8SetDirectionPIN(KPD_ROWS_PORT , R1 , PIN_INPUT);
	DIO_uint8SetDirectionPIN(KPD_ROWS_PORT , R2 , PIN_INPUT);
	DIO_uint8SetDirectionPIN(KPD_ROWS_PORT , R3 , PIN_INPUT);
	DIO_uint8SetDirectionPIN(KPD_ROWS_PORT , R4 , PIN_INPUT);

	// Set Columns -> Output
	DIO_uint8SetDirectionPIN(KPD_COLUMNS_PORT , C1 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(KPD_COLUMNS_PORT , C2 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(KPD_COLUMNS_PORT , C3 , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(KPD_COLUMNS_PORT , C4 , PIN_OUTPUT);

	// at the beginning: make all output columns as high , also all input rows as high to be connected with pull up resistors

	DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C1 , PIN_HIGH);
	DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C2 , PIN_HIGH);
	DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C3 , PIN_HIGH);
	DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C4 , PIN_HIGH);

	DIO_uint8SetValuePIN(KPD_ROWS_PORT , R1 , PIN_HIGH);
	DIO_uint8SetValuePIN(KPD_ROWS_PORT , R2 , PIN_HIGH);
	DIO_uint8SetValuePIN(KPD_ROWS_PORT , R3 , PIN_HIGH);
	DIO_uint8SetValuePIN(KPD_ROWS_PORT , R4 , PIN_HIGH);

}

uint8 KEYPAD_GET_KEY(void)
{

	uint8 i,j;
	uint8 keys[KEYPAD_ROWS][KEYPAD_COLUMNS] = KPD_KEYS;

	for (i=0 ; i<KEYPAD_COLUMNS; i++)
	{
		// Set all the columns to high
		DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C1 , PIN_HIGH);
		DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C2 , PIN_HIGH);
		DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C3 , PIN_HIGH);
		DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , C4 , PIN_HIGH);

		// Set column[i] to low
		DIO_uint8SetValuePIN(KPD_COLUMNS_PORT , keypad_columns[i] ,PIN_LOW);

		// Loop on every row to see if a key is pressed
		for(j=0 ; j< KEYPAD_ROWS ; j++)
		{
			if(DIO_uint8Read_PIN(KPD_ROWS_PIN , keypad_rows[j]) == 0)
			{
				while(DIO_uint8Read_PIN(KPD_ROWS_PIN , keypad_rows[j]) == 0);	// for single press
				return keys[j][i];
			}
		}

	}

	return '?';

}

