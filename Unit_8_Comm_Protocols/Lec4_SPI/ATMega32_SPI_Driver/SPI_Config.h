/*
 * SPI_Config.h
 *
 *  Created on: Dec 18, 2023
 *  Author: Youssef Samy
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/******************* SPI Configuration *******************/

#define SPI_DATA_ORDER			SPI_DATA_ORDER_MSB
#define SPI_CLOCK_PLOARITY		SPI_CPOL_LEADING_RISING
#define SPI_CLOCK_PHASE			SPI_CPHA_LEADING_SAMPLE
#define SPI_SET_DOUBLE_SPEED 	SPI_NO_DOUBLE_SPEED
#define SPI_CLK_RATE			SPI_CLK_RATE_4

/************************************************************************/

// Data order
#define SPI_DATA_ORDER_LSB			0
#define SPI_DATA_ORDER_MSB			1

// Clock Polarity
#define SPI_CPOL_LEADING_RISING		0
#define SPI_CPOL_LEADING_FALLING	1

// Clock Phase
#define SPI_CPHA_LEADING_SAMPLE		0
#define SPI_CPHA_LEADING_SETUP		1

// Double Speed
#define SPI_NO_DOUBLE_SPEED			0
#define SPI_DOUBLE_SPEED			1

// Clock Rate
#define SPI_CLK_RATE_4				0
#define SPI_CLK_RATE_16				1
#define SPI_CLK_RATE_64				2
#define SPI_CLK_RATE_128			3

#define SPI_CLK_Rate_Masking 		0xFC


#endif /* SPI_CONFIG_H_ */
