/*
 * input.h
 *
 *  Created on: Nov 16, 2023
 *      Author: elmar
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "types.h"
#include "inc/tm4c123gh6pm.h"

enum PRESSED_BTN{
    NONE,
    BTN1,
    BTN2,
    BOTH_BTNS,
};

void input_INIT(void);
void SW1_INIT(void);
void SW2_INIT(void);
void debounce_delay(int ttime);
uint8 chk_SW1(void);
uint8 chk_SW2(void);
uint8 get_input(void);

#endif /* INPUT_H_ */
