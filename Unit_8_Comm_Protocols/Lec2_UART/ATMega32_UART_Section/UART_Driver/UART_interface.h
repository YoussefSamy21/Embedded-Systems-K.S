/*
 * UART_interface.h
 *
 *  Created on: Dec 15, 2023
 *      Author: youssef
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_MemMap.h"
#include "UART_Config.h"
#include "Utils/STD_LIBRARY.h"
#include "Utils/STD_TYPES.h"

#define Default_Stop	'\r' // Until Enter (0x0d)

void UART_Init(void);

/******* Polling Mechanism *******/
void UART_Send_Byte(uint8 data);
uint8 UART_Receive_Byte(void);

/******* Periodic Check (No Block) *******/
// the aim of these functions to not block or delaying the main function
uint8 UART_Send_Byte_NoBlock(uint8 *pdata);
uint8 UART_Receive_Byte_NoBlock(uint8 *pdata);

/******* CallBack Functions *******/
void UART_Tx_Set_CallBack(void (*LocalFptr)(void));
void UART_Rx_Set_CallBack(void (*LocalFptr)(void));

/******* Tx/Rx Interrupt Enable *******/
void UART_Tx_Interrupt_Enable(void);
void UART_Rx_Interrupt_Enable(void);

/******* Tx/Rx Interrupt Disable *******/
void UART_Tx_Interrupt_Disable(void);
void UART_Rx_Interrupt_Disable(void);

/*******************************************************************************************************************************/
/********* String APIs *********/
void UART_Send_String(uint8 *pStr);
void UART_Send_String_Asynch(uint8 *pStr);

void UART_Receive_String(uint8 *pStr); // Receive until the Default_Stop Macro
void UART_Receive_String_Asynch(uint8 *pStr); // Receive until the Default_Stop Macro
uint8 UART_GET_Def_Stop_Flag(void); // Getter Function returns the Def_Stop_Flag (Used in the Asynch Receiving_String_API)

void UART_Send_Byte_inISR(uint8 data);
uint8 UART_Receive_Byte_inISR(void);

#endif /* UART_INTERFACE_H_ */
