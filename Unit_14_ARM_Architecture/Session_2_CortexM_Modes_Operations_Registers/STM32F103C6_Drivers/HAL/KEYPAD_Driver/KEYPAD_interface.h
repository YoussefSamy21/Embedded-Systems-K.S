/*
 * LCD_interface.h
 *
 *  Created on: Dec 7, 2023
 *      Author: youssef
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "STM32F103C6_GPIO_Driver.h"

void KEYPAD_INIT(void);
uint8_t KEYPAD_GET_KEY(void);


#endif /* KEYPAD_INTERFACE_H_ */
