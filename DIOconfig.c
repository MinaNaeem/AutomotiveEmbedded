#include "inc/tm4c123gh6pm.h"
#include <stdio.h>
#include "math.h"

typedef unsigned long uint32_t;

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

void gpio_init_fast(int port,int pinNo, int pinMode,int analog, int pullup, int AlterFn)
{
    switch(port){
    case portA:
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        SYSCTL_RCGCGPIO_R |= 0x01;
        GPIO_PORTA_CR_R |= pinNo;
        if(analog) GPIO_PORTA_AMSEL_R |= pinNo;
        else
        {
            GPIO_PORTA_AMSEL_R &= ~pinNo;
            GPIO_PORTA_DEN_R |= pinNo;
        }
        if(pinMode) GPIO_PORTA_DIR_R |= pinNo;
        else GPIO_PORTA_DIR_R &= ~pinNo;

        if(pullup) GPIO_PORTA_PUR_R |= pinNo;
        else GPIO_PORTA_PUR_R &= ~pinNo;
        if(AlterFn) GPIO_PORTA_AFSEL_R|= pinNo;
        else GPIO_PORTA_AFSEL_R &= ~pinNo;
        break;


    case portB:
        SYSCTL_RCGCGPIO_R |= 0x02;
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        GPIO_PORTB_CR_R |= pinNo;

        if(analog) GPIO_PORTB_AMSEL_R |= pinNo;
                else
                {
                    GPIO_PORTB_AMSEL_R &= ~pinNo;
                    GPIO_PORTB_DEN_R |= pinNo;
                }
                if(pinMode) GPIO_PORTB_DIR_R |= pinNo;
                else GPIO_PORTB_DIR_R &= ~pinNo;

                if(pullup) GPIO_PORTB_PUR_R |= pinNo;
                else GPIO_PORTB_PUR_R &= ~pinNo;
                if(AlterFn) GPIO_PORTB_AFSEL_R|= pinNo;
                else GPIO_PORTB_AFSEL_R &= ~pinNo;
                break;



    case portC:
        SYSCTL_RCGCGPIO_R |= 0x04;
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        GPIO_PORTC_CR_R |= pinNo;
        if(analog) GPIO_PORTC_AMSEL_R |= pinNo;
                else
                {
                    GPIO_PORTC_AMSEL_R &= ~pinNo;
                    GPIO_PORTC_DEN_R |= pinNo;
                }
                if(pinMode) GPIO_PORTC_DIR_R |= pinNo;
                else GPIO_PORTC_DIR_R &= ~pinNo;

                if(pullup) GPIO_PORTC_PUR_R |= pinNo;
                else GPIO_PORTC_PUR_R &= ~pinNo;
                if(AlterFn) GPIO_PORTC_AFSEL_R|= pinNo;
                else GPIO_PORTC_AFSEL_R &= ~pinNo;
                break;






    case portD:
        SYSCTL_RCGCGPIO_R |= 0x08;
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        GPIO_PORTD_CR_R |= pinNo;

        if(analog) GPIO_PORTD_AMSEL_R |= pinNo;
                else
                {
                    GPIO_PORTD_AMSEL_R &= ~pinNo;
                    GPIO_PORTD_DEN_R |= pinNo;
                }
                if(pinMode) GPIO_PORTD_DIR_R |= pinNo;
                else GPIO_PORTD_DIR_R &= ~pinNo;

                if(pullup) GPIO_PORTD_PUR_R |= pinNo;
                else GPIO_PORTD_PUR_R &= ~pinNo;
                if(AlterFn) GPIO_PORTD_AFSEL_R|= pinNo;
                else GPIO_PORTD_AFSEL_R &= ~pinNo;
                break;






    case portE:
        SYSCTL_RCGCGPIO_R |= 0x10;
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        GPIO_PORTE_CR_R |= pinNo;

        if(analog) GPIO_PORTE_AMSEL_R |= pinNo;
                      else
                      {
                          GPIO_PORTE_AMSEL_R &= ~pinNo;
                          GPIO_PORTE_DEN_R |= pinNo;
                      }
                      if(pinMode) GPIO_PORTE_DIR_R |= pinNo;
                      else GPIO_PORTE_DIR_R &= ~pinNo;

                      if(pullup) GPIO_PORTE_PUR_R |= pinNo;
                      else GPIO_PORTE_PUR_R &= ~pinNo;
                      if(AlterFn) GPIO_PORTE_AFSEL_R|= pinNo;
                      else GPIO_PORTE_AFSEL_R &= ~pinNo;
                      break;






    case portF:
        SYSCTL_RCGCGPIO_R |= 0x20;
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        GPIO_PORTF_CR_R |= pinNo;

        if(analog) GPIO_PORTF_AMSEL_R |= pinNo;
                      else
                      {
                          GPIO_PORTF_AMSEL_R &= ~pinNo;
                          GPIO_PORTF_DEN_R |= pinNo;
                      }
                      if(pinMode) GPIO_PORTF_DIR_R |= pinNo;
                      else GPIO_PORTF_DIR_R &= ~pinNo;

                      if(pullup) GPIO_PORTF_PUR_R |= pinNo;
                      else GPIO_PORTF_PUR_R &= ~pinNo;
                      if(AlterFn) GPIO_PORTF_AFSEL_R|= pinNo;
                      else GPIO_PORTF_AFSEL_R &= ~pinNo;
                      break;


    }
}

