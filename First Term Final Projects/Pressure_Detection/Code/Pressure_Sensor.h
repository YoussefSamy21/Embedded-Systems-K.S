/*
    Eng.Youssef Mohamed Samy
*/
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "State.h"
#include "GPIO.h"
#include "Platform_Types.h"
// #include <stdio.h>   for testing by printf through terminal 
// #include <stdlib.h>

void (*ptr_PS_State)();

// Pressure Sensor init Function
void PS_Init();

// States definition for Pressure Sensor (PS)
typedef enum 
{
    PS_BUSY
}PS_States;

STATE_define(PS_BUSY);

// uint32_t PS_Get_Pressure_Random(uint32_t l, uint32_t r, uint32_t count); // for testing

#endif /* PRESSURE_SENSOR_H_ */