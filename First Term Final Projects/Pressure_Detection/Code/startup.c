/*
	startup_Cortex_M3.c
	Eng. Youssef Mohamed Samy
*/

#include "Platform_Types.h"
extern void main(void);

void Reset_Handler ();
void Default_Handler ()
{
	Reset_Handler();
}
void NMI_Handler () 			__attribute__ ((weak,alias ("Default_Handler")));
void H_Fault_Handler () 		__attribute__ ((weak,alias ("Default_Handler")));
void MM_Fault_Handler () 		__attribute__ ((weak,alias ("Default_Handler")));
void Bus_Fault () 				__attribute__ ((weak,alias ("Default_Handler")));
void Usage_Fault_Handler () 	__attribute__ ((weak,alias ("Default_Handler")));


extern uint32_t _stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) = 
{
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler,
};
	
// using the Symbols in the Linker Script file for the start and end of the .data & .bss sections	
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

void Reset_Handler ()
{
	//Copying .data from FLASH to SRAM
	uint32_t data_size=(uint8_t *)&_E_data - (uint8_t *)&_S_data;
	uint8_t * P_src =(uint8_t *)&_E_text;   // Pointer to the Source Location which is FLASH
	uint8_t * P_dst =(uint8_t *)&_S_data;   // Pointer to the Destination Location which is SRAM
    uint32_t i;
	for(i=0 ; i < data_size ; i++)
    {
		// Copying Data Byte by Byte
        *((uint8_t *)P_dst)=*((uint8_t *)P_src);
        P_src++;
        P_dst++;
	}

	// Creating the .bss section in SRAM & Initializing it by 0

	uint32_t bss_size=(uint8_t *)&_E_bss - (uint8_t *)&_S_bss;
	P_dst =(uint8_t *)&_S_bss;
	for(i=0 ; i < bss_size ; i++)
    {
		*((uint8_t *)P_dst)=(uint8_t)0;
        P_dst++;
	}
    	
	main(); // Branch to main
}


