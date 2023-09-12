#include "US_Sensor.h"

static int US_distance = 0;
static US_states US_state_id;


void (*US_state)();

static int US_Get_Distance_random(int l, int r, int count)
{
	/* This will generate random number in range l and r */
	int i, rand_num;
	for(i = 0; i < count; i++)
    {
		rand_num = (rand() % (r - l + 1)) + l;
	}
	
    return rand_num;
}

void US_init()
{
	/* Init Ultrasonic Driver */
	printf("US Sensor Initialized\n");
}

STATE_define(US_busy)
{
	/* State Name */
	US_state_id = US_busy;

	// Read from the Ultrasonic
	US_distance = US_Get_Distance_random(45, 55, 1);
	printf("US_busy State: distance = %d \n", US_distance);
	US_Get_Distance(US_distance);
	US_state = STATE(US_busy);
}