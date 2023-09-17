/*
  Eng.Youssef Mohamed Samy
*/

#ifndef STATE_H_
#define STATE_H_

// MACRO for States to declare State Functions
// EX: STATE_define(BUSY); ====> void ST_BUSY();
#define STATE_define(...)    void ST_##__VA_ARGS__()

// MACRO for Calling State Functions using Pointer to Function
// EX: ptr_func = STATE(BUSY) ===> ptr_func = ST_BUSY
#define STATE(...)           ST_##__VA_ARGS__    

/************** States Signals **************/

/* Main_Algorithm --> Alarm_Monitor */
void High_Pressure_Detected(void);

/* Pressure_Sensor --> Main_Algorithm */
void Set_Pressure_Val(int p_val);


/* Alarm_Monitor --> Alarm_Actuator */
void Start_Alarm(void);

/* Alarm_Monitor --> Alarm_Actuator */
void Stop_Alarm(void);



#endif /* STATE_H_ */
