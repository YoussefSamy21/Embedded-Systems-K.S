/**
 ******************************************************************************
 *
 * @file           : main.c
 * @author         : Youssef Samy
 *
 */

//#include "STM32F103C6_EXTI_Driver.h"

#include "STM32F103C6_Systick_Driver.h"

static uint8_t TaskA_flag , TaskB_flag , Schedule_Flag = 0;

/*
	We assume here Our Stack Size = 0x400 = 1024 Byte = 1KB (actually it is 10KB in the Linker Script , but just for Simplicity)
	we will divide it into:
	1- 512 Bytes for Main Stack
	2- 100 Bytes for Task A
	3- 100 Bytes for Task B
	// Leaving 8 Bytes between each Stack size from these

 */

/************************************************************************************************************/

/**************************************** STACK Splitting ****************************************/


#define TaskA_Stack_Size 		100 	// 100 Bytes
#define TaskB_Stack_Size 		100 	// 100 Bytes

extern uint32_t _estack ;
/*
	The _estack is the Symbol in the Linker Script for holding the address of the Top of the "Main" Stack ...
	Note the ARM Stack is Full Descending Stack (Start from Highest Address)... (each Push, MSP decreases)
*/


// Main Stack
uint32_t _S_MSP = &_estack ; // Top of the Main Stack
uint32_t _E_MSP ;

// Process Stack Task A
uint32_t _S_PSP_TA ;
uint32_t _E_PSP_TA ;

// Process Stack Task B
uint32_t _S_PSP_TB ;
uint32_t _E_PSP_TB ;

/************************************************************************************************************/


/********************************************* (TASK A | TASK B)  *********************************************/

uint32_t TaskA(uint32_t a , uint32_t b , uint32_t c)
{
	return (a+b+c);
}

uint32_t TaskB(uint32_t a , uint32_t b , uint32_t c , uint32_t d)
{
	return (a+b+c+d);
}


/************************************************************************************************************/


/********************************************* OS Macros *********************************************/

// MACRO to set the PSP Register with the Addresses of TaskA and TaskB
#define OS_SET_PSP(address)		__asm volatile("MOV R0,%0  \n\t   MSR PSP,R0"  :   :"r" (address))

// Set SP to Shadow on PSP instead of MSP (SET Bit1 in CONTROL Register)
#define OS_SWITCH_SP_to_PSP()  	__asm volatile("MRS R0,CONTROL  \n\t   ORR R0,R0,#0x02  \n\t   MSR CONTROL,R0")

// Set SP to Shadow on MSP instead of PSP (Clear Bit1 in CONTROL Register)
#define OS_SWITCH_SP_to_MSP()  	__asm volatile("MRS R0,CONTROL  \n\t   AND R0,R0,#0xFFFFFFFD  \n\t   MSR CONTROL,R0")


// MACRO generating an SVC Exception , to be able to Switch to Privileged Access Level after Calling (Tasks A & B)
#define OS_Generate_SVC_Exception()	__asm volatile("SVC #0x3")


/************************************************************************************************************/


/********************************************* Switch CPU Access Level *********************************************/

#define Switch_CPU_Access_Level_to_Privileged()	 	__asm("MRS R3,CONTROL \n\t   AND R3,R3,#0xFFFFFFFE \n\t MSR CONTROL,R3")
#define Switch_CPU_Access_Level_to_Unprivileged() 	__asm("MRS R3,CONTROL  \n\t  ORR R3,R3,#0x1         \n\t MSR CONTROL,R3")


void SVC_Handler()
{
	Switch_CPU_Access_Level_to_Privileged();
}

enum CPU_AccessLevel
{
	Privileged,
	Unprivileged
};

void Switch_CPU_Access_Level(enum CPU_AccessLevel level)
{
	switch(level)
	{
	case Privileged:
		// Clear Bit 0 in CONTROL Register
		__asm("MRS R3,CONTROL 	\n\t"
				"AND R3,R3,#0xFFFFFFFE \n\t"
				"MSR CONTROL,R3");
		break;

	case Unprivileged:
		// SET Bit 0 in CONTROL Register
		__asm("MRS R3,CONTROL 	\n\t"
				"ORR R3,R3,#0x1 \n\t"
				"MSR CONTROL,R3");

		break;

	}

}

