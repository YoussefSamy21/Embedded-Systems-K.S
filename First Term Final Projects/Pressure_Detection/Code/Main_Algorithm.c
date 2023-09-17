/*
    Eng.Youssef Mohamed Samy
*/

#include "Main_Algorithm.h"
#include "Alarm_Actuator.h"
#include "Platform_Types.h"

static uint32_t     P_Val = 0;
static uint32_t     Alarm_State = 0;
static uint32_t     P_threeshold = 20;
static MA_States MA_State_ID;

STATE_define(MA_Waiting)
{
	MA_State_ID = MA_Waiting;

	// printf ("MA_Waiting state : Pressure=%d\n" ,P_Val); // for testing

	Alarm_State = 0; //State_Action

	Alarm_State_Set(Alarm_State);


}
STATE_define(MA_Detecting)
{
	MA_State_ID = MA_Detecting;
	// printf ("MA_Waiting state : Pressure=%d\n" ,P_Val); // for testing

	Alarm_State = 1; //State_Action
	
	Alarm_State_Set(Alarm_State);

}

void Set_Pressure_Val(int p_val)
{
	P_Val = p_val;

	( P_Val <= P_threeshold ) ? (ptr_MA_state = STATE(MA_Waiting)) : (ptr_MA_state = STATE(MA_Detecting));

	// printf ("Pressure Sensor ========> Pressure=%d ========> Main Algorithm\n\n\n" ,P_Val);   // for testing

}

