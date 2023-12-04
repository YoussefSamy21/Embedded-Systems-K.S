/*
 * Keypad_Interface.h
 *
 *  Created on: Dec 4, 2023
 *      Author: youssef
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_

#include "../../Utils/STD_TYPES.h"

void KEYPAD_INIT(void);
uint8 KEYPAD_GET_KEY(void);

#endif /* HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_ */
