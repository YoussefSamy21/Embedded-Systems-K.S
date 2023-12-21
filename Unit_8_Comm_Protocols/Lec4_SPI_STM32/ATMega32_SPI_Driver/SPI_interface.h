/*
 * SPI_interface.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Youssef Samy
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#include "SPI_MemMap.h"
#include "SPI_Config.h"
#include "Utils/STD_TYPES.h"
#include "Utils/STD_LIBRARY.h"

#include "DIO/DIO_INTERFACE.h" // for Initializing the SPI Master/Slave Pins (SS , MOSI , MISO , SClck)

void SPI_InitMaster(void);
void SPI_InitSlave(void);
uint8 SPI_SendReceive(uint8 data);

uint8 SPI_Recieve_PeriodicCheck(uint8 *ptr_data);

// Called Functions in ISR (directly return or send data in the Register without any checking)
void SPI_Send_NoBlock(uint8 data);
uint8 SPI_Receive_NoBlock(void);

// Interrupt Functions
void SPI_Interrupt_Enable(void);
void SPI_Interrupt_Disable(void);
void SPI_Set_CallBack(void (*LocalFptr)(void));




#endif /* SPI_INTERFACE_H_ */
