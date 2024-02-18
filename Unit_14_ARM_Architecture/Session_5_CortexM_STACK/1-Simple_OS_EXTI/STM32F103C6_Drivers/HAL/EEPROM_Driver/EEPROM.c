/*
 * EEPROM.c
 *
 *  Created on: Jan 31, 2024
 *      Author: youssef
 */

#include "EEPROM.h"

void EEPROM_Init(void)
{
	I2C_Config I2C1_CFG;

	I2C1_CFG.General_Call_Address_Detection = I2C_ENGC_Enable;
	I2C1_CFG.I2C_ACK_Control = I2C_ACK_Enable;
	I2C1_CFG.I2C_ClockSpeed = I2C_SCLK_SM_100K;
	I2C1_CFG.I2C_Mode = I2C_Mode_I2C;
	I2C1_CFG.P_Slave_Event_CallBack = NULL;
	I2C1_CFG.StretchMode = I2C_StretchMode_Enable;

	MCAL_I2C_Init(EEPROM_I2C, &I2C1_CFG);
}


void EEPROM_Write_nBytes(uint16_t Memory_Address, uint8_t *Data, uint8_t Data_Length)
{
	uint8_t i;
	uint8_t buffer[256] = {0};
	buffer[0] = (uint8_t) (Memory_Address >> 8);
	buffer[1] = (uint8_t) (Memory_Address);
	for(i = 2; i < (Data_Length+2); i++)
	{
		buffer[i] = Data[i-2];
	}
	MCAL_I2C_Master_TX(EEPROM_I2C, EEPROM_Slave_Address, buffer, (Data_Length+2), With_Stop, Start);

}


void EEPROM_Read_nBytes(uint16_t Memory_Address, uint8_t *DataOut, uint8_t Data_Length)
{
	uint8_t buffer[2];
	buffer[0] = (uint8_t) (Memory_Address >> 8);
	buffer[1] = (uint8_t) (Memory_Address);

	MCAL_I2C_Master_TX(EEPROM_I2C, EEPROM_Slave_Address, buffer, 2, Without_Stop, Start);
	MCAL_I2C_Master_RX(EEPROM_I2C, EEPROM_Slave_Address, DataOut, Data_Length, With_Stop, Repeated_Start);

}
