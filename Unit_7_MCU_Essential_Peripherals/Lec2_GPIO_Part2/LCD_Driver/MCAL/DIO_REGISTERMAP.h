/*
 * DIO_RegisterMap.h
 *
 *  Created on: Sep 16, 2022
 *      Author: youssef
 */

#ifndef DIO_REGISTERMAP_H_
#define DIO_REGISTERMAP_H_



#define DDRA        (*((volatile uint8*)0X3A))
#define DDRB        (*((volatile uint8*)0X37))
#define DDRC        (*((volatile uint8*)0X34))
#define DDRD        (*((volatile uint8*)0X31))

#define PORTA       (*((volatile uint8*)0X3B))
#define PORTB       (*((volatile uint8*)0X38))
#define PORTC       (*((volatile uint8*)0X35))
#define PORTD 		(*((volatile uint8*)0X32))

#define PINA        (*((volatile uint8*)0X39))
#define PINB        (*((volatile uint8*)0X36))
#define PINC        (*((volatile uint8*)0X33))
#define PIND 		(*((volatile uint8*)0X30))


#endif /* DIO_REGISTERMAP_H_ */
