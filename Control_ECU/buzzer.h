
 /******************************************************************************
 *
 * Module: buzzer
 *
 * File Name: buzzer.h
 *
 * Description: Header file for the AVR buzzer driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUZZER_PORT_ID PORTC_ID
#define BUZZER_PIN_ID  PIN5_ID

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/*
 * Description : Function to initialize the BUZZER driver
 * 	1. set the direction for the buzzer pin as output pin.
 */
void buzzer_init(void);
/*
 * Description: setting the buzzer pin.
 */
void buzzer_turnON(void);
/*
 * Description: clearing the buzzer pin.
 */
void buzzer_turnOFF(void);

#endif /* BUZZER_H_ */
