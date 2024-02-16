/**
 ******************************************************************************
 *
 * @file           : main.c
 * @author         : Youssef Samy
 * Lab2 ===> SVC and PendSV
 *
 */
#include "STM32F103C6_EXTI_Driver.h"

uint32_t OS_SVC_Set(uint32_t a , uint32_t b , uint32_t SVC_ID)
{
	uint32_t result;
	switch(SVC_ID)
	{
		case 0:
			__asm("SVC #0x00"); // OS ADD
			break;
		case 1:
			__asm("SVC #0x01"); // OS SUB
			break;
		case 2:
			__asm("SVC #0x02");	 // OS MUL
			break;
	}
	//Now, the result is in R0 , we want to put R0 value in the result variable
	__asm("MOV %0, R0"	: "=r"(result));

	return result;
}


__attribute ((naked)) void SVC_Handler()
{
	__asm( "TST    LR, #0x04  \n\t"
		    "ITE    EQ        \n\t"
			"MRSEQ  R0, MSP   \n\t"
			"MRSNE  R0, PSP   \n\t"
			"B      OS_SVC");

}


void OS_SVC(uint32_t *StackFrame_ptr)
{
	// StackFrame: R0 , R1 , R2 , R3 , R12 , LR , PC , xPSR
	uint8_t SVC_Number;
	uint32_t val_1 , val_2;

	val_1 = StackFrame_ptr[0];
	val_2 = StackFrame_ptr[1];

	SVC_Number = *( ((uint8_t*) ((uint8_t*)StackFrame_ptr[6]) - 2 ) );
	// it can also be written as:
	// SVC_Number =  ((uint8_t*)StackFrame_ptr[6]) [-2];

	switch(SVC_Number)
	{
		case 0:
			StackFrame_ptr[0] = val_1 + val_2; // OS ADD
			break;
		case 1:
			StackFrame_ptr[0] = val_1 - val_2; // OS SUB
			break;
		case 2:
			StackFrame_ptr[0] = val_1 * val_2; // OS MUL
			break;
	}
}


int main(void)
{
	uint32_t result;

	result = OS_SVC_Set(3, 2, 0); // ADD
	result = OS_SVC_Set(3, 2, 1); // SUB
	result = OS_SVC_Set(3, 2, 2); // Mul


	while (1)
	{

	}
}

