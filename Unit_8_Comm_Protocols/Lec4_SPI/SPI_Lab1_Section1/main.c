/*
 * main.c
 *
 *  Created on: Dec 18, 2023
 *  Author: Youssef Samy
 */


/*********** 7 Segment =====> Master Code ***********/


#include "ATMega32_SPI_Driver/SPI_interface.h"
#include <util/delay.h>

void main()
{
	uint8 data;
	SPI_InitMaster();
	DIO_uint8SetDirectionPort(PORT_A , PORT_OUTPUT);
	for(data = 0 ; data<255 ; data++)
	{
		_delay_ms(700);
		DIO_uint8Set_SpecificValue_Port(PORT_A , SPI_SendReceive(data));
	}
	while(1)
	{

	}

}


/*********** 7 Segment =====> Slave Code ***********/

/*
#include "ATMega32_SPI_Driver/SPI_interface.h"
#include <util/delay.h>

void main()
{
	uint8 data;
	SPI_InitSlave();
	DIO_uint8SetDirectionPort(PORT_A , PORT_OUTPUT);
	for(data = 255 ; data >= 0 ; data--)
	{
		_delay_ms(700);
		DIO_uint8Set_SpecificValue_Port(PORT_A , SPI_SendReceive(data));
	}
	while(1)
	{

	}
}

*/

