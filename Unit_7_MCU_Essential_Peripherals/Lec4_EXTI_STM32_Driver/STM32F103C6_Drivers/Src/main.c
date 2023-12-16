/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 */
#include "STM32F103C6_EXTI_Driver.h"
#include "../HAL/LCD_Driver/LCD_Config.h"
#include "../HAL/LCD_Driver/LCD_interface.h"

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


void EXTIB9_CallBack(void)
{
	LCD_SEND_STRING("IRQ_9 _|-");
	wait_ms(400);
	LCD_SEND_COMMAND(Clear_Display);
}

int main(void)
{
	// Enable the clocks of used Peripherals
	clock_init();

	// Initialize the LCD
	LCD_init();
	LCD_SEND_COMMAND(Clear_Display);

	// Configure the EXTI Pin
	EXTI_PinConfig_t PinCfg;
	PinCfg.EXTI_PIN = EXTI9PB9;
	PinCfg.Trigger_Case = EXTI_TRIGGER_RISING;
	PinCfg.P_IRQ_CallBack = EXTIB9_CallBack;
	PinCfg.IRQ_EN = EXTI_STATE_ENABLE;
	MCAL_EXTI_GPIO_Init(&PinCfg);

	LCD_SEND_STRING("Hello ...");
	wait_ms(500);
	LCD_SEND_COMMAND(Clear_Display);
	while (1)
	{

	}
}
