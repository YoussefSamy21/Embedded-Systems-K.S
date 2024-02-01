/*
 * I2C_Config.h
 *
 *  Created on: Jan 27, 2024
 *      Author: youssef
 */

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

#include "I2C_MemMap.h"


/* Frequency of CPU */
#define F_CPU 8000000UL

/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
#define SCL_Clock  400000UL

/*
 * Prescaler Options:
	1-PRESCALLER_BY_1
	2-PRESCALLER_BY_4
	3-PRESCALLER_BY_16
	4-PRESCALLER_BY_64
 */
#define TWI_PRESCALLER  PRESCALLER_BY_1

#endif /* I2C_CONFIG_H_ */
