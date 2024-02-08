/*
 * STM32F103C6_I2C_Driver.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Youssef Samy
 */

#ifndef STM32F103C6_I2C_DRIVER_H_
#define STM32F103C6_I2C_DRIVER_H_

#include "STM32F103C6_MemMap.h"
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_RCC_Driver.h"

// User type definitions

struct S_I2C_Slave_Device_Address
{
	uint16_t	Dual_ADD_ack;
	uint16_t  Primary_Slave_Address;
	uint16_t	Secondary_Slave_Address;
	uint32_t 	I2C_Adressing_Slave_Mode; // @ref I2C_Adressing_Slave_define
};

typedef enum
{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADDR_Matched,
	I2C_EV_DATA_REQ, // the APP layer should send the data
	I2C_EV_DATA_RCV	 // the APP layer should read the data
}Slave_State;

typedef enum
{
	With_Stop,
	Without_Stop
}Stop_Condition;

typedef enum
{
	Start,
	Repeated_Start
}Start_Condition;

typedef enum
{
	DISABLE,
	ENABLE
}FunctionalState;

typedef enum
{
	RESET,
	SET
}FlagStatus;

typedef enum
{
	I2C_FLAG_BUSY,
	EV5, 	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	EV6, 	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	EV7,	// EV7: RxNE=1 cleared by reading DR register
	EV8,  	// EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register
	EV8_1, 	// EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR
	MASTER_BYTE_TRANSMITTING = ((uint32_t)0x00070080) /* TRA, BUSY, MSL, TXE flags */

}Status;

typedef enum
{
	I2C_TRANSMITTER = 0,
	I2C_RECEIVER = 1
}I2C_Direction;

typedef struct
{
	uint32_t 								I2C_ClockSpeed; 	/* Specifies the clock frequency.
															This parameter must be set to @ref I2C_SCLK_define */

	uint32_t 								StretchMode;		// @ref I2C_StretchMode_define

	uint32_t 								I2C_Mode;			/* Specifies the I2C mode.
															This parameter can be a value of @ref I2C_Mode_define */

	struct S_I2C_Slave_Device_Address 		I2C_Slave_Address;

	uint32_t								I2C_ACK_Control;	/* This enables or disables the acknowledgment.
															This parameter can be a value of @ref I2C_ACK_define */

	uint32_t 								General_Call_Address_Detection;	// @ref I2C_ENGC_define

	void (*P_Slave_Event_CallBack)(Slave_State state);		// Sets the callback function

}I2C_Config;

// ===========================================================================================================================


// Macros Configuration References

// Configure the rise time register I2C_TRISE
#define I2C_SCLK_SM_50K					(50000U)
#define I2C_SCLK_SM_100K				(100000U)
#define I2C_SCLK_FM_200K				(200000U) // Fast mode not supported yet
#define I2C_SCLK_FM_400K				(400000U) // Fast mode not supported yet

// @ref I2C_StretchMode_define
#define I2C_StretchMode_Enable			0x00000000U
#define I2C_StretchMode_Disable 		I2C_CR1_NOSTRETCH

// @ref I2C_Mode_define
#define I2C_Mode_I2C					0x00000000U
#define I2C_Mode_SMBus					I2C_CR1_SMBUS

// @ref I2C_Adressing_Slave_define
#define I2C_Adressing_Slave_Mode_7Bit	0x00000000U
#define I2C_Adressing_Slave_Mode_10Bit	0x00000000U

// @ref I2C_ACK_define
#define I2C_ACK_Enable					I2C_CR1_ACK
#define I2C_ACK_Disable					0x00000000U

// @ref I2C_ENGC_define
#define I2C_ENGC_Enable					I2C_CR1_ENGC
#define I2C_ENGC_Disable				0x00000000U

// ===========================================================================================================================

void MCAL_I2C_Init(I2C_TypeDef *I2Cx, I2C_Config *I2C_cfg);
void MCAL_I2C_DeInit(I2C_TypeDef *I2Cx);
void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef *I2Cx);

// Master polling mechanism
void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Start_Condition Start_Con);
void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Start_Condition Start_Con);

// Slave interrupt mechanism
void MCAL_I2C_SlaveSendData(I2C_TypeDef *I2Cx, uint8_t data);
uint8_t MCAL_I2C_SlaveReceiveData(I2C_TypeDef *I2Cx);

// Generic APIs
void MCAL_I2C_GenerateSTART(I2C_TypeDef *I2Cx, FunctionalState NewState, Start_Condition Start_Con);
FlagStatus MCAL_I2C_GetFlagStatus(I2C_TypeDef *I2Cx, Status flag);
void MCAL_I2C_SendAddress(I2C_TypeDef *I2Cx, uint16_t Address, I2C_Direction Direction);
void MCAL_I2C_GenerateSTOP(I2C_TypeDef *I2Cx, FunctionalState NewState);
void MCAL_I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx, FunctionalState NewState);




#endif /* STM32F103C6_I2C_DRIVER_H_ */
