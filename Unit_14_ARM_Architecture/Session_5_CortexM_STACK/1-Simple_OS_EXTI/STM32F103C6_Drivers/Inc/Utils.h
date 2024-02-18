/*
 * Utils.h
 *
 *  Created on: Dec 5, 2023
 *      Author: youssef
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(VAR,BIT)    (VAR |=(0x01<<BIT))
#define CLEAR_BIT(VAR,BIT)    (VAR &= (~(0x01<<BIT)))
#define GET_BIT(VAR,BIT)    ((VAR>>BIT) & 0x01)
#define TOG_BIT(VAR,BIT)    (VAR ^=(0x01<<BIT))
#define IS_BIT_SET(VAR,BIT)  (GET_BIT(VAR,BIT))
#define IS_BIT_CLR(VAR,BIT)  (!GET_BIT(VAR,BIT))

#endif /* UTILS_H_ */
