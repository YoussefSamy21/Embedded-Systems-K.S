/*
 * I2C_MemMap.h
 *
 *  Created on: Jan 27, 2024
 *      Author: youssef
 */

#ifndef I2C_MEMMAP_H_
#define I2C_MEMMAP_H_

#define TWBR    (*(volatile unsigned char*)0x20) // Bit Rate Register
#define TWSR    (*(volatile unsigned char*)0x21) // Status Register
#define TWAR    (*(volatile unsigned char*)0x22) // Address Register
#define TWDR    (*(volatile unsigned char*)0x23) // Data Register
#define TWCR    (*(volatile unsigned char*)0x56) // Control Register

/* TWCR */
#define TWCR_TWINT	7							/*Interrupt Flag*/
#define TWCR_TWEA	6                           /*Enable Acknowledge*/
#define TWCR_TWSTA	5                           /*Start Condition*/
#define TWCR_TWSTO	4                           /*Stop Condition*/
#define TWCR_TWWC	3                           /*Write Collision*/
#define TWCR_TWEN	2                           /*Enable*/
/* bit 1 reserved */
#define TWCR_TWIE	0                           /*Interrupt Enable*/


/* TWAR */
#define TWAR_TWGCE	0							/*General Call recognition Enable*/
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0



#endif /* I2C_MEMMAP_H_ */
