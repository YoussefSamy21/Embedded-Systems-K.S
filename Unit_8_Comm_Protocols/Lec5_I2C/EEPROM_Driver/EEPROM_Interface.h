/*
 * EEPROM_Interface.h
 *
 *  Created on: Feb 1, 2024
 *      Author: youssef
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "EEPROM_Config.h"
#include "MCAL/ATMega32_I2C_Driver/I2C_interface.h"


void EEPROM_voidSendDataByte(uint16 Copy_u16LocationAddress, uint8 Copy_u8DataByte);

uint8 EEPROM_u8ReadDataByte(uint16 Copy_u16LocationAddress);



#endif /* EEPROM_INTERFACE_H_ */
