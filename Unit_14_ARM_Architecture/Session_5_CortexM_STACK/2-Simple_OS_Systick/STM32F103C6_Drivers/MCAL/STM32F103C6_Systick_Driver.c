/*
 * STM32F103C6_Systick_Driver.c
 *
 *  Created on: Feb 17, 2024
 *      Author: youssef
 */

#include "STM32F103C6_Systick_Driver.h"

static void (*STK_Fptr)(void) = NULL;

static uint8_t running_mode = 0;

void Systick_Init(Systick_CLCK_Source CLK_Source)
{
	Systick_CTRL |= CLK_Source;
}

void Systick_Set_Time_BusyWait(uint32_t ticks)
{
	Systick_LOAD = ticks;
	SET_BIT(Systick_CTRL , 0); // Start Timer

	while(GET_BIT(Systick_CTRL , 16 ) == 0); // Polling

	// Stop Timer
	CLEAR_BIT(Systick_CTRL , 0); // Counter Disable
	Systick_LOAD = 0;
	Systick_VAL = 0;
}

void Systick_Interrupt_Enable(void)
{
	SET_BIT(Systick_CTRL , 1);
}
void Systick_Interrupt_Disable(void)
{
	CLEAR_BIT(Systick_CTRL , 1);
}


void Systick_Set_Time_CallBack(uint32_t ticks , Systick_Running_Mode mode , void (*Lptr)(void) ) // Interrupt
{
	running_mode = mode;

	// Clear Timer
	CLEAR_BIT(Systick_CTRL , 0);
	Systick_VAL = 0;

	//Save CallBack
	STK_Fptr = Lptr;

	// Load Ticks
	Systick_LOAD = ticks;

	// Enable Interrupt
	Systick_Interrupt_Enable();

	//Start Timer
	SET_BIT(Systick_CTRL , 0);

}



void Systick_Stop_Timer(void)
{
	CLEAR_BIT(Systick_CTRL , 0);
	Systick_LOAD = 0;
	Systick_VAL = 0;
}

void SysTick_Handler()
{
	if(running_mode == Single)
	{
		Systick_Interrupt_Disable();
		Systick_Stop_Timer();
	}

	// Periodic
	if(STK_Fptr != NULL)
	{
		STK_Fptr();
	}

}


