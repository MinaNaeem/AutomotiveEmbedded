/*
 * DIOconfig.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mina
 */


#define portA 0
#define portB 1
#define portC 2
#define portD 3
#define portE 4
#define portF 5


#define pin0 0x01
#define pin1 0x02
#define pin2 0x04
#define pin3 0x08
#define pin4 0x10
#define pin5 0x20
#define pin6 0x40
#define pin7 0x80

#define output 1
#define input 0

#define input_pullup 1

#define alternative 1

void gpio_init_fast(int port,int pinNo, int pinMode,int analog, int pullup, int AlterFn);


