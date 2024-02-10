/*
 * EEPROM.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Youssef Samy
 */

#ifndef EEPROM_DRIVER_EEPROM_H_
#define EEPROM_DRIVER_EEPROM_H_

#include "STM32F103C6_I2C_Driver.h"

#define EEPROM_Slave_Address	0x2A
#define EEPROM_I2C				I2C1

void EEPROM_Init(void);
void EEPROM_Write_nBytes(uint16_t Memory_Address, uint8_t *Data, uint8_t Data_Length);
void EEPROM_Read_nBytes(uint16_t Memory_Address, uint8_t *DataOut, uint8_t Data_Length);



#endif /* EEPROM_DRIVER_EEPROM_H_ */
