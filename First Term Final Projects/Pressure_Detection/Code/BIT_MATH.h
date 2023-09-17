
/*
    Eng. Youssef Mohamed Samy
*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT)            REG |=  (1<<BIT)
#define CLEAR_BIT(REG,BIT)          REG &= ~(1<<BIT)
#define TOGGLE_BIT(REG,BIT)         REG ^=  (1<<BIT)
#define GET_BIT(REG,BIT)            ((REG) & (1<<(BIT)))
#define IS_BIT_SET(REG,BIT)         GET_BIT(REG,BIT)
#define IS_BIT_CLEAR(REG,BIT)       !(GET_BIT(REG,BIT))     



#endif /* BIT_MATH_H_ */