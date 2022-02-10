 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dcmotor.h
 *
 * Description: Header file for the AVR DC MOTOR driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT_ID PORTD_ID
#define MOTOR_PINX_ID PIN6_ID
#define MOTOR_PINY_ID PIN7_ID
/*******************************************************************************
 *                             Types Declaration                               *
 *******************************************************************************/
typedef enum
{
	STOP_ROTATION=0x00,CW_ROTATION=0x01,CCW_ROTATION=0x02
}Dc_motorStateType;
/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/*
 * Description : Function to initialize the DC MOTOR driver
 * 	1. The Function responsible for setup the direction for the two
       motor pins through the GPIO driver.
 * 	2. Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description:  The function responsible for rotate the DC Motor CW/ or A-CW or
                 stop the motor based on the state input state value.
 */
void DcMotor_Rotate(Dc_motorStateType state);

#endif /* DCMOTOR_H_ */
