#include "DC_motor.h"

static int DC_speed = 0;
static DC_states DC_state_id;

void (*DC_state)();

void DC_init()
{
	// init DC
    printf("DC Motor is Initialized \n");
}

void DC_Motor_Set_Speed(int speed)
{
	DC_speed = speed;
	DC_state = STATE(DC_busy);
	printf("CA ===> Speed = %d ===> DC\n", DC_speed);
}

STATE_define(DC_idle)
{
	/* State Name */
	DC_state_id = DC_idle;

	/* State Action */
	// Call PWM to make speed = DC_speed
	printf("DC_idle State: Speed = %d \n", DC_speed);
}

STATE_define(DC_busy)
{
	// State Action
	DC_state_id = DC_idle;

	// Call DC Driver
	DC_state = STATE(DC_idle);
	printf("DC_idle State: Speed = %d \n", DC_speed);
}