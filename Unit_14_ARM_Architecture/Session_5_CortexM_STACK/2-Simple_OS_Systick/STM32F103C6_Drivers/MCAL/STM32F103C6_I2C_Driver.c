/*
 * STM32F103C6_I2C_Driver.c
 *
 *  Created on: Jan 31, 2024
 *      Author: youssef
 */

#include "STM32F103C6_I2C_Driver.h"

static I2C_Config Global_I2C_Config[2];

#define I2C1_INDEX	0
#define I2C2_INDEX	1


void MCAL_I2C_Init(I2C_TypeDef *I2Cx, I2C_Config *I2C_cfg)
{
	uint32_t tempreg, pclk, freqrange, result;
	/* Enable RCC Clock */
	if(I2C1 == I2Cx)
	{
		Global_I2C_Config[I2C1_INDEX] = *I2C_cfg;
		RCC_I2C1_CLK_EN();
	}
	else if(I2C2 == I2Cx)
	{
		Global_I2C_Config[I2C2_INDEX] = *I2C_cfg;
		RCC_I2C2_CLK_EN();
	}
	else
	{
		/* Do Nothing */
	}
	if(I2C_Mode_I2C == I2C_cfg->I2C_Mode)
	{
		/* Init Timing */
		// I2C_CR2.FREQ[5:0]: Peripheral clock frequency
		/* Get the I2Cx CR2 register value */
		tempreg = I2Cx->CR2;
		/* Clear frequency bits */
		tempreg &= ~(I2C_CR2_FREQ_Msk);
		/* Get pclk1 frequency value */
		pclk = MCAL_RCC_GetPCLK1Freq();
		/* Set frequency bits depending on pclk1 value */
		freqrange = pclk/1000000;

		tempreg |= freqrange;
		I2Cx->CR2 = tempreg;

		/* Configure the clock control register (I2C_CCR) */
		/* Disable the selected I2C peripheral to configure time */
		I2Cx->CR1 &= ~(I2C_CR1_PE_Msk);
		tempreg = 0;

		/* Configure speed in standard mode */
		if((I2C_SCLK_SM_50K == I2C_cfg->I2C_ClockSpeed) || (I2C_SCLK_SM_100K == I2C_cfg->I2C_ClockSpeed))
		{
			/* Standard mode speed calculation */
			// Tclk/2 = CRR * Tpclk1
			// CRR = Tclk / (2 * Tpclk1)
			// CRR = Fpclk1 / (2 * I2C_ClockFrequency
			result = pclk / (I2C_cfg->I2C_ClockSpeed << 1);
			I2Cx->CCR = result;

			/* I2C_TRISE Configuration */
			I2Cx->TRISE = freqrange + 1;
		}
		else
		{
			/* Fast mode not supported yet */
		}
	}
	else
	{
		/* SMBus Not Supported Yet */
	}

	/* I2Cx CR1 configuration */

	/* Get the I2Cx CR1 value */
	tempreg = I2Cx->CR1;
	tempreg |= (I2C_cfg->I2C_ACK_Control | I2C_cfg->StretchMode | I2C_cfg->I2C_Mode | I2C_cfg->StretchMode);
	I2Cx->CR1 = tempreg;

	/* I2Cx OAR1 & I2Cx OAR2 configuration */
	tempreg = 0;
	if(1 == I2C_cfg->I2C_Slave_Address.Dual_ADD_ack)
	{
		tempreg = I2C_OAR2_ENDUAL;
		tempreg |= (I2C_cfg->I2C_Slave_Address.Secondary_Slave_Address << I2C_OAR2_ADD2_Pos);
		tempreg = I2Cx->OAR2;
	}
	else
	{
		/* Do Nothing */
	}
	tempreg = (I2C_cfg->I2C_Slave_Address.Primary_Slave_Address << 1);
	tempreg |= I2C_cfg->I2C_Slave_Address.I2C_Adressing_Slave_Mode;
	I2Cx->OAR1 = tempreg;


	/* Interrupt mode (Slave mode) */
	// Check on callback function if null -> master mode else -> slave mode
	if(I2C_cfg->P_Slave_Event_CallBack)
	{
		tempreg = I2Cx->CR2;
		tempreg |= (I2C_CR2_ITERREN | I2C_CR2_ITEVTEN | I2C_CR2_ITBUFEN);
		I2Cx->CR2 = tempreg;

		if(I2C1 == I2Cx)
		{
			NVIC_IRQ31_I2C1_EV_Enable();
			NVIC_IRQ32_I2C1_ER_Enable();
		}
		else if(I2C2 == I2Cx)
		{
			NVIC_IRQ33_I2C2_EV_Enable();
			NVIC_IRQ34_I2C2_ER_Enable();
		}
		else
		{
			/* Do Nothing */
		}

		I2Cx->SR1 = 0;
		I2Cx->SR2 = 0;
	}

	/* Enable the selected I2C Peripheral */
	I2Cx->CR1 |= I2C_CR1_PE;

	MCAL_I2C_GPIO_Set_Pins(I2Cx);
}


