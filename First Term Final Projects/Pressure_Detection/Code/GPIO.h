/*
    Eng.Youssef Mohamed Samy
*/

#ifndef GPIO_H_
#define GPIO_H_

#include "Platform_Types.h"
#include "BIT_MATH.h"

// RCC Def
#define BASE_RCC   0x40021000
#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)

// GPIOA Def
#define GPIO_PORTA 0x40010800
#define GPIOA_CRL *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

// APIs
void GPIO_Delay( uint32_t nCount);
void GPIO_Init(void);
uint32_t GPIO_Get_Pressure_Value(void);
void GPIO_Start_Alarm_Actuator(void);
void GPIO_Stop_Alarm_Actuator(void);

#endif /* GPIO_H_ */
