/*
 * EEPROM_Interface.c
 *
 *  Created on: Feb 1, 2024
 *      Author: youssef
 */


#include "EEPROM_Interface.h"
#include <util/delay.h>

void EEPROM_voidSendDataByte(uint16 Copy_u16LocationAddress, uint8 Copy_u8DataByte)
{
	uint8 Local_Address_Packet;

	Local_Address_Packet = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8)(Copy_u16LocationAddress >>8);
	// In 24C02 : Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(Local_Address_Packet);
	TWI_MasterWriteDataByte((uint8) Copy_u16LocationAddress); // Send the rest 8bits of the location address

	TWI_MasterWriteDataByte(Copy_u8DataByte);

	TWI_SendStopCondition();

	_delay_ms(10);
}

uint8 EEPROM_u8ReadDataByte(uint16 Copy_u16LocationAddress)
{
	uint8 Local_Address_Packet , Local_data;

	Local_Address_Packet = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8)(Copy_u16LocationAddress >>8);
	// In 24C02 : Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(Local_Address_Packet);
	TWI_MasterWriteDataByte((uint8) Copy_u16LocationAddress); // Send the rest 8bits of the location address

	TWI_SendRepeatedStart(); // send repeated start to change from write request to read request

	TWI_SendSlaveAddressWithRead(Local_Address_Packet);

	TWI_MasterReadDataByte(&Local_data);

	TWI_SendStopCondition();

	return Local_data;
}
