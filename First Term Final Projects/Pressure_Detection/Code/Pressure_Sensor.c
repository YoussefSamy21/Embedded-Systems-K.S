/*
    Eng.Youssef Mohamed Samy
*/

#include "Pressure_Sensor.h"

static uint32_t P_Val = 0;
static PS_States PS_State_ID;


STATE_define(PS_BUSY)
{
    PS_State_ID = PS_BUSY;
    // P_Val = PS_Get_Pressure_Random(15,25,1); // for testing

    // printf ("PS_BUSY state : Pressure= %d\n" ,P_Val);
    
    P_Val = GPIO_Get_Pressure_Value();


	Set_Pressure_Val(P_Val);
    ptr_PS_State = STATE(PS_BUSY);


}


void PS_Init()
{
	//Init Pressure Sensor Driver
	// printf ("\n\n===========> Pressure Sensor Driver Initialization <===========\n"); for testing
}

/************************************************************************************/
/*
 // this function was created for testing , through terminal ,  by printing the random numbers for the Pressure sensor
uint32_t PS_Get_Pressure_Random(uint32_t l, uint32_t r, uint32_t count)
{
	// This will generate random number in range l and r 
	uint32_t i, rand_num;
	for(i = 0; i < count; i++)
    {
		rand_num = (rand() % (r - l + 1)) + l;
	}
	
    return rand_num;
}
*/