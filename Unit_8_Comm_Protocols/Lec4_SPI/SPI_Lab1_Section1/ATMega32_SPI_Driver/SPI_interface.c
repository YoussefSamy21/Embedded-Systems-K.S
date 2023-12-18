/*
 * SPI_interface.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Youssef Samy
 */

#include "SPI_interface.h"

// Pointer used in Call Back function
static void (*SPI_Fptr)(void);


void SPI_InitMaster(void)
{
	// Data Order
	#if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB
		SET_BIT(SPCR, DORD);
	#elif SPI_DATA_ORDER == SPI_DATA_ORDER_MSB
		CLEAR_BIT(SPCR, DORD);
	#endif

	// Set Clock polarity
	#if SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_RISING
		CLEAR_BIT(SPCR, CPOL);
	#elif SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_FALLING
		SET_BIT(SPCR, CPOL);
	#endif

	// Set Clock phase
	#if SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SAMPLE
		CLEAR_BIT(SPCR, CPHA);
	#elif SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SETUP
		SET_BIT(SPCR, CPHA);
	#endif

	// Double SPI Speed Bit
	#if SPI_SET_DOUBLE_SPEED == SPI_NO_DOUBLE_SPEED
		CLEAR_BIT(SPSR, SPI2X);
	#elif SPI_SET_DOUBLE_SPEED == SPI_DOUBLE_SPEED
		SET_BIT(SPSR, SPI2X);
	#endif

	// SPI Clock Rate
	SPCR &= SPI_CLK_Rate_Masking;
	SPCR |= SPI_CLK_RATE;

	// Select SPI Master Mode
	SET_BIT(SPCR, MSTR);

	// SPI Enable
	SET_BIT(SPCR, SPE);

	/****** Configuring SPI Master Pins (SS , MOSI , MISO , SClck) (PORT=> B , PINS (4,5,6,7)) ******/
	DIO_uint8SetDirectionPIN(PORT_B, PIN_4 , PIN_OUTPUT);     // SS Pin  : Output
	DIO_uint8SetDirectionPIN(PORT_B, PIN_5 , PIN_OUTPUT);   // MOSI Pin : Output
	DIO_uint8SetDirectionPIN(PORT_B, PIN_6 , PIN_INPUT);   // MISO Pin  : Input
	DIO_uint8SetDirectionPIN(PORT_B, PIN_7 , PIN_OUTPUT); // Sclck Pin  : Output
}


void SPI_InitSlave(void)
{
	// Set data order
	#if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB
		SET_BIT(SPCR, DORD);
	#elif SPI_DATA_ORDER == SPI_DATA_ORDER_MSB
		CLEAR_BIT(SPCR, DORD);
	#endif

	// Set Clock polarity
	#if SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_RISING
		CLEAR_BIT(SPCR, CPOL);
	#elif SPI_CLOCK_PLOARITY == SPI_CPOL_LEADING_FALLING
		SET_BIT(SPCR, CPOL);
	#endif

	// Set Clock phase
	#if SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SAMPLE
		CLEAR_BIT(SPCR, CPHA);
	#elif SPI_CLOCK_PHASE == SPI_CPHA_LEADING_SETUP
		SET_BIT(SPCR, CPHA);
	#endif

	// select SPI Slave mode
	CLEAR_BIT(SPCR, MSTR);

	// SPI Enable
	SET_BIT(SPCR, SPE);

	/****** Configuring SPI Slave Pins (MOSI , MISO , SS , SClck) (PORT=> B , PINS (4,5,6,7)) ******/
	DIO_uint8SetDirectionPIN(PORT_B, PIN_4 , PIN_INPUT);      // SS Pin   : Input
	DIO_uint8SetDirectionPIN(PORT_B, PIN_5 , PIN_INPUT);     // MOSI Pin  : Input
	DIO_uint8SetDirectionPIN(PORT_B, PIN_6 , PIN_OUTPUT);   // MISO Pin   : Output
	DIO_uint8SetDirectionPIN(PORT_B, PIN_7 , PIN_INPUT);   // Sclck Pin   : Input
}


uint8 SPI_SendReceive(uint8 data)
{
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}

uint8 SPI_Recieve_PeriodicCheck(uint8 *ptr_data)
{
	if(GET_BIT(SPSR,SPIF))
	{
		*ptr_data = SPDR;
		return 1;
	}
	else
	{
		return 0;
	}
}

void SPI_Send_NoBlock(uint8 data)
{
	SPDR = data;
}


uint8 SPI_Receive_NoBlock(void)
{
	return SPDR;
}

void SPI_Interrupt_Enable(void)
{
	SET_BIT(SPCR, SPIE);
}

void SPI_Interrupt_Disable(void)
{
	CLEAR_BIT(SPCR, SPIE);
}

void SPI_Set_CallBack(void (*LocalFptr)(void))
{
	SPI_Fptr = LocalFptr;
}

ISR(SPI_STC_vect)
{
	if(SPI_Fptr != NULLPTR)
	{
		SPI_Fptr();
	}
}





