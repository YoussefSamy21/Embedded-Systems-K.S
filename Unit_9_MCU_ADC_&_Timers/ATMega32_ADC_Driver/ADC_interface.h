/*
 * ADC_interface.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Youssef Samy
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_MemMap.h"
#include "Utils/STD_TYPES.h"
#include "Utils/STD_LIBRARY.h"
typedef enum
{
	VREF_AVCC,
	VREF_AREF,
	VREF_256	//Internal 2.56V Voltage Reference

}ADC_Vref_type;

typedef enum
{
	ADC_SCALER_2,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128

}ADC_SCALER_type;

typedef enum
{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7

}ADC_CHANNEL_type;


void ADC_INIT(ADC_Vref_type vref,ADC_SCALER_type scaler);

uint16 ADC_START_CONVERSION(ADC_CHANNEL_type channel);

void ADC_Interrupt_Enable();
void ADC_Interrupt_Disable();
void ADC_SetCallBack(void(*LocalPtr)(void));

// Periodic Check (No Block) , the aim of this function to not block or delaying the main function
uint8 ADC_GetRead_NoBlock(ADC_CHANNEL_type channel,uint16 *ptr_data);

#endif /* ADC_INTERFACE_H_ */
