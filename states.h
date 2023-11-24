#ifndef _states_
#define _states_

#include "inc/tm4c123gh6pm.h"
#include "types.h"

volatile uint8 NEXT_STATE;
volatile uint8 CURRENT_STATE;
volatile uint8 NEXT_COLOR;
volatile uint8 CURRENT_COLOR;
volatile uint32 var_states;
uint32 states(uint8 NEXT_STATE);

#endif
