/*
 * Servo.c
 *
 *  Created on: Feb 7, 2024
 *      Author: youssef
 */


#include "Servo.h"

void SERVO_Init(void)
{
	//Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_NON_INVERTING);	// OCRB hardware pin used in Servo
	OCR1A = 20000;// T_total in pulse of servo (controlling servo position by OCR1B register) , while OCR1A is only Top
}

void SERVO_SetAngle(uint8 angle)
{
	OCR1B = (((uint32)angle*1000)/180)+ 1000;
}

void SERVO_Rotate_MAX_LEFT(void)
{
	OCR1B = 2000;
}
void SERVO_Rotate_MAX_RIGHT(void)
{
	OCR1B = 1000;
}
void SERVO_Rotate_MIDDLE(void)
{
	OCR1B = 1500;
}


