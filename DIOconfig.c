#include "inc/tm4c123gh6pm.h"
#include <stdio.h>
typedef unsigned long uint32_t;

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


