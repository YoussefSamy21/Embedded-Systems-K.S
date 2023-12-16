/*
 * Stack.h
 *
 *  Created on: Dec 16, 2023
 *      Author: youssef
 */

#ifndef STACK_H_
#define STACK_H_


#include "../Utils/STD_TYPES.h"


#define STACK_SIZE	10

typedef enum
{
	STACK_EMPTY,
	STACK_FULL,
	DONE

}Stack_Status;

Stack_Status PUSH(uint8 data);
Stack_Status POP(uint8 *pdata);

#endif /* STACK_H_ */
