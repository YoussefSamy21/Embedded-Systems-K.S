/*
 * STM32F103C6_Systick_Driver.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Youssef Samy
 */

#ifndef STM32F103C6_SYSTICK_DRIVER_H_
#define STM32F103C6_SYSTICK_DRIVER_H_

#include "STM32F103C6_MemMap.h"

typedef enum
{
	CLK_AHB_8 = 0x00, // Clock Source = AHB / 8
	CLK_AHB = 0x04   // Clock Source = Processor Clock (AHB)
}Systick_CLCK_Source;

typedef enum
{
	Single,
	Periodic
}Systick_Running_Mode;

void Systick_Init(Systick_CLCK_Source CLK_Source);

void Systick_Set_Time_BusyWait(uint32_t ticks); // Polling
void Systick_Set_Time_CallBack(uint32_t ticks , Systick_Running_Mode mode , void (*Lptr)(void) ); // Interrupt

void Systick_Interrupt_Enable(void);
void Systick_Interrupt_Disable(void);

void Systick_Stop_Timer(void);



#endif /* STM32F103C6_SYSTICK_DRIVER_H_ */
