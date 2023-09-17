
/*
    Eng. Youssef Mohamed Samy
*/ 
#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

#include "State.h"


void (*ptr_MA_state)();

// States definition for Main Algorithm
typedef enum 
{
	MA_Waiting,
	MA_Detecting
}MA_States;


/* Declare State Functions of CA */
STATE_define(MA_Waiting);
STATE_define(MA_Detecting);

#endif /* MAIN_ALGORITHM_H_ */
