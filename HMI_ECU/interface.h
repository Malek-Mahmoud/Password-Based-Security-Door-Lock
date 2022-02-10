 /******************************************************************************
 * File Name: interface.h
 *
 * Description: Header file for the HMI ECU.
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define F_CPU 8000000
#define NO_OF_OVF_PER_SECOND 31
#define ERROR 0
#define SUCCESS 1
#define PASS_SIZE 5
#define ENTER '='

#define DOOR_UNLOCKING_DELAY 15
#define DOOR_HOLDING_DELAY 3
#define DOOR_LOCKING_DELAY 15
#define DOOR_ERROR_DELAY 1000

#define INIT_PASS_COMMAND 0XAA
#define CHANGE_PASS_COMMAND 0XAB
#define OPEN_DOOR_COMMAND 0XAC
/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/*
 * Description: function to get password from user and save it in an array
 */
void interface_getPassword(uint8* pass);
/*
 * Description:function to handle entering the password
 */
void interface_enterPassword(uint8* pass);
/*
 * Description: function to initialize new password
 */
void interface_initNewPassword(void);
/*
 * * Description: function to send the password via UART
 */
void interface_sendPassword(uint8* pass);
/*
 * Description: function to display the options
 */
void interface_mainOptions(void);
/*
 * Description: call-back function called by the timer every 1 overflow
 */
void interface_timerCallBack(void);
/*
 * Description: function to handle the door unlocking routine
 */
void interface_doorUnlockingRoutine(void);
/*
 * Description: function to handle changing password routine
 */
void interface_changeRoutine(void);

#endif /* INTERFACE_H_ */
