/*
    Eng.Youssef Mohamed Samy
*/

#include "Alarm_Actuator.h"

static uint32_t Alarm_State = 0;
static Alarm_Actuator_States Alarm_Actuator_State_ID;

STATE_define(Alarm_Actuator_IDLE)
{
    // State_Name
	Alarm_Actuator_State_ID = Alarm_Actuator_IDLE;

    ptr_Alarm_Actuator_State = STATE(Alarm_Actuator_IDLE);

	// printf ("Alarm Actuator IDLE State : State=%d \n\n\n",Alarm_State ); // for testing
}


STATE_define(Alarm_Actuator_BUSY)
{
    // State_Name
	Alarm_Actuator_State_ID = Alarm_Actuator_BUSY;


	ptr_Alarm_Actuator_State = STATE(Alarm_Actuator_BUSY);

	// printf ("Alarm Actuator BUSY State : State=%d \n\n\n",Alarm_State);    // for testing

}


void Alarm_Actuator_Init()
{
    //Init Alarm Actuator Driver
	// printf ("===========> Alarm Actuator Driver Initialization <===========\n\n\n");  // for testing
}

void Alarm_State_Set(uint32_t state)
{
    Alarm_State = state ;
	ptr_Alarm_Actuator_State = STATE(Alarm_Actuator_BUSY);
	
	if (Alarm_State == 1)
	{
		GPIO_Start_Alarm_Actuator();
	}
	else if (Alarm_State == 0)
	{
		GPIO_Stop_Alarm_Actuator();
	} 
	// printf ("Main Algorithm ==========> State=%d ==========> Alarm_Actuator\n\n\n" ,Alarm_State); // for testing
}