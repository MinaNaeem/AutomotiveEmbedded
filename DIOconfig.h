/*
 * DIOconfig.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mina
 */

#include "types.h"
#define portA 0
#define portB 1
#define portC 2
#define portD 3
#define portE 4
#define portF 5


#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7



#define output 1
#define input 0

#define input_pullup 1

#define alternative 1

void gpio_init_fast(int port,int pinNo, int pinMode,int analog, int pullup, int AlterFn);






