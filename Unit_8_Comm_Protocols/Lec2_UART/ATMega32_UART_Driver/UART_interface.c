/*
 * UART_interface.c
 *
 *  Created on: Dec 15, 2023
 *      Author: youssef
 */


#include "UART_interface.h"

// Pointers used in Call Back functions
static void (*UART_Tx_Fptr)(void);
static void (*UART_Rx_Fptr)(void);


/********* Initialization ***********/

// Array of  UBRR values
const uint16 BaudRateArray[TOTAL_SPEED_MODE][TOTAL_CPU_F][TOTAL_BAUD_RATE] =
	 {     { {103, 51, 25, 16, 12,  8} , {207,103, 51, 34, 25, 16} , {416,207,103, 68 ,51, 34} } ,
	       { {207,103, 51, 34, 25, 16} , {416,207,103, 68 ,51, 34} , {832,416,207,138,103, 68} } };

void UART_Init(void)
{
	uint8  UCSRC_var=0;
	uint16 UBRR_var=0;
	/***************************** Transmission Speed***************************/
	#if (SPEED_MODE == NORMAL_SPEED)
	CLEAR_BIT(UCSRA,U2X);
	#elif (SPEED_MODE == DOUBLE_SPEED)
	SET_BIT(UCSRA,U2X);
	#endif

	//******************set URSEL to write data to UCSRC register***************/
	SET_BIT(UCSRC_var,URSEL);

	//********************************Synch/Asynch ***********************************/
	 #if (SYNCH_MODE == SYNCH)
	 SET_BIT(UCSRC_var,UMSEL)
	 #elif (SYNCH_MODE == ASYNCH)
	 CLEAR_BIT(UCSRC_var,UMSEL);
	 #endif

	 //***************************** Parity Mode *******************************/
	#if (PARITY_MODE == NO_PARITY)
	CLEAR_BIT(UCSRC_var,UPM0);
	CLEAR_BIT(UCSRC_var,UPM1);
	#elif (PARITY_MODE==EVEN_PARITY)
	CLEAR_BIT(UCSRC_var,UPM0);
	SET_BIT(UCSRC_var,UPM1);
	#elif (PARITY_MODE == ODD_PARITY)
	SET_BIT(UCSRC_var,UPM0);
	SET_BIT(UCSRC_var,UPM1);
	#endif

	//************************Data bits(5-9) *******************************/
	#if (N_DATA_BITS==_5_DATA_BITS)
	CLEAR_BIT(UCSRC_var,UCSZ0);
	CLEAR_BIT(UCSRC_var,UCSZ1);
	CLEAR_BIT(UCSRC_var,UCSZ2);
	#elif (N_DATA_BITS==_6_DATA_BITS)
	SET_BIT(UCSRC_var,UCSZ0);
	CLEAR_BIT(UCSRC_var,UCSZ1);
	CLEAR_BIT(UCSRC_var,UCSZ2);
	#elif (N_DATA_BITS==_7_DATA_BITS)
	CLEAR_BIT(UCSRC_var,UCSZ0);
	SET_BIT(UCSRC_var,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);
	#elif (N_DATA_BITS==_8_DATA_BITS)
	SET_BIT(UCSRC_var,UCSZ0);
	SET_BIT(UCSRC_var,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);
	#elif (N_DATA_BITS==_9_DATA_BITS)
	SET_BIT(UCSRC_var,UCSZ0);
	SET_BIT(UCSRC_var,UCSZ1);
	SET_BIT(UCSRB,UCSZ2);
	#endif

	//************************Stop bits*******************************/
	#if (N_STOP_BITS==ONE_STOP_BIT)
	CLEAR_BIT(UCSRC_var,USBS);
	#elif (N_STOP_BITS==TWO_STOP_BIT)
	SET_BIT(UCSRC_var,USBS);
	#endif

	//*****************set UCSRC value   *******************************/
	UCSRC=UCSRC_var;

	//************************Baud rate *******************************/
	UBRR_var=BaudRateArray[SPEED_MODE][CPU_F][BAUD_RATE];
	UBRRH = (uint8)(UBRR_var>>8);
	UBRRL = (uint8)UBRR_var;

	//************************ Enable Tx/Rx *******************************/
	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);
	//enable UART  transmitter .
	SET_BIT(UCSRB,TXEN);
}


/******* Polling Mechanism *******/
void UART_Send_Byte(uint8 data)
{
	while(!(GET_BIT(UCSRA,UDRE)));
	UDR = data;
}

