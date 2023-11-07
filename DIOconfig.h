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


#define pin0 1<<0
#define pin1 1<<1
#define pin2 1<<2
#define pin3 1<<3
#define pin4 1<<4
#define pin5 1<<5
#define pin6 1<<6
#define pin7 1<<7

typedef unsigned long uint32_t;

#define output 1
#define input 0

#define input_pullup 1

#define alternative 1

void gpio_init_fast(int port,int pinNo, int pinMode,int analog, int pullup, int AlterFn);
void UART0_en(uint32_t baud);
void UART1_en(uint32_t baud);



