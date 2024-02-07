/*
 * ADC_MemMap.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Youssef Samy
 */

#define ADMUX        (*((volatile unsigned char*)0x27))
#define REFS1 				7	// these 2 bits in ADMUX register are for  **** Voltage Reference Selection ****
#define REFS0 				6
#define ADLAR 				5	// when this bit is 1 --> left adjust the result



#define ADCSRA        (*((volatile unsigned char*)0x26))
#define ADPS0 0	// the following 3 bits(0,1,2) are for **** Prescaler Selection ****
#define ADPS1 1
#define ADPS2 2
#define ADIE  3  // interrupt enable
#define ADIF  4  // interrupt flag
#define ADATE 5  // auto trigger enable (Convert 1 Time Only or Morethan one time)
#define ADSC  6	 // start conversion
#define ADEN  7	 // enable


#define ADCH     (*((volatile unsigned char*)0x25))
#define ADCL     (*((volatile unsigned char*)0x24))
#define ADC		 (*((volatile unsigned short*)0X24)) //to prevent shifting when getting the 10 bits of result.


/* ADC Conversion Complete */
#define ADC_vect			   __vector_16

/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)


#  define ISR_NOBLOCK    __attribute__((interrupt))
#  define ISR_NAKED      __attribute__((naked))


#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)



