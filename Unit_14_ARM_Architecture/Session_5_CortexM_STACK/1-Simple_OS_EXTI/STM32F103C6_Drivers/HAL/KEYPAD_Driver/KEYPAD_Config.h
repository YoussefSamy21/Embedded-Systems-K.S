/*
 * LCD_Config.h
 *
 *  Created on: Dec 7, 2023
 *      Author: youssef
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "STM32F103C6_MemMap.h"
#include "STM32F103C6_GPIO_Driver.h"

#define KEYPAD_PORT GPIOB


#define R1 GPIO_PIN_0
#define R2 GPIO_PIN_1
#define R3 GPIO_PIN_3
#define R4 GPIO_PIN_4
#define C1 GPIO_PIN_5
#define C2 GPIO_PIN_6
#define C3 GPIO_PIN_7
#define C4 GPIO_PIN_8

#define KEYPAD_ROWS			4
#define KEYPAD_COLUMNS		4
#define KPD_KEYS			{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'} ,{'@','0','=','+'}}

#endif /* KEYPAD_CONFIG_H_ */
