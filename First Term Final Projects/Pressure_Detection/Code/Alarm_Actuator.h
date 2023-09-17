/*
    Eng.Youssef Mohamed Samy
*/

#ifndef Alarm_Actuator_H_
#define Alarm_Actuator_H_

#include "State.h"
#include "GPIO.h"
#include "Platform_Types.h"
// #include <stdio.h> for testing

void (*ptr_Alarm_Actuator_State)();

// Alarm Actuator init Function
void Alarm_Actuator_Init();

// States definition for Alarm Actuator
typedef enum 
{
    Alarm_Actuator_IDLE,
	Alarm_Actuator_BUSY
}Alarm_Actuator_States;

STATE_define(Alarm_Actuator_IDLE);
STATE_define(Alarm_Actuator_BUSY);

void Alarm_State_Set(uint32_t state);

#endif /* Alarm_Actuator_H_ */