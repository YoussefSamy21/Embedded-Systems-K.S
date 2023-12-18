/*
 * SPI_MemMap.h
 *
 *  Created on: Dec 18, 2023
 *      Author: youssef
 */

#ifndef SPI_MEMMAP_H_
#define SPI_MEMMAP_H_


// SPI Data Register - SPDR
#define SPDR       (*(volatile unsigned char*)0x2F)

// SPI Status Register - SPSR
#define 	SPSR       (*(volatile unsigned char*)0x2E)
#define    	SPIF         7
#define    	WCOL         6
#define    	SPI2X        0

// SPI Control Register - SPCR
#define 	SPCR       (*(volatile unsigned char*)0x2D)
#define    	SPIE         7
#define    	SPE          6
#define    	DORD         5
#define    	MSTR         4
#define    	CPOL         3
#define    	CPHA         2
#define    	SPR1         1
#define    	SPR0         0

// Interrupt Vectors: Serial Transfer Complete
#define SPI_STC_vect			__vector_12

#define sei()  __asm__ __volatile__ ("sei" ::) // enable the Global Interrupt
#define cli()  __asm__ __volatile__ ("cli" ::)
#define reti()  __asm__ __volatile__ ("reti" ::)

#define ISR_NOBLOCK    __attribute__((interrupt))
#define ISR_NAKED      __attribute__((naked))


#define ISR(vector,...)    \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)



#endif /* SPI_MEMMAP_H_ */
