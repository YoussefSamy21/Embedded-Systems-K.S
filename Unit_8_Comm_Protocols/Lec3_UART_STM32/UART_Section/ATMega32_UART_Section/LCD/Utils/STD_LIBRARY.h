/*
 * std_library.h
 *
 *  Created on: Sep 16, 2022
 *      Author: youssef
 */

#ifndef STD_LIBRARY_H_
#define STD_LIBRARY_H_

#define SET_BIT(VAR,BIT)    (VAR |=(0x01<<BIT))
#define CLEAR_BIT(VAR,BIT)    (VAR &= (~(0x01<<BIT)))
#define GET_BIT(VAR,BIT)    ((VAR>>BIT) & 0x01)
#define TOG_BIT(VAR,BIT)    (VAR ^=(0x01<<BIT))
#define IS_BIT_SET(VAR,BIT)  (GET_BIT(VAR,BIT))
#define IS_BIT_CLR(VAR,BIT)  (!GET_BIT(VAR,BIT))


#endif /* STD_LIBRARY_H_ */
