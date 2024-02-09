/**
 ******************************************************************************
 *
 * @file           : main.c
 * @author         : Youssef Samy
 *
 */
#include "STM32F103C6_EXTI_Driver.h"

static uint8_t IRQ_Flag = 0;


void wait_ms(uint32_t time)
{
	uint16_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}
void clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}


int HANDLER_INT_VAL;

void EXTIB9_CallBack(void)
{
	__asm("nop \n\t nop"); // nop (no operation) , CPU takes one Clock cycle doing nothing
	__asm("MRS %[out] , IPSR"
			: [out] "=r" (HANDLER_INT_VAL) ); // Output parameters , (reading from CPU register into C variable)
	__asm("nop \n\t nop");
	IRQ_Flag = 1;
}

int THREAD_MODE;
int main(void)
{
	// Enable the clocks of used Peripherals
	clock_init();

	// Configure the EXTI Pin
	EXTI_PinConfig_t PinCfg;
	PinCfg.EXTI_PIN = EXTI9PB9;
	PinCfg.Trigger_Case = EXTI_TRIGGER_RISING;
	PinCfg.P_IRQ_CallBack = EXTIB9_CallBack;
	PinCfg.IRQ_EN = EXTI_STATE_ENABLE;
	MCAL_EXTI_GPIO_Init(&PinCfg);

	IRQ_Flag = 1;

	__asm("nop \n\t nop"); // nop (no operation) , CPU takes one Clock cycle doing nothing
	__asm("MRS %[out] , CONTROL"
			: [out] "=r" (THREAD_MODE) ); // Output parameters , (reading from CPU register into C variable)
	__asm("nop \n\t nop");
	while (1)
	{
		if(IRQ_Flag == 1)
		{
			IRQ_Flag = 0;
		}

	}
}
