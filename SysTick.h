#ifndef __SysTick__
#define __SysTick__
#include "types.h"
#include "inc/tm4c123gh6pm.h"


#define SYSTICK_CTRL_REG          (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile uint32 *)0xE000E018))

void Systick_INIT(void);

#endif
