/*
 * EXT_interrupt_interface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: youssef
 */

#ifndef EXT_INTERRUPT_INTERFACE_H_
#define EXT_INTERRUPT_INTERFACE_H_

#include "STD_TYPES.h"
#include "STD_LIBRARY.h"
#include "EXT_interrupt_RegMap.h"

typedef enum
{
	EX_INT0=0,
	EX_INT1,
	EX_INT2

}EX_InterruptSource_type;

typedef enum
{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE

}TriggerEdge_type;

void EXI_Enable(EX_InterruptSource_type Interrupt);

void EXI_Disable(EX_InterruptSource_type Interrupt);

void EXI_TriggerEdge(EX_InterruptSource_type Interrupt,TriggerEdge_type Edge);

void EXI_SetCallBack(EX_InterruptSource_type Interrupt,void(*LocalPtr)(void));



#endif /* EXT_INTERRUPT_INTERFACE_H_ */
