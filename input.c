/*
 * input.c
 *
 *  Created on: Nov 16, 2023
 *      Author: elmar
 */
#include "input.h"
void SW1_INIT(void)
{
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R |= (1 << 4);
    GPIO_PORTF_AMSEL_R &= ~(1 << 4);
    GPIO_PORTF_PCTL_R &= 0xFFF0FFFF;
    GPIO_PORTF_DIR_R &= ~(1 << 4);
    GPIO_PORTF_AFSEL_R &= ~(1 << 4);
    GPIO_PORTF_PUR_R |= (1 << 4);
    GPIO_PORTF_DEN_R |= (1 << 4);
}

void SW2_INIT(void)
{
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R |= (1 << 0);
    GPIO_PORTF_AMSEL_R &= ~(1 << 0);
    GPIO_PORTF_PCTL_R &= 0xFFFFFFF0;
    GPIO_PORTF_DIR_R &= ~(1 << 0);
    GPIO_PORTF_AFSEL_R &= ~(1 << 0);
    GPIO_PORTF_PUR_R |= (1 << 0);
    GPIO_PORTF_DEN_R |= (1 << 0);
}

void debounce_delay(int mtime)
{
    volatile int i;
    SYSCTL_RCGCTIMER_R |= 1; /*enable clock for TimerA */
    TIMER0_CTL_R = 0; /*disable timer before initialization */
    TIMER0_CFG_R = 0x04; /*16-bit option */
    TIMER0_TAMR_R = 0x02; /*periodic mode and down counter */
    TIMER0_TAILR_R = 16000 - 1; /*TimerA interval load value register */
    TIMER0_ICR_R = 0x01; /*clear the TimerA timeout flag */
    TIMER0_CTL_R |= 0x01; /*enable TimerA after initialization */
    for (i = 0; i < mtime; i++)
    {
        while ((TIMER0_RIS_R & 0x01) == 0)
            ; /*wait for TimerA timeout flag */
        TIMER0_ICR_R = 0x01; /*clear the TimerA timeout flag */
    }
//    SYSCTL_RCGCTIMER_R |= 0x01;
//    TIMER0_CTL_R = 0;
//    TIMER0_CFG_R = 0X04;
//    TIMER0_TAMR_R = 0X01;
//    TIMER0_TAILR_R = (16000 * mtime) - 1;
//    TIMER0_ICR_R = 0X1;
//    TIMER0_CTL_R = 0X01;
//    while ((TIMER0_RIS_R & 0x1) == 0);
//    TIMER0_ICR_R |= (1 << 0);

}
uint8 chk_SW1(void)
{
    if (!(GPIO_PORTF_DATA_R & (1 << 4)))
    {
        debounce_delay(15);
        if (!(GPIO_PORTF_DATA_R & (1 << 4)))
            return 1;
    }
    return 0;
}

uint8 chk_SW2(void)
{
    if (!(GPIO_PORTF_DATA_R & (1 << 0)))
    {
        debounce_delay(15);
        if (!(GPIO_PORTF_DATA_R & (1 << 0)))
            return 1;
    }
    return 0;
}

uint8 get_input(void)
{
    if (chk_SW1())
    {
        while (chk_SW1())
        {
            if (chk_SW2())
            {
                return BOTH_BTNS;
            }
        }
        return BTN1;
    }
    if (chk_SW2())
    {
        while (chk_SW2())
        {
            if (chk_SW1())
            {
                return BOTH_BTNS;
            }
        }
        return BTN2;
    }
    return NONE;
}
void input_INIT(void)
{
    SYSCTL_RCGCGPIO_R |= 0x20;
    while (!(SYSCTL_PRGPIO_R & 0x20))
        ;
    SW2_INIT();
    SW1_INIT();
}
