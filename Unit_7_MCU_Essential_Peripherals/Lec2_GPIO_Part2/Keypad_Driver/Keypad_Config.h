/*
 * Keypad_Config.h
 *
 *  Created on: Dec 4, 2023
 *      Author: youssef
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_



#define KPD_ROWS_PORT		PORT_D
#define KPD_COLUMNS_PORT	PORT_D

#define KPD_ROWS_PIN		PIN_D

#define R1					0
#define R2					1
#define R3					2
#define R4					3

#define C1					4
#define C2					5
#define C3					6
#define C4					7

#define KEYPAD_ROWS			4
#define KEYPAD_COLUMNS		4
#define KPD_KEYS			{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'} ,{'@','0','=','+'}}

#endif /* KEYPAD_CONFIG_H_ */
