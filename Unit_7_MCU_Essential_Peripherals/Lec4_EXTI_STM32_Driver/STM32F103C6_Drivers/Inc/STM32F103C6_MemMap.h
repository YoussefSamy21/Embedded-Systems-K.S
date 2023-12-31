/*
 * STM32F103x6_MemMap.h
 *
 *  Created on: Dec 5, 2023
 *      Author: youssef
 */

#ifndef STM32F103C6_MEMMAP_H_
#define STM32F103C6_MEMMAP_H_

//-----------------------------
//Includes
//-----------------------------

#include "Platform_Types.h"
#include "Utils.h"

/*********************************************** Base addresses for Memories ***********************************************/

#define FLASH_Memory_BASE 							0x08000000UL
#define System_Memory_BASE 							0x1FFFF000UL
#define SRAM_Memory_BASE 							0x20000000UL


#define Peripherals_BASE 							0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE 		0xE0000000UL


/*********************************************** Core Peripherals ***********************************************/
// NVIC
#define NVIC_BASE_ADDERESS					0xE000E100UL
#define NVIC_ISER0							*((vuint32_t*)	NVIC_BASE_ADDERESS + 0x000)
#define NVIC_ISER1							*((vuint32_t*)	NVIC_BASE_ADDERESS + 0x004)
#define NVIC_ISER2							*((vuint32_t*)	NVIC_BASE_ADDERESS + 0x008)
#define NVIC_ICER0							*((vuint32_t*)	NVIC_BASE_ADDERESS + 0x080)
#define NVIC_ICER1							*((vuint32_t*)	NVIC_BASE_ADDERESS + 0x084)
#define NVIC_ICER2							*((vuint32_t*)	NVIC_BASE_ADDERESS + 0x088)


/*********************************************** Peripherals Base Addresses ***********************************************/

/********** Base Addresses for AHB Peripherals **********/
//RCC
#define RCC_BASE 							0x40021000UL


/********** Base Addresses for APB1 Peripherals **********/



/********** Base Addresses for APB2 Peripherals **********/

//GPIO
#define GPIOA_BASE 							0x40010800UL
#define GPIOB_BASE 							0x40010C00UL
#define GPIOC_BASE 							0x40011000UL
#define GPIOD_BASE 							0x40011400UL
#define GPIOE_BASE 							0x40011800UL

//EXTI
#define EXTI_BASE 							0x40010400UL

//AFIO
#define AFIO_BASE 							0x40010000UL



/*********************************************** Peripheral Registers ***********************************************/

/********** GPIO **********/
typedef struct
{
	volatile uint32_t  CRL ;
	volatile uint32_t  CRH ;
	volatile uint32_t  IDR ;
	volatile uint32_t  ODR ;
	volatile uint32_t  BSRR ;
	volatile uint32_t  BRR ;
	volatile uint32_t  LCKR ;
}GPIO_TypeDef;

/********** RCC **********/
typedef struct
{
	volatile uint32_t  CR ;
	volatile uint32_t  CFGR ;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;

/********** EXTI **********/
typedef struct
{
	volatile uint32_t  IMR ;
	volatile uint32_t  EMR ;
	volatile uint32_t  RTSR ;
	volatile uint32_t  FTSR ;
	volatile uint32_t  SWIER ;
	volatile uint32_t  PR ;

}EXTI_TypeDef;

/********** AFIO **********/
typedef struct
{
	volatile uint32_t  EVCR ;
	volatile uint32_t  MAPR ;
	volatile uint32_t EXTICR[4]; // the four EXTICR Registers are merged in an array to facilitate the EXTI driver
	uint32_t  		   RESERVED0 ; //0x18
	volatile uint32_t  MAPR2 ; // 0x1c


}AFIO_TypeDef;


/*********************************************** Peripheral Instants ***********************************************/

#define GPIOA      					((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB      					((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC      					((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD      					((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE      					((GPIO_TypeDef *)GPIOE_BASE)

#define RCC      					((RCC_TypeDef *)RCC_BASE)

#define EXTI      					((EXTI_TypeDef *)EXTI_BASE)

#define AFIO      					((AFIO_TypeDef *)AFIO_BASE)


/************************************** Peripheral Macros *************************************/
// EXTI Lines
#define EXTI0          	0
#define EXTI1          	1
#define EXTI2          	2
#define EXTI3          	3
#define EXTI4          	4
#define EXTI5          	5
#define EXTI6          	6
#define EXTI7          	7
#define EXTI8          	8
#define EXTI9          	9
#define EXTI10          10
#define EXTI11          11
#define EXTI12          12
#define EXTI13          13
#define EXTI14          14
#define EXTI15          15

// EXTI IRQ Handlers
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40


/*********************************************** Clock Enable Macros ***********************************************/
#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1<<0)
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<6)


/************************************** Core Peripherals Macros *************************************/

/*********************** NVIC ****************************/

#define NVIC_IRQ6_EXTI0_ENABLE()				NVIC_ISER0 |= (1<<6)
#define NVIC_IRQ7_EXTI1_ENABLE()				NVIC_ISER0 |= (1<<7)
#define NVIC_IRQ8_EXTI2_ENABLE()				NVIC_ISER0 |= (1<<8)
#define NVIC_IRQ9_EXTI3_ENABLE()				NVIC_ISER0 |= (1<<9)
#define NVIC_IRQ10_EXTI4_ENABLE()				NVIC_ISER0 |= (1<<10)
#define NVIC_IRQ23_EXTI9_5_ENABLE()				NVIC_ISER0 |= (1<<23)
#define NVIC_IRQ40_EXTI15_10_ENABLE()			NVIC_ISER1 |= (1<<8)

#define NVIC_IRQ6_EXTI0_DISABLE()				NVIC_ICER0 |= (1<<6)
#define NVIC_IRQ7_EXTI1_DISABLE()				NVIC_ICER0 |= (1<<7)
#define NVIC_IRQ8_EXTI2_DISABLE()				NVIC_ICER0 |= (1<<8)
#define NVIC_IRQ9_EXTI3_DISABLE()				NVIC_ICER0 |= (1<<9)
#define NVIC_IRQ10_EXTI4_DISABLE()				NVIC_ICER0 |= (1<<10)
#define NVIC_IRQ23_EXTI9_5_DISABLE()			NVIC_ICER0 |= (1<<23)
#define NVIC_IRQ40_EXTI15_10_DISABLE()			NVIC_ICER1 |= (1<<8)

#endif /* STM32F103C6_MEMMAP_H_ */
