/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dcmotor.c
 *
 * Description: Source file for the AVR dc motor driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/

#include "dcmotor.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "gpio.h" /* To use gpio functions */
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description : Function to initialize the DC MOTOR driver
 * 	1. The Function responsible for setup the direction for the two
       motor pins through the GPIO driver.
 * 	2. Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PINX_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PINY_ID,PIN_OUTPUT);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PINX_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PINY_ID,LOGIC_LOW);
}

/*
 * Description:  The function responsible for rotate the DC Motor CW/ or A-CW or
                 stop the motor based on the state input state value.
 */
void DcMotor_Rotate(Dc_motorStateType state)
{
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PINX_ID,(state & 0x01));
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PINY_ID,(state & 0x02)>>1);
}
