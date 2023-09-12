#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"
#include <stdio.h>
#include <stdlib.h>

// enum for US_sensor states
typedef enum
{
	US_busy
} US_states;

// State pointer to function
extern void (*US_state)();

void US_init();
STATE_define(US_busy);


#endif /* US_SENSOR_H_ */