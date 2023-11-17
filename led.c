/*
 * led.c
 *
 *  Created on: Nov 16, 2023
 *      Author: elmar
 */
#include "led.h"

void Led_INIT(void)
{
    SYSCTL_RCGCGPIO_R |= 0x20;
    while (!(SYSCTL_PRGPIO_R & 0x20))
            ;
    GPIO_PORTF_AMSEL_R &= ~((1 << 3) | (1 << 2) | (1 << 1)); /* Disable Analog on PF1 */
    GPIO_PORTF_PCTL_R &= 0xFFFF000F; /* Clear PMCx bits for PF1 to use it as GPIO pin */
    GPIO_PORTF_DIR_R |= (1 << 3) | (1 << 2) | (1 << 1); /* Configure PF1 as output pin */
    GPIO_PORTF_AFSEL_R &= ~((1 << 3) | (1 << 2) | (1 << 1)); /* Disable alternative function on PF1 */
    GPIO_PORTF_DEN_R |= (1 << 3) | (1 << 2) | (1 << 1); /* Enable Digital I/O on PF1 */
    GPIO_PORTF_DATA_R &= ~((1 << 3) | (1 << 2) | (1 << 1)); /* Clear bit 1 in Data register to turn off the led */
}

void white_led(void)
{
    clear_leds();
    GPIO_PORTF_DATA_R |= (1 << 3) | (1 << 2) | (1 << 1);
}
void blue_led(void)
{
    clear_leds();
    GPIO_PORTF_DATA_R |= (1 << 2);
}
void Red_led(void)
{
    clear_leds();
    GPIO_PORTF_DATA_R |= (1 << 1);
}
void green_led(void)
{
    clear_leds();
    GPIO_PORTF_DATA_R |= (1 << 3);
}
void clear_leds(void)
{
    GPIO_PORTF_DATA_R &= ~((1 << 3) | (1 << 2) | (1 << 1));
}
