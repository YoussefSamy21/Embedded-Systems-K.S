/*
 * LCD_interface.c
 *
 *  Created on: Dec 7, 2023
 *      Author: youssef
 */

#include "LCD_interface.h"

/* Make a delay function */
static void waitMs(uint32_t time)
{
	uint32_t i,j;
	for(i=0 ; i< time ;i++)
		for(j=0 ; j< 255 ;j++);
}

uint8_t DATA_Pins[8] = DATA_PINS;

void LCD_init(void)
{
	GPIO_PinConfig_t Pin_Confg;
	uint8_t i;

	// Configure RS,RW,EN Pins as Output
	Pin_Confg.GPIO_PinNumber = RS;
	Pin_Confg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Confg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(PORT_CONTROL, &Pin_Confg);

	Pin_Confg.GPIO_PinNumber = RW;
	Pin_Confg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Confg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(PORT_CONTROL, &Pin_Confg);

	Pin_Confg.GPIO_PinNumber = EN;
	Pin_Confg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Confg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(PORT_CONTROL, &Pin_Confg);

	waitMs(30);

	//Configure ALL DATA Pins as output
	for(i=0 ; i<8 ; i++)
	{
		Pin_Confg.GPIO_PinNumber = DATA_Pins[i];
		Pin_Confg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		Pin_Confg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(PORT_DATA, &Pin_Confg);
	}

	LCD_SEND_COMMAND(lcd_Home);

	LCD_SEND_COMMAND(FUN_SET_8BIT_2LINE);

	LCD_SEND_COMMAND(DisplayOn_CursorOn);

	LCD_SEND_COMMAND(Clear_Display);

	LCD_SEND_COMMAND(Entry_Mode);

}

/*-------------------------------------------------------------------------------------*/

void LCD_SEND_COMMAND(Commands copy_command)
{
	MCAL_GPIO_WritePin(PORT_CONTROL, RS, GPIO_PIN_RESET);

	MCAL_GPIO_WritePin(PORT_CONTROL, RW, GPIO_PIN_RESET);

	PORT_DATA->ODR = (PORT_DATA->ODR & 0xFF00) | copy_command;

	// giving a PULSE to the EN pin
	MCAL_GPIO_WritePin(PORT_CONTROL , EN , GPIO_PIN_SET);
	waitMs(50);

	MCAL_GPIO_WritePin(PORT_CONTROL , EN , GPIO_PIN_RESET);
	waitMs(50);

	MCAL_GPIO_WritePin(PORT_CONTROL , EN , GPIO_PIN_SET);

}

/*-------------------------------------------------------------------------------------*/

void LCD_SEND_DATA_8bit(uint8_t DATA)
{
	MCAL_GPIO_WritePin(PORT_CONTROL, RS, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(PORT_CONTROL, RW, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(PORT_CONTROL, EN, GPIO_PIN_SET);

	PORT_DATA->ODR = (PORT_DATA->ODR & 0xFF00) | DATA;

	// giving a PULSE to the EN pin
	MCAL_GPIO_WritePin(PORT_CONTROL , EN , GPIO_PIN_SET);
	waitMs(50);

	MCAL_GPIO_WritePin(PORT_CONTROL , EN , GPIO_PIN_RESET);
	waitMs(50);

	MCAL_GPIO_WritePin(PORT_CONTROL , EN , GPIO_PIN_SET);
}

/*-------------------------------------------------------------------------------------*/

void LCD_SEND_NUMBER_4Digits(uint32_t Copyu32_NUM)
{
	// displays number 4 digits

	LCD_SEND_DATA_8bit((Copyu32_NUM % 10000) / 1000 + '0');

	LCD_SEND_DATA_8bit((Copyu32_NUM % 1000) / 100 + '0');

	LCD_SEND_DATA_8bit((Copyu32_NUM % 100) / 10 + '0');

	LCD_SEND_DATA_8bit((Copyu32_NUM % 10) / 1 + '0');

}

/*-------------------------------------------------------------------------------------*/
void LCD_SEND_NUMBER(uint32_t num)
{
	uint8_t i=0,arr[10],j;
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

void LCD_Goto_XY(uint8_t Col, uint8_t Row)
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

void LCD_SEND_STRING(uint8_t *ptr)
{
	uint8_t i=0;
	while(ptr[i] != '\0')
	{
		LCD_SEND_DATA_8bit(ptr[i]);
		i++;
	}

}
