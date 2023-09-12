#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include <stdio.h>
#include "state.h"

// enum for DC_motor states
typedef enum
{
	DC_idle,
	DC_busy
} DC_states;

/* State pointer to function */
extern void (*DC_state)();

/* Declare states functions */
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

#endif /* DC_MOTOR_H_ */