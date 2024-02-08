/*
 * STM32F103C6_SPI_Driver.h
 *
 *  Created on: Dec 21, 2023
 *      Author: youssef
 */

#ifndef STM32F103C6_SPI_DRIVER_H_
#define STM32F103C6_SPI_DRIVER_H_

#include "STM32F103C6_MemMap.h"
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_RCC_Driver.h"

struct S_IRQ_SRC // to determine which IRQ source occurs in the SPI Handler
{
	uint8_t TXE:1;		//TX buffer empty interrupt
	uint8_t RXNE:1;		//RX buffer not empty interrupt
	uint8_t ERRI:1;		//Error interrupt
	uint8_t Reserved:5;
};

typedef struct
{
	uint8_t	SPI_Mode;				//Specifies the SPI mode
									// this parameter must be set based on @ref SPI_Mode_define

	uint16_t Communication_Mode;	//Specifies the SPI Bidirectional mode state
									// this parameter must be set based on @ref SPI_Communication_Mode_define

	uint8_t	Frame_Format;			//Specifies MSB transmitted first or LSB transmitted first
									// this parameter must be set based on @ref SPI_Frame_Format_define

	uint16_t Data_Size;				//Specifies the size of SPI frame if it's 8 or 16 bit
									// this parameter must be set based on @ref SPI_Data_Size_define

	uint8_t	CLK_Polarity;			//Specifies the SPI Bidirectional mode state
									// this parameter must be set based on @ref SPI_CLK_Polarity_define

	uint8_t	CLK_PHASE;				//Specifies the SPI Bidirectional mode state
									// this parameter must be set based on @ref SPI_CLK_PHASE_define

	uint16_t NSS;					//Specifies whether NSS signal is managed by H.W or S.W using SSI bit enable
									// this parameter must be set based on @ref SPI_NSS_define

	uint8_t	Baud_Rate_PreSCLR;		/* Specifies the Baud Rate prescaler value which will be
									used to configure the transmit and receive SCK clock.
									@note The communication clock is derived from the master
									clock. The slave clock does not need to be set.
									this parameter must be set based on @ref SPI_Baud_Rate_PreSCLR_define */

	uint8_t IRQ_Enable;				//Specifies whether Interrupt is will be Enabled or Disabled
									// this parameter must be set based on @ref SPI_IRQ_define

	void (*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);	//set the C Function() which will be called once the IRQ Happen
}SPI_Config_t;


//==================================================
//Macros Configurations References
//==================================================

//@ref SPI_Mode_define
#define SPI_Mode_Master			(1<<2)	 //CR1.MSTR = 1
#define SPI_Mode_Slave			(0<<2)	 //CR1.MSTR = 0

//@ref SPI_Communication_Mode_define
#define SPI_Communication_Mode_2LINES				(0x0000U)
#define SPI_Communication_Mode_2LINES_RXONLY		(1<<10)
#define SPI_Communication_Mode_1LINE_RXONLY			(1<<15)
#define SPI_Communication_Mode_1LINE_TXONLY	    	(1<<15 | 1 <<14)


//@ref SPI_Frame_Format_define
#define SPI_Frame_Format_LSB	(1<<7)
#define SPI_Frame_Format_MSB	(0x00U)

//@ref SPI_Data_Size_define
#define SPI_Data_Size_8bit		0x0000U
#define SPI_Data_Size_16bit		1<<11

//@ref SPI_CLK_Polarity_define
#define SPI_CLK_Polarity_LOW_idle	0x00U
#define SPI_CLK_Polarity_HIGH_idle	1<<1

//@ref SPI_CLK_PHASE_define
#define SPI_CLK_PHASE_1EDGE_Sampling	0x00U
#define SPI_CLK_PHASE_2EDGE_Sampling	1<<0

//@ref SPI_NSS_define
/* H.W  Bit9 : SSM in CR1 is low by default */
#define SPI_NSS_HW_Slave					0x0000U
#define SPI_NSS_HW_Master_SS_output_Enable	1<<2
#define SPI_NSS_HW_Master_SS_output_Disable	((uint8_t)(~(1<<2)))

//S.W (Master or Slave)
#define SPI_NSS_SW_RESET	1<<9
#define SPI_NSS_SW_SET		(1<<9 | 1 <<8)


//@ref SPI_Baud_Rate_PreSCLR_define
#define SPI_Baud_Rate_PreSCLR_2		0x00U
#define SPI_Baud_Rate_PreSCLR_4		0b001<<3
#define SPI_Baud_Rate_PreSCLR_8		0b010<<3
#define SPI_Baud_Rate_PreSCLR_16	0b011<<3
#define SPI_Baud_Rate_PreSCLR_32	0b100<<3
#define SPI_Baud_Rate_PreSCLR_64	0b101<<3
#define SPI_Baud_Rate_PreSCLR_128	0b110<<3
#define SPI_Baud_Rate_PreSCLR_256	0b111<<3

//@ref SPI_IRQ_define
#define SPI_IRQ_NONE		0x00U
#define SPI_IRQ_TXEIE		1<<7
#define SPI_IRQ_RXNEIE		1<<6
#define SPI_IRQ_ERRIE		1<<5


enum SPI_Polling_mechanism
{
	PollingEnable,
	PollingDisable
};



void MCAL_SPI_Init(SPI_TypeDef* SPIx, SPI_Config_t* SPI_Config);
void MCAL_SPI_DeInit(SPI_TypeDef* SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef* SPIx);

void MCAL_SPI_SendData(SPI_TypeDef* SPIx, uint16_t* pTxBuffer, enum SPI_Polling_mechanism PollingEn);
void MCAL_SPI_ReceiveData(SPI_TypeDef* SPIx, uint16_t* pRxBuffer, enum SPI_Polling_mechanism PollingEn);

void MCAL_SPI_TxRx(SPI_TypeDef* SPIx, uint16_t* pBuffer, enum SPI_Polling_mechanism PollingEn);




#endif /* STM32F103C6_SPI_DRIVER_H_ */