void MCAL_I2C_DeInit(I2C_TypeDef *I2Cx)
{
	if(I2C1 == I2Cx)
	{
		NVIC_IRQ31_I2C1_EV_Disable();
		NVIC_IRQ32_I2C1_ER_Disable();
		RCC_I2C1_Reset();
	}
	else if(I2C2 == I2Cx)
	{
		NVIC_IRQ33_I2C2_EV_Disable();
		NVIC_IRQ34_I2C2_ER_Disable();
		RCC_I2C2_Reset();
	}
	else
	{
		/* Do Nothing */
	}
}


void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef *I2Cx)
{
	GPIO_PinConfig_t PinCfg;
	RCC_AFIO_CLK_EN();
	RCC_GPIOB_CLK_EN();

	if(I2C1 == I2Cx)
	{
		// PB6 : I2C1_SCL
		// PB7 : I2C1_SDA
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;

		PinCfg.GPIO_PinNumber = GPIO_PIN_6;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_7;
		MCAL_GPIO_Init(GPIOB, &PinCfg);
	}
	else if(I2C2 == I2Cx)
	{
		// PB10 : I2C2_SCL
		// PB11 : I2C2_SDA
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;

		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		MCAL_GPIO_Init(GPIOB, &PinCfg);
	}
	else
	{
		// Do Nothing
	}

}

// Master polling mechanism
void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Start_Condition Start_Con)
{
	// 1. Set the START bit in the I2C_CR1 register to generate a Start condition
	MCAL_I2C_GenerateSTART(I2Cx, ENABLE, Start_Con);

	// 2. Wait for EV5
	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV5)));

	// 3. Send Address
	MCAL_I2C_SendAddress(I2Cx, devAddr, I2C_TRANSMITTER);

	// 4. Wait for EV6
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV6)));

	/* check TRA, BUSY, MSL, TXE flags */
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, MASTER_BYTE_TRANSMITTING)));

	for(uint32_t iterator = 0 ; iterator < dataLen ; iterator++)
	{
		/* Write in the DR the data to be sent */
		I2Cx->DR = dataOut[iterator];

		// 5. Wait for EV8
		// EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register
		while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV8)));
	}
	if(With_Stop == Stop)
	{
		MCAL_I2C_GenerateSTOP(I2Cx, ENABLE);
	}

}


void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Start_Condition Start_Con)
{
	uint8_t index = (I2C1 == I2Cx) ? I2C1_INDEX : I2C2_INDEX;

	// 1. Set the START bit in the I2C_CR1 register to generate a Start condition
	MCAL_I2C_GenerateSTART(I2Cx, ENABLE, Start_Con);

	// 2. Wait for EV5
	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV5)));

	// 3. Send Address
	MCAL_I2C_SendAddress(I2Cx, devAddr, I2C_RECEIVER);

	// 4. Wait for EV6
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV6)));

	MCAL_I2C_AcknowledgeConfig(I2Cx, ENABLE);

	if(dataLen)
	{
		for(uint32_t iterator = dataLen; iterator > 1; iterator--)
		{
			// Wait until RXNE becomes 1
			while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV7)));
			// Read data from data register to buffer
			*dataOut = I2Cx->DR;
			dataOut++;
		}

		MCAL_I2C_AcknowledgeConfig(I2Cx, DISABLE);

		// Wait until RXNE becomes 1
		while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV7)));
		// Read data from data register to buffer
		*dataOut = I2Cx->DR;
	}

	if(With_Stop == Stop)
	{
		MCAL_I2C_GenerateSTOP(I2Cx, ENABLE);
	}
	else
	{
		/* Do Nothing */
	}

	/* Re-enable ack */
	if(I2C_ACK_Enable == Global_I2C_Config[index].I2C_ACK_Control)
	{
		MCAL_I2C_AcknowledgeConfig(I2Cx, ENABLE);
	}
	else
	{
		/* Do Nothing */
	}
}



