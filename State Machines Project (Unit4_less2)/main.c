#include "DC_motor.h"
#include "US_Sensor.h"
#include "Collision_Avoidance.h"


void setup()
{
	// Init drivers
	// Init IRQ
	// Init Hardware Abstraction Layer (HAL) ==> US_Driver , DC_Driver
	DC_init();
	US_init();

	// Init Block
	// Set pointers to the states for each block
	CA_state = STATE(CA_waiting);
	DC_state = STATE(DC_idle);
	US_state = STATE(US_busy);
}

int main()
{
	setup();
	while(1)
    {
		// Call state for each block
		CA_state();
		US_state();
		DC_state();
	}
	return 0;
}