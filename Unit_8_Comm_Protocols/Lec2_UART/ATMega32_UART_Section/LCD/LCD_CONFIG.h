/*
 * LCD_CONFIG.h
 *
 *  Created on: Sep 17, 2022
 *      Author: youssef
 */

/*
*this file is for the user where it shows the pins of LCD connected to the pins of the microcontroller
*so the user can modify any ports or pins related to the connection
*/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/**********	CONTROL PINS	**********/

#define	PORT_CONTROL	PORT_B
#define	RS				PIN_1
#define	RW				PIN_2
#define	EN				PIN_3

/******************************/
#define	PORT_DATA		PORT_A




#endif /* LCD_CONFIG_H_ */
