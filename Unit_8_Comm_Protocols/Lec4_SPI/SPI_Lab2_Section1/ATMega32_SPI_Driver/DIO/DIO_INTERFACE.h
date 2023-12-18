/*
 * DIO_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: youssef
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "STD_LIBRARY.h"
#include "DIO_REGISTERMAP.h"

typedef enum
{
	PORT_A=0,
	PORT_B,
	PORT_C,
	PORT_D
}PORT_NAME;


typedef enum
{	// this enum to read an input from the PIN Register
	PIN_A=0,
	PIN_B,
	PIN_C,
	PIN_D
}PIN_Reg_NAME;


typedef enum
{
	PIN_0=0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}PIN_NAME;

typedef enum
{

	PIN_INPUT=0,
	PIN_OUTPUT=1
}PIN_DIR;

typedef enum
{
	PORT_INPUT=0X00,
	PORT_OUTPUT=0XFF
}PORT_DIR;

typedef enum
{
	PIN_LOW=0,
	PIN_HIGH=1
}PIN_VALUE;

typedef enum
{
	PORT_LOW=0x00,
	PORT_HIGH=0xFF
}PORT_VALUE;

void DIO_uint8SetDirectionPIN(PORT_NAME Copy_Port,PIN_NAME Copy_Pin,PIN_DIR Copy_Dir);

void DIO_uint8SetDirectionPort(PORT_NAME Copy_Port,PORT_DIR Copy_Dir);

void DIO_uint8SetValuePIN(PORT_NAME Copy_Port,PIN_NAME Copy_Pin,PIN_VALUE Copy_Value);

void DIO_uint8SetValuePort(PORT_NAME Copy_Port,PORT_VALUE Copy_Value);

PIN_VALUE  DIO_uint8Read_PIN(PIN_Reg_NAME Copy_Port,PIN_NAME Copy_Pin);


/**********************************************************************/

void DIO_uint8Set_SpecificValue_Port(PORT_NAME Copy_Port,uint8 Copy_Value);

void DIO_uint8Set_SpecificValue_Port_Direction(PORT_NAME Copy_Port,uint8 Copy_Dir);

/**********************************************************************/

#endif /* DIO_INTERFACE_H_ */
