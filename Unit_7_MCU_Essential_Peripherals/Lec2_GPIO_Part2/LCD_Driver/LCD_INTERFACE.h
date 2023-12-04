/*
 * LCD_INTERFACE.h
 *
 *  Created on: Sep 17, 2022
 *      Author: youssef
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

typedef enum COMMANDS		/*******	COMMANDS	******/
{
	Clear_Display = 0x01,

	FUN_SET_8BIT_2LINE = 0x38,

	FUN_SET_4BIT_2LINE = 0x28,

	FUN_SET_4BIT_1LINE = 0x20,

	Entry_Mode = 0x06,

	lcd_Home = 0x02,

	DisplayOn_CursorOn = 0x0E,

	DisplayOn_CursorOff = 0x0C,

	DisplayOn_CursorBlink = 0x0F,


	ShiftDisplay_Left = 0x18,

	ShiftDisplay_Right = 0x1C,

	MoveCursor_Left = 0x10,

	MoveCursor_Right = 0x14,

	ForceBegin_1Row = 0x80,

	ForceBegin_2Row = 0xC0

}Commands;


void LCD_init(void);

void LCD_SEND_COMMAND(Commands copy_command);

void LCD_SEND_DATA_8bit(uint8 DATA);

void LCD_SEND_NUMBER_4Digits(uint32 Copyu32_NUM);		// displays number 4 digits if num = 12 ----> 0012

void LCD_SEND_NUMBER(uint32 num);

void LCD_Goto_XY(uint8 Col, uint8 Row);		//goes to special position in LCD

void LCD_SEND_STRING(uint8 *ptr);

#endif /* LCD_INTERFACE_H_ */
