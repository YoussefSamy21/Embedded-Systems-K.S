/*
    Eng.Youssef Mohamed Samy
*/

// #include <stdio.h> // for testing

#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "GPIO.h"

#include "State.h"
#include "Pressure_Sensor.h"
#include "Alarm_Actuator.h"
#include "Main_Algorithm.h"

void setup()
{
	//Init all the drivers
	//Init IRQ ...
	//Init HAL 
	
    GPIO_Init();
	
    //init Block
	PS_Init();
	Alarm_Actuator_Init();

	// Set pointers to the states for each block
	ptr_MA_state = STATE(MA_Waiting);
	ptr_PS_State = STATE(PS_BUSY);
	ptr_Alarm_Actuator_State = STATE(Alarm_Actuator_IDLE);
}

void main(void)
{
	
    volatile uint32_t delay ;
	setup();    
	while (1)
	{
        // Calling State for Each Block by Pointer to Function
		ptr_PS_State();
		ptr_MA_state();
		ptr_Alarm_Actuator_State();
		for (delay=0 ; delay<=1000 ; delay++);
	}
    
}


