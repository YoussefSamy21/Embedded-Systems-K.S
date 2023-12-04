/*
 * LCD-INTERFACE.c
 *
 *  Created on: Sep 17, 2022
 *      Author: youssef
 */
#include "Utils/STD_TYPES.h"
#include "Utils/STD_LIBRARY.h"
#include <util/delay.h>

#include "MCAL/DIO_INTERFACE.h"
#include "MCAL/DIO_REGISTERMAP.h"
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"


void LCD_init(void)
{
	DIO_uint8SetDirectionPort(PORT_DATA , PORT_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_CONTROL , RS , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_CONTROL , RW , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(PORT_CONTROL , EN , PIN_OUTPUT);

	_delay_ms(30);

	LCD_SEND_COMMAND(lcd_Home);
	_delay_ms(15);

	LCD_SEND_COMMAND(FUN_SET_8BIT_2LINE);
	_delay_ms(1);

	LCD_SEND_COMMAND(DisplayOn_CursorOn);
	_delay_ms(1);

	LCD_SEND_COMMAND(Clear_Display);
	_delay_ms(15);

	LCD_SEND_COMMAND(Entry_Mode);
	_delay_ms(2);

}

/*-------------------------------------------------------------------------------------*/

void LCD_SEND_COMMAND(Commands copy_command)
{
	DIO_uint8SetValuePIN(PORT_CONTROL , RS , PIN_LOW);

	DIO_uint8SetValuePIN(PORT_CONTROL , RW , PIN_LOW);

	DIO_uint8Set_SpecificValue_Port(PORT_DATA , copy_command);
	/******	giving a PULSE to the EN pin ******/

	DIO_uint8SetValuePIN(PORT_CONTROL , EN , PIN_HIGH);
	_delay_ms(2);

	DIO_uint8SetValuePIN(PORT_CONTROL , EN , PIN_LOW);
	_delay_ms(2);

	DIO_uint8SetValuePIN(PORT_CONTROL , EN , PIN_HIGH);

}

/*-------------------------------------------------------------------------------------*/

void LCD_SEND_DATA_8bit(uint8 DATA)
{
	DIO_uint8SetValuePIN(PORT_CONTROL , RS , PIN_HIGH);

	DIO_uint8SetValuePIN(PORT_CONTROL , RW , PIN_LOW);

	DIO_uint8SetValuePIN(PORT_CONTROL , EN , PIN_HIGH);

	DIO_uint8Set_SpecificValue_Port(PORT_DATA , DATA);

	/******	giving a PULSE to the EN pin ******/

	//DIO_uint8SetValuePIN(PORT_CONTROL , EN , PIN_HIGH);
	//_delay_ms(2);

	DIO_uint8SetValuePIN(PORT_CONTROL , EN , PIN_LOW);
	_delay_ms(5);

	DIO_uint8SetValuePIN(PORT_CONTROL , EN , PIN_HIGH);
	_delay_ms(10);

}

/*-------------------------------------------------------------------------------------*/

void LCD_SEND_NUMBER_4Digits(uint32 Copyu32_NUM)
{
	// displays number 4 digits

	LCD_SEND_DATA_8bit((Copyu32_NUM % 10000) / 1000 + '0');

	LCD_SEND_DATA_8bit((Copyu32_NUM % 1000) / 100 + '0');

	LCD_SEND_DATA_8bit((Copyu32_NUM % 100) / 10 + '0');

	LCD_SEND_DATA_8bit((Copyu32_NUM % 10) / 1 + '0');

}

/*-------------------------------------------------------------------------------------*/
void LCD_SEND_NUMBER(uint32 num)
{
	uint8 i=0,arr[10],j;
	if(num==0)
	{
		LCD_SEND_DATA_8bit('0');
	}
	else
	{
			while(num)
			{
				arr[i]=num%10+'0';
				num/=10;
				i++;
			}
			for(j=i;j>0;j--)
			{
				LCD_SEND_DATA_8bit(arr[j-1]);
			}
	}
}

/*-------------------------------------------------------------------------------------*/

void LCD_Goto_XY(uint8 Col, uint8 Row)
{
	switch(Row)
	{
		case 1:	LCD_SEND_COMMAND(ForceBegin_1Row + Col - 1);
		break;

		case 2:	LCD_SEND_COMMAND(ForceBegin_2Row + Col - 1);
		break;
	}
}

/*-------------------------------------------------------------------------------------*/

void LCD_SEND_STRING(uint8 *ptr)
{
	uint8 i=0;
	while(ptr[i] != '\0')
	{
		LCD_SEND_DATA_8bit(ptr[i]);
		i++;
	}

}

/*-------------------------------------------------------------------------------------*/










