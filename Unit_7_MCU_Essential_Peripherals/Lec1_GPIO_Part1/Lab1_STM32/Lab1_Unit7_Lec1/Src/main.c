/*
 	 Author: Youssef Samy
 	  Date: 1/12/2023
 */

#include "Platform_Types.h"

#define GET_BIT(VAR,BIT)	((VAR>>BIT)&0x01)
// RCC
#define RCC_BASE    0x40021000
#define RCC_APB2ENR *((vuint32_t*)(RCC_BASE + 0x18))
#define RCC_CFGR    *((vuint32_t*)(RCC_BASE + 0x04))

// GPIOA
#define GPIOA_BASE  0x40010800
#define GPIOA_CRL   *((vuint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_CRH   *((vuint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_ODR   *((vuint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR   *((vuint32_t*)(GPIOA_BASE + 0x08))


// GPIOB
#define GPIOB_BASE  0x40010C00
#define GPIOB_CRL   *((vuint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_CRH   *((vuint32_t*)(GPIOB_BASE + 0x04))
#define GPIOB_ODR   *((vuint32_t*)(GPIOB_BASE + 0x0C))
#define GPIOB_IDR   *((vuint32_t*)(GPIOB_BASE + 0x08))


void Clock_init()
{
	RCC_APB2ENR |= (1<<2);      // Enable Clock for GPIOA
	RCC_APB2ENR |= (1<<3);		// Enable Clock for GPIOB
}

void GPIO_init()
{
	GPIOA_CRL = 0x00;
	GPIOB_CRL = 0x00;

	// PA1 ==> I/P (Floating)
	GPIOA_CRL &= ~(0b11<<4); // Input Mode
	GPIOA_CRL |= (0b1<<6); 	// "Floating" Input Mode

	// PA13 ==> I/P (Floating)
	GPIOA_CRH &= ~(0b11<<20); // Input Mode
	GPIOA_CRH |= (0b01<<22); // "Floating" Input Mode

	// PB1 ==> O/P (PushPull)
	GPIOB_CRL |= (0b01<<4);   // output mode with speed 10 MHZ
	GPIOB_CRL &= ~(0b11<<6); //  Push-Pull output

	// PB13 ==> O/P (PushPull)
	GPIOB_CRH |= (0b01<<20);  // output mode with speed 10 MHZ
	GPIOB_CRH &= ~(0b11<<22); // Push-Pull output

}

void My_Wait(uint32_t x) // Delay Function
{
	uint32_t i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<255;j++);
	}
}

void main(void)
{

	Clock_init();
	GPIO_init();

	while(1)
	{
		if(GET_BIT(GPIOA_IDR , 1) == 0)	// PULL UP Pin
		{
			GPIOB_ODR ^= (1<<1);
			while(GET_BIT(GPIOA_IDR , 1) == 0); // Single Pressing
		}

		if(GET_BIT(GPIOA_IDR , 13) == 1) // PULL Down Pin 
		{
			// Multi-Pressing
			GPIOB_ODR ^= (1<<13);
			My_Wait(1);
		}

	}
}