uint8 UART_Receive_Byte(void)
{
	while(!(GET_BIT(UCSRA,RXC)));
	return UDR;
}


/******* Periodic Check (No Block) *******/
// the aim of these functions to not block or delaying the main function
uint8 UART_Send_Byte_NoBlock(uint8 *pdata)
{
	uint8 status;
	if(GET_BIT(UCSRA,UDRE))
	{
		UDR = *pdata;
		status = 1;
	}
	else
	{
		status = 0;
	}

	return status;
}

uint8 UART_Receive_Byte_NoBlock(uint8 *pdata)
{
	uint8 status;
	if(GET_BIT(UCSRA,RXC))
	{
		*pdata = UDR;
		status = 1;
	}
	else
	{
		status = 0;
	}

	return status;
}

/******* CallBack Functions *******/
void UART_Tx_Set_CallBack(void (*LocalFptr)(void))
{
	UART_Tx_Fptr = LocalFptr;
}
void UART_Rx_Set_CallBack(void (*LocalFptr)(void))
{
	UART_Rx_Fptr = LocalFptr;
}

ISR(USART_TXC_vect)
{
	if(UART_Tx_Fptr != NULLPTR)
	{
		UART_Tx_Fptr();
	}
}
ISR(USART_RXC_vect)
{
	if(UART_Rx_Fptr != NULLPTR)
	{
		UART_Rx_Fptr();
	}
}



/******* Tx/Rx Interrupt Enable *******/
void UART_Tx_Interrupt_Enable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_Rx_Interrupt_Enable(void)
{
	SET_BIT(UCSRB,RXCIE);
}


/******* Tx/Rx Interrupt Disable *******/
void UART_Tx_Interrupt_Disable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}
void UART_Rx_Interrupt_Disable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}


void UART_Send_Byte_inISR(uint8 data)
{
	UDR = data;
}

uint8 UART_Receive_Byte_inISR(void)
{
	return UDR;
}



/*******************************************************************************************************************************/
/********* String APIs *********/

static uint8 *Asynch_Send_pStr;
static uint8 *Asynch_Receive_pStr;


//===============================================================================================

void UART_Send_String(uint8 *pStr) // Polling Mechanism
{
	uint8 i = 0;
	while(pStr[i] != '\0')
	{
		UART_Send_Byte(pStr[i]);
		i++;
	}
}

//===============================================================================================

static void Func_Tx_Asynch(void) // the function which will run in the ISR (Asynch Mode) (Background) , to send the rest of string
{
	static uint8 i = 1;
	if(Asynch_Send_pStr[i] != '\0')
	{
		UART_Send_Byte_inISR(Asynch_Send_pStr[i]);
		i++;
	}
	else
	{
		i = 1; // to be able to send string again
		UART_Tx_Interrupt_Disable();
	}
}
void UART_Send_String_Asynch(uint8 *pStr)
{
	UART_Send_Byte(pStr[0]);
	UART_Tx_Interrupt_Enable();
	UART_Tx_Set_CallBack(Func_Tx_Asynch);

	Asynch_Send_pStr = pStr;
	// the Asynch_Send_pStr will send the rest of string in the Background (using interrupt) without delaying the main
}

//===============================================================================================


void UART_Receive_String(uint8 *pStr) // Polling Mechanism (Receive until the Default_Stop Macro)
{
	uint8 i = 0;
	pStr[i] = UART_Receive_Byte();
	while(pStr[i] != Default_Stop)
	{
		i++;
		pStr[i] = UART_Receive_Byte();
	}
	pStr[i] = '\0';
}

//===============================================================================================

volatile uint8 Default_Stop_Flag = 0; // this Flag can be accessed by the User by the Getter Function

uint8 UART_GET_Def_Stop_Flag(void) // Getter Function returns the Def_Stop_Flag (Used in the Asynch Receiving_String_API)
{
	return Default_Stop_Flag;
}

// this function which will run in the ISR (Asynch Mode) (Background),to Receive String until Default Stop Macro
static void Func_Rx_Asynch(void)
{
	static uint8 i = 0;
	Asynch_Receive_pStr[i] = UART_Receive_Byte_inISR();
	if(Asynch_Receive_pStr[i] == Default_Stop)
	{
		Default_Stop_Flag = 1;
	}
	i++;
}

void UART_Receive_String_Asynch(uint8 *pStr) // Receive until the Default_Stop Macro
{
	Asynch_Receive_pStr = pStr;
	UART_Rx_Interrupt_Enable();
	UART_Rx_Set_CallBack(Func_Rx_Asynch);
}









