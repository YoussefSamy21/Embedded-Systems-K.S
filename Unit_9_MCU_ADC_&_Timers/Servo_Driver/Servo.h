/*
 * Servo.h
 *
 *  Created on: Feb 7, 2024
 *      Author: youssef
 */



#include "MCAL/ATMega32_Timers_Driver/Timers_interface.h"


void SERVO_Init(void);

void SERVO_SetAngle(uint8 angle);

void SERVO_Rotate_MAX_LEFT(void);	// 0 degree
void SERVO_Rotate_MAX_RIGHT(void);	// 180 degree
void SERVO_Rotate_MIDDLE(void);	// 90 degree
