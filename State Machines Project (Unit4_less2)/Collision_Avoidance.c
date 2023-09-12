#include "Collision_Avoidance.h"

#define STOP_SPEED	0
#define MOVE_SPEED	30

static CA_states CA_state_id;
static int CA_distance = 0;
static int CA_speed = 0;
static int CA_threshold = 50;

void (*CA_state)();

void US_Get_Distance(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US ===> Distance = %d ===> CA\n", CA_distance);
}

STATE_define(CA_waiting)
{

	/* State Name */
	CA_state_id = CA_waiting;
	printf("CA_Waiting State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);

	/* State Action */
	CA_speed = STOP_SPEED;
	DC_Motor_Set_Speed(CA_speed);

	/* Event Check */
}

STATE_define(CA_driving)
{
	CA_state_id = CA_driving;
	printf("CA_Driving State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);

	CA_speed = MOVE_SPEED;
	DC_Motor_Set_Speed(CA_speed);

	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_Driving State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);
}