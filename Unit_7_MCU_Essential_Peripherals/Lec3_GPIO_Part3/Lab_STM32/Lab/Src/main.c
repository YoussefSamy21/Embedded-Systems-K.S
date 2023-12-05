/*
 	 Author: Youssef Samy
 	  Date: 1/12/2023
 */

#include "STM32F103C6_GPIO_Driver.h"

void My_Wait(uint32_t x) // Delay Function
{
	uint32_t i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<255;j++);
	}
}

void main(void)
{

	// RCC Clock Configurations
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

	GPIO_PinConfig_t Pin_Config;

	// PA1 ==> I/P (Floating)
	Pin_Config.GPIO_PinNumber = GPIO_PIN_1;
	Pin_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &Pin_Config);

	// PA13 ==> I/P (Floating)
	Pin_Config.GPIO_PinNumber = GPIO_PIN_13;
	Pin_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &Pin_Config);

	// PB1 ==> O/P (PushPull)
	Pin_Config.GPIO_PinNumber = GPIO_PIN_1;
	Pin_Config.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &Pin_Config);

	// PB13 ==> O/P (PushPull)
	Pin_Config.GPIO_PinNumber = GPIO_PIN_13;
	Pin_Config.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &Pin_Config);


	while(1)
	{
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)	// PULL UP Pin
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); // Single Press
		}

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) // PULL Down Pin
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13); // Multi-Pressing
			My_Wait(1);
		}

	}
}


