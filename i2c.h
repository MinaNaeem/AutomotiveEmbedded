/*
 * i2c.h
 *
 *  Created on: Nov 24, 2023
 *      Author: Mina
 */
#ifndef I2C_H_
#define I2C_H_

#include "inc/tm4c123gh6pm.h"
#include "types.h"



void I2CMasterInit(uint8 slaveAddr);
void I2CMasterSend(uint8 data);
void delay(uint32 value);



#endif /* I2C_H_ */



