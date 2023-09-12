#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_

#include <stdio.h>
#include "state.h"

// enum for Collision Avoidance States
typedef enum
{
	CA_waiting,
	CA_driving
}CA_states;

// prototypes
STATE_define(CA_waiting);
STATE_define(CA_driving);

// global pointer to function
extern void (*CA_state)();

#endif /* COLLISION_AVOIDANCE_H_ */