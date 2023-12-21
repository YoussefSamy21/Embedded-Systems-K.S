/**
 ******************************************************************************
 *
 * @file           : main.c
 * @author         : Youssef Samy
 *
 */
#include "STM32F103C6_USART_Driver.h"
#include "STM32F103C6_SPI_Driver.h"

#define MCU_Act_as_Master
//#define MCU_Act_as_Slave

void clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}



//uint32_t IRQ_Flag = 0 ;
uint8_t ch;

void UART_IRQ_CallBack(void)
{
	#ifdef MCU_Act_as_Master

		MCAL_UART_ReceiveData(USART1, &ch, disable);
		MCAL_UART_SendData(USART1, &ch, enable);

		//Make SS low to send data
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

		//Send to SPI
		MCAL_SPI_TxRx(SPI1, &ch, PollingEnable);

		//Return Slave Select to be HIGH (idle mode)
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	#endif
}

void SPI_IRQ_CallBack(struct S_IRQ_SRC irq_src)
{
	#ifdef MCU_Act_as_Slave
		if(irq_src.RXNE)
		{
			Byte = 0xf;
			MCAL_SPI_TxRx(SPI1, &ch, PollingDisable);
			MCAL_UART_SendData(USART1, &ch, enable);
		}
	#endif
}

int main(void)
{
	UART_Config UART_Pincfg;
	GPIO_PinConfig_t PinConfig;

	clock_init();
	/* ============================ UART init ============================ */
	//USART1_TX : PA9
	//USART1_Rx : PA10
	//USART1_RTS: PA12
	//USART1_CTS: PA11
	UART_Pincfg.USART_Mode = UART_MODE_TX_RX;
	UART_Pincfg.BaudRate = UART_BaudRate_115200;
	UART_Pincfg.Payload_Length = UART_Payload_Length_8B;
	UART_Pincfg.Parity = UART_Parity__NONE;
	UART_Pincfg.StopBits = UART_StopBits__1;
	UART_Pincfg.HwFlowCtl = UART_HwFlowCtl_NONE;
	UART_Pincfg.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	UART_Pincfg.P_IRQ_CallBack = UART_IRQ_CallBack;

	MCAL_UART_Init(USART1, &UART_Pincfg);
	MCAL_UART_GPIO_Set_Pins(USART1);

	/* ============================ SPI init ============================ */
	//NSS  : PA4
	//SCK  : PA5
	//MISO : PA6
	//MOSI : PA7
	SPI_Config_t SPI_Config;

	//Common Configurations
	SPI_Config.CLK_Polarity = SPI_CLK_PHASE_2EDGE_Sampling;
	SPI_Config.CLK_PHASE = SPI_CLK_Polarity_HIGH_idle;
	SPI_Config.Data_Size = SPI_Data_Size_8bit;
	SPI_Config.Frame_Format = SPI_Frame_Format_MSB;
	//Assume by default PCLK2 = 8 MHZ
	SPI_Config.Baud_Rate_PreSCLR = SPI_Baud_Rate_PreSCLR_8;
	SPI_Config.Communication_Mode = SPI_Communication_Mode_2LINES;

#ifdef MCU_Act_as_Master
	SPI_Config.IRQ_Enable = SPI_IRQ_NONE;
	SPI_Config.NSS = SPI_NSS_SW_SET;
	SPI_Config.P_IRQ_CallBack = NULL;
	SPI_Config.SPI_Mode = SPI_Mode_Master;


	//Configure SS on PA.4 by GPIO
	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

	//Force Slave Select to be HIGH (idle mode)
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

#endif

#ifdef MCU_Act_as_Slave
	SPI_Config.IRQ_Enable = SPI_IRQ_RXNEIE;
	SPI_Config.NSS = SPI_NSS_HW_Slave;
	SPI_Config.P_IRQ_CallBack = SPI_IRQ_CallBack;
	SPI_Config.SPI_Mode = SPI_Mode_Slave;
#endif
	MCAL_SPI_Init(SPI1, &SPI_Config);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	while(1)
	{

	}
}

