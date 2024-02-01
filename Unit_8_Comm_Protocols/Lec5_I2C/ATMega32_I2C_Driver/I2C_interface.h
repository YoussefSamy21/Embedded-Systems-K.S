/*
 * I2C_interface.h
 *
 *  Created on: Jan 27, 2024
 *      Author: youssef
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "Utils/STD_LIBRARY.h"
#include "Utils/STD_TYPES.h"
#include "I2C_MemMap.h"
#include "I2C_Config.h"

#define START_ACK                0x08 /* start has been sent */
#define REP_START_ACK            0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */


/* Prescalers */
#define PRESCALLER_BY_1    1
#define PRESCALLER_BY_4    4
#define PRESCALLER_BY_16   16
#define PRESCALLER_BY_64   64


typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	SlaveWriteByteErr,
	SlaveReadByteErr,
}TWI_ErrStatus;

/*Set master address to 0 if master will not be addressed*/
void TWI_voidInitMaster(uint8 Copy_u8Address);

void TWI_voidInitSlave(uint8 Copy_u8Address);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(uint8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(uint8* Copy_pu8DataByte);

TWI_ErrStatus TWI_SlaveWriteDataByte(uint8 Copy_u8DataByte);

TWI_ErrStatus TWI_SlaveReadDataByte(uint8* Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif /* I2C_INTERFACE_H_ */
