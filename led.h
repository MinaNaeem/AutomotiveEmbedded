/*
 * led.h
 *
 *  Created on: Nov 16, 2023
 *      Author: elmar
 */

#ifndef LED_H_
#define LED_H_

#include "inc/tm4c123gh6pm.h"
#include "types.h"

void green_led(void);
void Red_led(void);
void blue_led(void);
void white_led(void);
void clear_leds(void);
void Led_INIT(void);

#endif /* LED_H_ */
