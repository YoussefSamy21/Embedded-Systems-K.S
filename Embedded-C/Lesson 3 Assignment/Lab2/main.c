
#include "Platform_Types.h"

#define RCC_BASE 		0x40021000
#define GPIOA_BASE 		0x40010800

#define RCC_APB2ENR  *((vuint32_t *)(RCC_BASE + 0x18))
#define GPIOA_CRH    *((vuint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR    *((vuint32_t *)(GPIOA_BASE + 0x0C))

typedef union
{
	vuint32_t all_fields;
	struct
	{
		vuint32_t reserved:13;
		vuint32_t pin13:1;

	}pin;

} R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

void main(void)
{
	uint32_t i;
	RCC_APB2ENR |= 1<<2;		// SET Bit 2 of APB2ENR to enable the RCC
	GPIOA_CRH &= 0xff0fffff; 	// Clear bits 20 to 23
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		R_ODR->pin.pin13 = 1;
		for(i = 0; i < 5000; i++);		// arbitrary delay

		R_ODR->pin.pin13 = 0;


		for(i = 0; i < 5000; i++);		// arbitrary delay
	}
}
