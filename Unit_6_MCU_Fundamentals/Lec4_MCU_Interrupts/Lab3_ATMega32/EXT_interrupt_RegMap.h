/*
 * int_register_map.h
 *
 *  Created on: Oct 1, 2022
 *      Author: youssef
 */

#ifndef EXT_INTERRUPT_REGMAP_H_
#define EXT_INTERRUPT_REGMAP_H_

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

// __attribute__ ((signal)) is  to make context switching


#define sei()  __asm__ __volatile__ ("sei" ::)	/*
 	 	 	 	 	 	 	 	 	 	 	 	 * this is to write an assembly instruction
 	 	 	 	 	 	 	 	 	 	 	 	 * "sei" ---> is an assembly instruction to enable the global interrupt
 	 	 	 	 	 	 	 	 	 	 	 	 */
# define cli()  __asm__ __volatile__ ("cli" ::) // disbale global interrupt

#define SREG        (*((volatile uint8*)0X5F))

#define GICR        (*((volatile uint8*)0X5B))
#define INT1 7
#define INT0 6
#define INT2 5


#define MCUCR        (*((volatile uint8*)0X55))
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3


#define MCUCSR        (*((volatile uint8*)0X54))
#define ISC2 6


#define GIFR        (*((volatile uint8*)0X5A))
#define INTF1 7
#define INTF0 6
#define INTF2 5


#endif /* EXT_INTERRUPT_REGMAP_H_ */
