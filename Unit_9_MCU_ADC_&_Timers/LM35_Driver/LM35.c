/*
 * LM35.c
 *
 *  Created on: Feb 8, 2024
 *      Author: youssef
 */

#include "LM35.h"

void LM35_INIT()
{
	ADC_INIT(LM35_Vref , LM35_Scalar);
}


uint16 LM35_GetTemp()
{
	uint16 temp , adc , volt;
	adc = ADC_START_CONVERSION(LM35_CH);
	volt = (uint32)(adc*5000) / 1024; // mv
	temp = volt / 10 ;
	return temp;
}


