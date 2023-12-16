/**
 ******************************************************************************
 *
 * @file           : main.c
 * @author         : Youssef Samy
 *
 */
#include "STM32F103C6_USART_Driver.h"

void clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}



//uint32_t IRQ_Flag = 0 ;
uint8_t ch;

//void UART_IRQ_Callback(void)
//{
//	MCAL_UART_ReceiveData(USART1, &ch, disable);
//	MCAL_UART_SendData(USART1, &ch, enable);
//	MCAL_UART_SendData(USART1, &ch, enable);
//}

int main(void)
{
	// Enable the clocks of used Peripherals
	clock_init();
	UART_Config uart_CFG;

	uart_CFG.BaudRate     	= UART_BaudRate_115200;
	uart_CFG.HwFlowCtl 		= UART_HwFlowCtl_NONE;

	uart_CFG.IRQ_Enable 	= UART_IRQ_Enable_NONE;
	//	uart_CFG.IRQ_Enable 	= UART_IRQ_Enable_RXNEIE;

	uart_CFG.P_IRQ_CallBack = NULL;
	//	uart_CFG.P_IRQ_CallBack = UART_IRQ_Callback;

	uart_CFG.Parity      	= UART_Parity__NONE;
	uart_CFG.Payload_Length = UART_Payload_Length_8B;
	uart_CFG.StopBits		= UART_StopBits__1;
	uart_CFG.USART_Mode    	= UART_MODE_TX_RX;

	MCAL_UART_Init(USART1, &uart_CFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while (1)
	{
		MCAL_UART_ReceiveData(USART1, &ch, enable);
		MCAL_UART_SendData(USART1, &ch, enable);
		MCAL_UART_SendData(USART1, &ch, enable);
	}
}

