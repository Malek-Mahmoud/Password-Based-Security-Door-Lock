/******************************************************************************
 *
 * File Name: interface.c
 *
 * Description: Source file for the HMI ECU.
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/
#include "interface.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h>
#include <avr/delay.h>
#include "timer.h"
#include "keypad.h"
#include "lcd.h"
#include "uart.h"
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
uint8 g_password[PASS_SIZE];
uint8 g_tick =0;
uint8 g_sec=0;
uint8 g_passwordState = 0;
/*******************************************************************************/
/*******************************************************************************
 *                              Main Routine                                   *
 *******************************************************************************/
int main(void)
{
	uint8 selectedoption = 0;
	SREG = (1<<7);
	UART_configType uart_config = {9600,EGITH_BIT,DISABLE_PARITY,ONE_BIT};
	timer_8bitConfigType timer0_config = {0,0,CLK_1024,DISABLE};

	UART_init(&uart_config);
	timer0_OVFmodeInit(&timer0_config);
	timer0_OVFmode_setCallBack(interface_timerCallBack);
	LCD_init();

	interface_initNewPassword();
	while(1)
	{
		interface_mainOptions();
		selectedoption = KEYPAD_getPressedKey();
		if(selectedoption == '+')
		{
			UART_sendByte(OPEN_DOOR_COMMAND);
			interface_enterPassword(g_password);
			if(g_passwordState == SUCCESS)
			{
				interface_doorUnlockingRoutine();
			}
			else
			{
				/*do nothing*/
			}
		}
		else if(selectedoption == '-')
		{
			UART_sendByte(CHANGE_PASS_COMMAND);
			interface_changeRoutine();
		}
	}
	return 0;
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description: function to get password from user and save it in an array
 */
void interface_getPassword(uint8* pass)
{
	uint8 count,current;
	for(count=0;count<PASS_SIZE;count++)
	{
		current = KEYPAD_getPressedKey();
		LCD_displayCharacter('*');
		pass[count] = current;
	}

	while(KEYPAD_getPressedKey() != ENTER){}
}
/*
 * Description:function to handle entering the password
 */
void interface_enterPassword(uint8* pass)
{
	uint8 count=0;
	do
	{
		LCD_displayString("Enter the pass");
		LCD_moveCursor(1, 4);
		interface_getPassword(g_password);
		interface_sendPassword(g_password);
		g_recieveData = 0;
		while(g_recieveData != 0){}
		g_passwordState = g_recieveData;
		if(g_passwordState == ERROR)
		{
			count ++;
			if(count == 3)
			{
				g_sec = 0;
				LCD_clearScreen();
				LCD_displayString("WRONG PASSWORD");
				LCD_displayStringRowColumn(1,0, "Try after 1 min");
				while(g_sec <= DOOR_ERROR_DELAY);
				break;
			}
		}
	}while(g_passwordState != SUCCESS);
}
/*
 * Description: function to initialize new password
 */
void interface_initNewPassword(void)
{
	while(g_passwordState == ERROR)
	{
		LCD_clearScreen();
		LCD_displayString("Enter new Pass");
		LCD_moveCursor(1, 4);
		interface_getPassword(g_password);
		interface_sendPassword(g_password);

		/* get confirm password from user */
		LCD_clearScreen();
		LCD_displayString("re-Enter the Pass");
		LCD_moveCursor(1, 4);
		interface_getPassword(g_password);
		interface_sendPassword(g_password);

		g_recieveData = 0;
		while(g_recieveData != 0){}

		g_passwordState = g_recieveData;
		if(g_passwordState == ERROR)
		{
			g_sec=0;
			LCD_clearScreen();
			LCD_displayString("Mismatch!");
			while(g_sec == 1);
		}
		else
		{
			break;
		}
	}
}
/*
 * Description: function to send the password via UART
 */
void interface_sendPassword(uint8* pass)
{
	uint8 count;
	for(count = 0;count<PASS_SIZE;count++)
	{
		UART_sendByte(pass[count]);
	}
}
/*
 * Description: function to display the options
 */
void interface_mainOptions(void)
{
	LCD_clearScreen();
	LCD_displayString("+ : Open door");
	LCD_displayStringRowColumn(1, 0, "- : Change pass");
}
/*
 * Description: call-back function called by the timer every 1 overflow
 */
void interface_timerCallBack(void)
{
	g_tick++;
	if(g_tick == NO_OF_OVF_PER_SECOND)
	{
		g_sec++;
		g_tick=0;
	}
}
/*
 * Description: function to handle the door unlocking routine
 */
void interface_doorUnlockingRoutine(void)
{
	g_sec = 0;
	LCD_clearScreen();
	LCD_displayString("Door is unlocking");
	while(g_sec <= DOOR_UNLOCKING_DELAY);

	g_sec = 0;
	LCD_clearScreen();
	LCD_displayString("Door is now open");
	while (g_sec <= DOOR_HOLDING_DELAY);

	g_sec = 0;
	LCD_clearScreen();
	LCD_displayString("Door is locking");
	while (g_sec <= DOOR_LOCKING_DELAY);

}
/*
 * Description: function to handle changing password routine
 */
void interface_changeRoutine(void)
{
	LCD_clearScreen();

	interface_enterPassword(g_password);
	if(g_passwordState == SUCCESS)
	{
		g_passwordState = ERROR;
		interface_initNewPassword();
	}
	else
	{
		/*do nothing*/
	}
}
