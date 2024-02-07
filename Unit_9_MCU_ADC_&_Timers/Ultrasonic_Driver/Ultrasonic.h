/*
 * Ultrasonic.h
 *
 *  Created on: Feb 7, 2024
 *      Author: youssef
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "MCAL/ATMega32_DIO_Driver/DIO_INTERFACE.h"
#include "MCAL/ATMega32_Timers_Driver/Timers_interface.h"
#include <util/delay.h>

void ULTRASONIC_Init(void);

uint8 ULTRASONIC_GetDistance(PORT_NAME ultrasonic_port , PIN_NAME ultrasonic_pin);

uint8 ULTRASONIC_GetDistance2(PORT_NAME ultrasonic_port , PIN_NAME ultrasonic_pin);

void ULTRASONIC_Start(PORT_NAME ultrasonic_port , PIN_NAME ultrasonic_pin);

uint8 ULTRASONIC_GetDistanceNoBlock(uint8 *Pdistance);

static void Func_ICU(void);
static void Func_OVF(void);



#endif /* ULTRASONIC_H_ */
