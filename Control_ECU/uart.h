/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the AVR UART driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
extern volatile uint8 g_recieveData;

typedef enum
{
	ONE_BIT,TWO_BIT
}UART_stopBit;

typedef enum
{
	DISABLE_PARITY,EVEN_PARITY=2,ODD_PARITY
}UART_parityMode;

typedef enum
{
	FIVE_BIT,SIX_BIT,SEVEN_BIT,EGITH_BIT,NINE_BIT=7
}UART_dataSize;


typedef struct
{
	uint32 bitRate;
	UART_dataSize dataSiza;
	UART_parityMode parityMode;
	UART_stopBit stopBit;
}UART_configType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(UART_configType * config_ptr);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
