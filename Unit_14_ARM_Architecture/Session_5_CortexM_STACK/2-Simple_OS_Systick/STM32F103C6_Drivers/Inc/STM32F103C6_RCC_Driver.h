/*
 * STM32F103C6_RCC_Driver.h
 *
 *  Created on: Dec 16, 2023
 *      Author: youssef
 */

#ifndef STM32F103C6_RCC_DRIVER_H_
#define STM32F103C6_RCC_DRIVER_H_

#include "STM32F103C6_MemMap.h"

#define  HSE_Clock			(uint32_t)16000000
#define  HSI_RC_Clk			(uint32_t)8000000

uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);



#endif /* STM32F103C6_RCC_DRIVER_H_ */
