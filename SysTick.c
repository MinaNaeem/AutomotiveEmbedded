#include "SysTick.h"

uint32 systick_counter = 0;
uint8 systick_flag = 0;

void Systick_INIT(void)
{
    SYSTICK_CTRL_REG = 0;
    SYSTICK_RELOAD_REG = 16000 - 1;
    SYSTICK_CURRENT_REG = 0;
    SYSTICK_CTRL_REG = 0x7;
}

void SysTick_Handler(void)
{
    systick_counter++;
    if (systick_counter > 5001)
    {
        systick_counter = 0;
    }
    systick_flag = 0;
}