void UART0_en(uint32_t baud)
{
    uint32_t FBRDvar, IBRDvar;

    // enable clock for UART0 and port A
    SYSCTL_RCGCUART_R |= (1<<0);
    SYSCTL_RCGCGPIO_R |= (1<<0);

    // disable UART0
    UART0_CTL_R = 0;

    IBRDvar = floor(SYSCTL_RCC_R / (16 * baud));
    FBRDvar = floor((SYSCTL_RCC_R / (16 * baud) - IBRDvar) * 64 + 0.5);    // CHECK THIS LINE OF CODE****
    UART0_FBRD_R = FBRDvar;
    UART0_IBRD_R = IBRDvar;

    // set line control of UART0
    UART0_LCRH_R = 0x60; // 8-bit data, no parity, one stop bit, no FIFO

    // set clock source of UART0
    UART0_CC_R = 0; // use system clock

    // enable port A as GPIO for UART0
    GPIO_PORTA_CR_R = 0x03; // enable PA0 and PA1

    // set PA0 and PA1 as input
    GPIO_PORTA_DIR_R &= ~(0x03);

    // enable digital function for PA0 and PA1
    GPIO_PORTA_DEN_R |= 0x03;

    // select alternate function for PA0 and PA1
    GPIO_PORTA_AFSEL_R |= 0x03;

    // select UART function for PA0 and PA1
    GPIO_PORTA_PCTL_R = 0x11;

    // enable UART0, TXE, and RXE
    UART0_CTL_R = 0x301;
}

void UART1_en(uint32_t baud)
{
    uint32_t FBRDvar, IBRDvar;

    SYSCTL_RCGCUART_R |= (1<<1);
    SYSCTL_RCGCGPIO_R |= (1<<1);
     UART1_CTL_R = 0;

     IBRDvar = floor(SYSCTL_RCC_R / (16 * baud));
     FBRDvar = floor((SYSCTL_RCC_R / (16 * baud)) - IBRDvar * 64 + 0.5);
     UART1_FBRD_R = FBRDvar;
     UART1_IBRD_R = IBRDvar;

    UART1_LCRH_R = 0x60; // 8-bit data, no parity, one stop bit, no FIFO
    UART1_CC_R = 0; // use system clock
    GPIO_PORTB_CR_R = 0x03; // enable PB0 and PB1
    GPIO_PORTB_DIR_R &= ~(0x03);
    GPIO_PORTB_DEN_R |= 0x03;
    GPIO_PORTB_AFSEL_R |= 0x03;
    GPIO_PORTB_PCTL_R = 0x11;
    UART1_CTL_R = 0x301;

}

