 /******************************************************************************
 *
 * Module: buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the AVR buzzer driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/

#include "buzzer.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "gpio.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description : Function to initialize the ... driver
 * 	1.
 * 	2.
 * 	3.
 * 	4.
 */
void buzzer_init(void)
{
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
}
/*
 * Description:
 */
void buzzer_turnON(void)
{
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_HIGH);
}
/*
 * Description:
 */
void buzzer_turnOFF(void)
{
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}