// Slave interrupt mechanism
void MCAL_I2C_SlaveSendData(I2C_TypeDef *I2Cx, uint8_t data)
{
	I2Cx->DR = data;
}


uint8_t MCAL_I2C_SlaveReceiveData(I2C_TypeDef *I2Cx)
{
	return (uint8_t) I2Cx->DR;
}



// Generic APIs
void MCAL_I2C_GenerateSTART(I2C_TypeDef *I2Cx, FunctionalState NewState, Start_Condition Start_Con)
{
	if(Start == Start_Con)
	{
		/* Check if the bus is idle */
		while(MCAL_I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));
	}
	else
	{
		/* Do Nothing */
	}

	if(ENABLE == NewState)
	{
		I2Cx->CR1 |= I2C_CR1_START;
	}
	else
	{
		I2Cx->CR1 &= ~(I2C_CR1_START);
	}

}


FlagStatus MCAL_I2C_GetFlagStatus(I2C_TypeDef *I2Cx, Status flag)
{
	uint32_t flag1, flag2;
	FlagStatus bitstatus;
	switch(flag)
	{
	case I2C_FLAG_BUSY:
		if((I2Cx->SR2) & (I2C_SR2_BUSY))
		{
			bitstatus = SET;
		}
		else
		{
			bitstatus = RESET;
		}
		break;
	case EV5:
		if((I2Cx->SR1) & (I2C_SR1_SB))
		{
			bitstatus = SET;
		}
		else
		{
			bitstatus = RESET;
		}
		break;
	case EV6:
		if((I2Cx->SR1) & (I2C_SR1_ADDR))
		{
			bitstatus = SET;
		}
		else{
			bitstatus = RESET;
		}
		break;
	case EV7:
		if((I2Cx->SR1) & (I2C_SR1_RXNE))
		{
			bitstatus = SET;
		}
		else
		{
			bitstatus = RESET;
		}
		break;
	case EV8:
	case EV8_1:
		if((I2Cx->SR1) & (I2C_SR1_TXE))
		{
			bitstatus = SET;
		}
		else
		{
			bitstatus = RESET;
		}
		break;
	case MASTER_BYTE_TRANSMITTING:
		flag1 = I2Cx->SR1;
		flag2 = I2Cx->SR2;
		flag2 = flag2 << 16;
		flag1 |= flag2;
		if((flag1 & flag) == flag)
		{
			bitstatus = SET;
		}
		else
		{
			bitstatus = RESET;
		}
		break;

	default:
		bitstatus = RESET;
		break;
	}

	return bitstatus;

}


void MCAL_I2C_SendAddress(I2C_TypeDef *I2Cx, uint16_t Address, I2C_Direction Direction)
{
	Address = (Address << 1) | Direction;
	I2Cx->DR = Address;
}


void MCAL_I2C_GenerateSTOP(I2C_TypeDef *I2Cx, FunctionalState NewState)
{

	if(ENABLE == NewState)
	{
		I2Cx->CR1 |= I2C_CR1_STOP;
	}
	else
	{
		I2Cx->CR1 &= ~(I2C_CR1_STOP);
	}
}

void MCAL_I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
	if(ENABLE == NewState){
		I2Cx->CR1 |= I2C_CR1_ACK;
	}
	else{
		I2Cx->CR1 &= ~(I2C_CR1_ACK_Msk);
	}
}

void I2C1_EV_IRQHandler(void)
{

}

void I2C1_ER_IRQHandler(void)
{

}

void I2C2_EV_IRQHandler(void)
{

}

void I2C2_ER_IRQHandler(void)
{

}





