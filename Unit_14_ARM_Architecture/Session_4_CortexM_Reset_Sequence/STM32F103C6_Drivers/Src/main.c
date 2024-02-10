/**
 ******************************************************************************
 *
 * @file           : main.c
 * @author         : Youssef Samy
 *
 */
#include "STM32F103C6_EXTI_Driver.h"

static uint8_t IRQ_Flag = 0;

enum CPU_AccessLevel
{
	Privileged,
	Unprivileged
};

void Switch_CPU_Access_Level(enum CPU_AccessLevel);


void Switch_CPU_Access_Level(enum CPU_AccessLevel level)
{
	switch(level)
	{
	case Privileged:
		// Clear Bit 0 in CONTROL Register
		__asm("MRS R3,CONTROL 	\n\t"
				"AND R3,R3,#0xFFFFFFFE \n\t"
				"MSR CONTROL,R3");
		break;

	case Unprivileged:
		// SET Bit 0 in CONTROL Register
		__asm("MRS R3,CONTROL 	\n\t"
				"ORR R3,R3,#0x1 \n\t"
				"MSR CONTROL,R3");

		break;

	}

}
void EXTIB9_CallBack(void)
{
	IRQ_Flag = 1;
	Switch_CPU_Access_Level(Privileged); // to be able to return to thread mode in Privileged access Level
}

int main(void)
{
	// Enable the clocks
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	// Configure the EXTI Pin
	EXTI_PinConfig_t PinCfg;


	// Switch_CPU_AccessLevel(Unprivileged);
	/*
		if we switch to unprivileged mode before accessing NVIC in EXTI configuration
		the NVIC will not be configured resulting in Fault Handler Exception,
		So in this case we can switch to privileged mode in the hard fault handler as we have access on the
		Control Register only in the Privilege mode and Generally , Handler mode is always Privileged
	*/

	PinCfg.EXTI_PIN = EXTI9PB9;
	PinCfg.Trigger_Case = EXTI_TRIGGER_RISING;
	PinCfg.P_IRQ_CallBack = EXTIB9_CallBack;
	PinCfg.IRQ_EN = EXTI_STATE_ENABLE;
	MCAL_EXTI_GPIO_Init(&PinCfg);

	IRQ_Flag = 1;
	Switch_CPU_Access_Level(Unprivileged); // will Switch to Unprivileged by accessing CONTROL Register

	// Switch_CPU_Access_Level(Privileged);
	// This Line will not be executed , because switching from Unprivileged to Privileged is Available ONLY in Handler Mode

	while (1)
	{
		if(IRQ_Flag == 1)
		{
			IRQ_Flag = 0;
		}

	}
}

void HardFault_Handler()
{
	// Switch_CPU_Access_Level(Privileged);
}

void BusFault_Handler()
{

}

void UsageFault_Handler()
{

}

