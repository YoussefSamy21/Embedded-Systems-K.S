/*
 * APP.c
 *
 *  Created on: Sep 17, 2022
 *      Author: youssef
 */

#include "Utils/STD_TYPES.h"
#include <util/delay.h>
#include "MCAL/DIO_INTERFACE.h"
#include "LCD_CONFIG.H"
#include "LCD_INTERFACE.H"



//#include "STD_LIBRARY.h"
//#include "DIO_REGISTERMAP.h"

void main(void)
{
	/*	Testing the Driver	*/
	LCD_init();

	//LCD_SEND_NUM_8bit(134);

	//LCD_SEND_DATA_8bit(' ');

	LCD_SEND_DATA_8bit('e');

	//LCD_SEND_NUM_8bit_normal(-7);

	//LCD_SEND_DATA_8bit(' ');

	//LCD_SEND_NUM_8bit_normal(32);

	//LCD_SEND_COMMAND(DisplayOn_CursorBlink);

	//LCD_SEND_DATA_8bit(' ');

	//LCD_SEND_NUM_8bit_normal(-543);

	//LCD_SEND_DATA_8bit(' ');

	LCD_SEND_NUMBER(89);

	//LCD_SEND_STRING("hi");

	while(1);

}
