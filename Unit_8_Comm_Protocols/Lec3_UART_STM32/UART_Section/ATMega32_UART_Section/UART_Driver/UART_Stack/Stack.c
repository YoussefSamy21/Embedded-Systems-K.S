/*
 * Stack.c
 *
 *  Created on: Dec 16, 2023
 *      Author: youssef
 */

#include "Stack.h"

static uint8 STACK[STACK_SIZE];
static uint8 SP = 0;


Stack_Status PUSH(uint8 data)
{
	Stack_Status status;
	if(SP < STACK_SIZE)
	{
		STACK[SP] = data;
		SP++;
		status = DONE;
	}
	else
	{
		status = STACK_FULL;
	}

	return status;
}


Stack_Status POP(uint8 *pdata)
{
	Stack_Status status;
	if(SP == 0)
	{
		status = STACK_EMPTY;
	}
	else
	{
		SP--;
		*pdata = STACK[SP];
		status = DONE;
	}

	return status;
}
