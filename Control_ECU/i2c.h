 /******************************************************************************
 *
 * Module:
 *
 * File Name: I2C.h
 *
 * Description: Header file for the AVR I2C driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/


#ifndef I2C_H_
#define I2C_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */
/*******************************************************************************
 *                             Types Declaration                               *
 *******************************************************************************/
typedef enum
{
	TWPS_1,TWPS_4,TWPS_16,TWPS_64
}TWI_prescalerType;

typedef struct
{
	uint32 bitRate;
	uint8  address;
	TWI_prescalerType prescaler;
}TWI_configType;

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/*
 * Description : Function to initialize the ... driver
 * 	1.
 * 	2.
 * 	3.
 * 	4.
 */
void TWI_init(TWI_configType * config_ptr);
/*
 * Description:
 */
void TWI_start(void);
/*
 * Description:
 */
void TWI_stop(void);
/*
 * Description:
 *
 */
void TWI_writeByte(uint8 data);
/*
 * Description:
 */
uint8 TWI_readByteWithACK(void);
/*
 * Description:
 */
uint8 TWI_readByteWithNACK(void);
/*
 * Description:
 */
uint8 TWI_getStatus(void);


#endif /* I2C_H_ */
