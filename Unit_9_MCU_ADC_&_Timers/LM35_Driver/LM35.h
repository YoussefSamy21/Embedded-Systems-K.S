/*
 * LM35.h
 *
 *  Created on: Feb 8, 2024
 *      Author: youssef
 */

#ifndef LM35_H_
#define LM35_H_

#include "MCAL/ATMega32_ADC_Driver/ADC_interface.h"

/*
 LM35_Vref:
 1- VREF_AVCC
 2- VREF_AREF
 3- VREF_256
*/
#define LM35_Vref VREF_AVCC

#define LM35_CH	CH_0
// LM35_CH: CH_0 , CH_1 , CH_2 , CH_3 , CH_3 , CH_4 , CH_5 , CH_6 , CH_7

#define LM35_Scalar ADC_SCALER_8


void LM35_INIT();
uint16 LM35_GetTemp();



#endif /* LM35_H_ */
