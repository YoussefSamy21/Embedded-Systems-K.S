/*
 * Ultrasonic.c
 *
 *  Created on: Feb 7, 2024
 *      Author: youssef
 */

#include "Ultrasonic.h"


static volatile uint16 t1,t2,flag=0,c=0;

void ULTRASONIC_Init(void)
{
	/****you can use timer in another mode except modes using ICR as top but take care do not reset timer****/
	//Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_NON_INVERTING);
	//OCR1A = 20000;
	Timer1_OVF_SetCallBack(Func_OVF);
	Timer1_ICU_SetCallBack(Func_ICU);

}

uint8 ULTRASONIC_GetDistance(PORT_NAME ultrasonic_port , PIN_NAME ultrasonic_pin)
{
	uint8 distance;
	uint16 time;
	//TCNT1=0;	// do not reset timer to not affect the Servo motor
	c=0;
	flag=0;


	DIO_uint8SetValuePIN(ultrasonic_port , ultrasonic_pin , PIN_HIGH);
	_delay_us(10);
	DIO_uint8SetValuePIN(ultrasonic_port , ultrasonic_pin , PIN_LOW);

	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();

	Timer1_OVF_InterruptEnable();

	while (flag<2);
	time=t2-t1+((uint32)c*20000); // not 65535 because we use OCR1A = 20000 as top , so timer OVF when reaches 20000
	distance=time/58;

	return distance;

}
void ULTRASONIC_Start(PORT_NAME ultrasonic_port , PIN_NAME ultrasonic_pin)
{
		if(flag==0)
		{
			DIO_uint8SetValuePIN(ultrasonic_port , ultrasonic_pin , PIN_HIGH);
			_delay_us(10);
			DIO_uint8SetValuePIN(ultrasonic_port , ultrasonic_pin , PIN_LOW);
			Timer1_InputCaptureEdge(RISING);
			Timer1_ICU_InterruptEnable();
			Timer1_OVF_InterruptEnable();
		}

}
uint8 ULTRASONIC_GetDistanceNoBlock(uint8 *Pdistance)
{
	uint8 distance;
	uint16 time;
	if (flag==2)
	{
		time=t2-t1+((uint32)c*65535);
		distance=time/58;
		*Pdistance=distance;
		Timer1_OVF_InterruptEnable();
		flag=0;
		return 1;
	}
	return 0;
}
uint8 ULTRASONIC_GetDistance2(PORT_NAME ultrasonic_port , PIN_NAME ultrasonic_pin)
{
	uint8 distance;
	uint16 time;
	DIO_uint8SetValuePIN(ultrasonic_port , ultrasonic_pin , PIN_HIGH);
	_delay_us(10);
	DIO_uint8SetValuePIN(ultrasonic_port , ultrasonic_pin , PIN_LOW);

	while (!DIO_uint8Read_PIN(PORT_D,PIN_6));
	TCNT1=0;
	while (DIO_uint8Read_PIN(PORT_D,PIN_6));
	time=TCNT1;
	distance=time/58;
	return distance;

}

static void Func_ICU(void)
{
	if(flag==0)
	{
		c=0;
		t1=ICR1;
		flag=1;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if (flag==1)
	{
		t2=ICR1;
		flag=2;
		Timer1_InputCaptureEdge(RISING);
		Timer1_OVF_InterruptDisable();
		Timer1_ICU_InterruptDisable();
	}
}

static void Func_OVF(void)
{
	c++;
}
