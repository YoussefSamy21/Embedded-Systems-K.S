/*
 * LCD_Config.h
 *
 *  Created on: Dec 7, 2023
 *      Author: youssef
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "STM32F103C6_MemMap.h"
#include "STM32F103C6_GPIO_Driver.h"

/**********	CONTROL PINS	**********/

#define	PORT_CONTROL	GPIOA
#define	RS				GPIO_PIN_8
#define	RW				GPIO_PIN_9
#define	EN				GPIO_PIN_10

/******************************/
#define	PORT_DATA		GPIOA
#define DATA_PINS		{GPIO_PIN_0 , GPIO_PIN_1  , GPIO_PIN_2  , GPIO_PIN_3  , GPIO_PIN_4  , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7}


#endif /* LCD_CONFIG_H_ */
