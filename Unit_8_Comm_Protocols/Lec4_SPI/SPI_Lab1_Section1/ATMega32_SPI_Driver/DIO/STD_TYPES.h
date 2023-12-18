/*
 * std_types.h
 *
 *  Created on: Sep 16, 2022
 *      Author: youssef
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef     unsigned char         uint8   ;
typedef     unsigned short int    uint16  ;
typedef     unsigned int          uint32  ;

typedef     signed char           sint8   ;
typedef     signed short int      sint16  ;
typedef     signed int            sint32  ;

typedef     float            	  f32  	  ;
typedef     double            	  f64  	  ;

#define 	NULLPTR  			((void*)0)	 /*	casting 3shan msln lw size of intger 4 bytes and pointer 8 bytes aw el 3aks
											  *	yb2a ana 3mlt casting lel zero 3ala ad el pointer ...
											  *	f yb2a ma3rof en da "address zero" not "rakam zero"
 	 	 	 	 	 	 	 	 	 	 	  */


#endif /* STD_TYPES_H_ */
