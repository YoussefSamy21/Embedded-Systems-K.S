/*
	Author: Youssef Samy
 */


/*
  What We Need:
  -------------
  When Pressed Button Connected to PA0 (GPIO A) ===> EXTI0 Line ===>  NVIC ===> CPU ===> (Toggling LED in ISR(EXTI0 Handler))

 */
#include "Platform_Types.h"

// RCC
#define RCC_BASE    0x40021000
#define RCC_APB2ENR *((vuint32_t*)(RCC_BASE + 0x18))
#define RCC_CFGR    *((vuint32_t*)(RCC_BASE + 0x04))

// GPIOA
#define GPIOA_BASE  0x40010800
#define GPIOA_CRL   *((vuint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_CRH   *((vuint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_ODR   *((vuint32_t*)(GPIOA_BASE + 0x0C))

// EXTI
#define EXTI_BASE 			0x40010400
#define EXTI_IMR			*((vuint32_t*)(EXTI_BASE + 0x00))	// Interrupt mask register
#define EXTI_RTSR			*((vuint32_t*)(EXTI_BASE + 0x08))	// Rising trigger selection register
#define EXTI_PR				*((vuint32_t*)(EXTI_BASE + 0x14))	// Pending Register

// AFIO
#define AFIO_BASE			0x40010000
#define AFIO_EXTICR1		*((vuint32_t*)(AFIO_BASE + 0x08)) //EXTI Configuration Register

//NVIC
#define NVIC_BASE 			0xE000E100
#define NVIC_EXTI0_EN		*((vuint32_t*) (NVIC_BASE + 0x00))


void Clock_init()
{
	RCC_APB2ENR |= (1<<2);      // Enable Clock for GPIOA
	RCC_APB2ENR |= (1<<0);      // Enable Clock for AFIOA
}

void GPIO_init()
{
	// PORTA -> PIN13 -> OUTPUT
	GPIOA_CRH &= 0xFF0FFFFF; 	// Clearing first before changing
	GPIOA_CRH |= 0x00200000;

	// PORTA -> PIN0 -> FLOATING INPUT
	GPIOA_CRL |= (1<<2);
}

int main(void)
{

	Clock_init();
	GPIO_init();

	// Enable EXTI0 Line to be Connected with GPIOA (using the Alternative Pins (AFIOA))
	AFIO_EXTICR1 = 0; // it is configured by default (0000 for EXTI0)

	// Enable Rising Edge for EXTI0 Line
	EXTI_RTSR |= (1<<0);

	// Enable EXTI0 Line
	EXTI_IMR |= (1<<0);

	// Enable NVIC IRQ 6 (EXTI0)
	NVIC_EXTI0_EN |= (1<<6);


	while(1);
}

void EXTI0_IRQHandler()
{
	/**** EXTI0 Pending Request MUST be CLEARED in the Handler to Avoid infinite Interrupt Looping (Write 1 to Clear) ****/
	EXTI_PR |= (1<<0);

	// LED TOGGLE
	GPIOA_ODR ^= (1<<13);
}

