#ifndef STATE_H_
#define STATE_H_

/* Automatic state function generated */
#define STATE_define(_stateFun_) void ST_##_stateFun_()
#define STATE(_stateFun_) ST_##_stateFun_

/* States Connection */
void US_Get_Distance(int distance);
void DC_Motor_Set_Speed(int speed);

#endif /* STATE_H_ */