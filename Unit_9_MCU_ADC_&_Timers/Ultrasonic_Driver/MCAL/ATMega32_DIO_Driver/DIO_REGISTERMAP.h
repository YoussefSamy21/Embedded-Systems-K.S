/*
 * DIO_RegisterMap.h
 *
 *  Created on: Sep 16, 2022
 *      Author: youssef
 */

#ifndef DIO_REGISTERMAP_H_
#define DIO_REGISTERMAP_H_



#define DDRA        (*((volatile unsigned char*)0X3A))
#define DDRB        (*((volatile unsigned char*)0X37))
#define DDRC        (*((volatile unsigned char*)0X34))
#define DDRD        (*((volatile unsigned char*)0X31))

#define PORTA       (*((volatile unsigned char*)0X3B))
#define PORTB       (*((volatile unsigned char*)0X38))
#define PORTC       (*((volatile unsigned char*)0X35))
#define PORTD 		(*((volatile unsigned char*)0X32))

#define PINA        (*((volatile unsigned char*)0X39))
#define PINB        (*((volatile unsigned char*)0X36))
#define PINC        (*((volatile unsigned char*)0X33))
#define PIND 		(*((volatile unsigned char*)0X30))


#endif /* DIO_REGISTERMAP_H_ */