/************************************************************************************************************/

/*********************************************   Main OS   *********************************************/
void MainOS()
{
	// Main Stack
	_E_MSP = (_S_MSP - 512);

	//Task A
	_S_PSP_TA = (_E_MSP - 8);
	_E_PSP_TA = (_S_PSP_TA - TaskA_Stack_Size);

	//Task B
	_S_PSP_TB = (_E_PSP_TA - 8);
	_E_PSP_TB = (_S_PSP_TB - TaskB_Stack_Size);

	while(1)
	{
		__asm("NOP");


		if(TaskA_flag == 1)
		{
			/*
				1- Set PSP Register to _S_PSP_TA
				2- SP --> PSP (Bit1 in CONTROL Register)
				3- Switch from Privileged ---> Unprivileged
				4- Call TaskA
				(Note that TaskA is not in while(1) , so each return it pops all values and return again to _S_PSP_TA)

			 */
			OS_SET_PSP(_S_PSP_TA);
			OS_SWITCH_SP_to_PSP();
			Switch_CPU_Access_Level_to_Unprivileged();


			TaskA_flag = TaskA(1, 2, 3);

			// 1- Switch from Unprivileged --> Privileged (using SVC SWI)
			// 2- SP --> MSP
			OS_Generate_SVC_Exception();
			OS_SWITCH_SP_to_MSP();

		}
		else if(TaskB_flag == 1)
		{
			// Same Steps for TaskA
			OS_SET_PSP(_S_PSP_TB);
			OS_SWITCH_SP_to_PSP();
			Switch_CPU_Access_Level_to_Unprivileged();


			TaskB_flag = TaskB(1, 2, 3, 4);

			// 1- Switch from Unprivileged --> Privileged (using SVC Handler)
			// 2- SP --> MSP
			OS_Generate_SVC_Exception();
			OS_SWITCH_SP_to_MSP();
		}
	}
}

/************************************************************************************************************/


void Scheduler_Func(void)
{
	// Our Task Scheduling between Tasks A & B is Enhanced to be based on the Systick timer instead of the EXTI

	if(Schedule_Flag == 0)
	{
		TaskA_flag = 1;
		Schedule_Flag = 1;
	}
	else // Schedule_Flag = 1
	{
		TaskB_flag = 1;
		Schedule_Flag = 0;
	}
}

int main(void)
{
	// Enable the clocks
	// RCC_GPIOA_CLK_EN();
	// RCC_GPIOB_CLK_EN();
	// RCC_AFIO_CLK_EN();

	// Configure the EXTI Pin
	// EXTI_PinConfig_t PinCfg;
	// Switch_CPU_AccessLevel(Unprivileged);
	/*
		if we switch to unprivileged mode before accessing NVIC in EXTI configuration
		the NVIC will not be configured resulting in Fault Handler Exception,
		So in this case we can switch to privileged mode in the hard fault handler as we have access on the
		Control Register only in the Privilege mode and Generally , Handler mode is always Privileged
	 */
	// PinCfg.EXTI_PIN = EXTI9PB9;
	// PinCfg.Trigger_Case = EXTI_TRIGGER_RISING;
	// PinCfg.P_IRQ_CallBack = EXTIB9_CallBack;
	// PinCfg.IRQ_EN = EXTI_STATE_ENABLE;
	// MCAL_EXTI_GPIO_Init(&PinCfg);

	// Switch_CPU_Access_Level(Unprivileged); // will Switch to Unprivileged by accessing CONTROL Register
	// Switch_CPU_Access_Level(Privileged);
	// This Line will not be executed , because switching from Unprivileged to Privileged is Available ONLY in Handler Mode



	/********************** Enhanced Scheduling Point ===> Systick Timer (instead of EXTI) **********************/

	Systick_Init(CLK_AHB_8); // AHB / 8 = 1MHz

	Systick_Set_Time_CallBack(1000000, Periodic, Scheduler_Func);

	MainOS();

	while (1)
	{

	}
}
