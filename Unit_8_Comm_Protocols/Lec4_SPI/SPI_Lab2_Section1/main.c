/*
 * main.c
 *
 *  Created on: Dec 18, 2023
 *  Author: Youssef Samy
 */


/*********** 7 Segment =====> Master Code ***********/


#include "ATMega32_SPI_Driver/SPI_interface.h"
#include <util/delay.h>

void Send(uint8 command, uint8 data)
{
	DIO_uint8SetValuePIN(PORT_B , PIN_4 , PIN_LOW);
	SPI_SendReceive(command); // Send Command
	SPI_SendReceive(data); // Send Data
	DIO_uint8SetValuePIN(PORT_B , PIN_4 , PIN_HIGH);
}
void main()
{
	SPI_InitMaster();

	Send(0x09, 0xFF);  // Decode all display
	Send(0x0B, 0x07);  // Scan limit Display digits from 0 to 7
	Send(0x0A, 0x0F); // Intensity
	Send(0x0C, 0x01); // Turn on display

	uint8 i , count = 0;
	while(1)
	{
		for(i = 0 ; i<9 ; i++)
		{
			Send(i,count);
			count++;
		}
		_delay_ms(700);
	}

}


