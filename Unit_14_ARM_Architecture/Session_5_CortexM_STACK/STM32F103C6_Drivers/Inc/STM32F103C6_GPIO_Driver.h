/*
 * STM32F103C6_GPIO_Driver.h
 *
 *  Created on: Dec 5, 2023
 *      Author: youssef
 */

#ifndef STM32F103C6_GPIO_DRIVER_H_
#define STM32F103C6_GPIO_DRIVER_H_

// Includes
#include "STM32F103C6_MemMap.h"

//----------------------------------

//Config Structure
typedef struct
{
	uint16_t GPIO_PinNumber ; // Specifies the GPIO pins to be configured.
							 // This parameter must be set based on @ref GPIO_PINS_define

	uint8_t  GPIO_MODE      ; // Specifies the operating mode for the selected pins
							// This parameter can be a value of @ref GPIO_MODE_define

	uint8_t GPIO_Output_Speed ;    // Specifies the speed for the selected pins
								  // This parameter can be a value of @ref GPIO_SPEED_define


}GPIO_PinConfig_t;


//@ref GPIO_PIN_state
#define GPIO_PIN_SET    	1
#define GPIO_PIN_RESET     	0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enabled    	1
#define GPIO_RETURN_LOCK_ERROR     	    0

//================================
//Macros Configuration References
//================================

// @ref GPIO_PINS_define
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    0000 0000 0000 0001*/
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected	0000 0000 0000 0010  */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected  	0000 0000 0000 0100  */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected  	0000 0000 0000 1000  */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected  	0000 0000 0001 0000  */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected  	0000 0000 0010 0000  */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected  	0000 0000 0100 0000  */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected  	0000 0000 1000 0000  */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    0000 0001 0000 0000  */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    0000 0010 0000 0000  */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   0000 0100 0000 0000  */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   0000 1000 0000 0000  */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   0001 0000 0000 0000  */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   0010 0000 0000 0000  */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   0100 0000 0000 0000  */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   1000 0000 0000 0000  */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected 1111 1111 1111 1111  */

#define GPIO_PIN_MASK              0x0000FFFFu /* PIN mask for assert test */

// @ref GPIO_MODE_define
// Analog mode
// Floating input (reset state)
// Input with pull-up
// Pull-down
// General purpose output push-pull
// General purpose output Open-drain
// Alternate function output Push-pull
// Alternate function output Open-drain
// Alternate function  INPUT
#define  GPIO_MODE_Analog						 0x00000000u   //Analog mode
#define  GPIO_MODE_INPUT_FLO                     0x00000001u   //Floating input
#define  GPIO_MODE_INPUT_PU                      0x00000002u   //Input with pull-up
#define  GPIO_MODE_INPUT_PD                      0x00000003u   //Input with pull-down
#define  GPIO_MODE_OUTPUT_PP                     0x00000004u   //General purpose output push-pull
#define  GPIO_MODE_OUTPUT_OD                     0x00000005u   //General purpose output Open-drain
#define  GPIO_MODE_OUTPUT_AF_PP                  0x00000006u   //Alternate function output Push-pull
#define  GPIO_MODE_OUTPUT_AF_OD                  0x00000007u   //Alternate function output Open-drain
#define  GPIO_MODE_AF_INPUT                      0x00000008u   //Alternate function INPUT



// @ref GPIO_SPEED_define
// Output mode, max speed 10 MHz.
// Output mode, max speed 2 MHz.
// Output mode, max speed 50 MHz

#define GPIO_SPEED_10M		0x00000001u  //Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M		0x00000002u  //Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M		0x00000003u  //Output mode, max speed 50 MHz.


/*
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */

void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit (GPIO_TypeDef *GPIOx);

uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber );
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx,uint16_t PinNumber , uint8_t Value);
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint16_t Value);

void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx,uint16_t PinNumber );

uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber );


#endif /* STM32F103C6_GPIO_DRIVER_H_ */
