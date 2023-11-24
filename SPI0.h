#ifndef _SPI0_
#define _SPI0_

#include "inc/tm4c123gh6pm.h"
#include "types.h"
void init_SPI0SLAVE();
void init_SPI0MASTER();
extern volatile uint32 var_states;
uint16 SPI0_receive(uint16 DATA);
uint16 SPI0_send(uint16 msg);
uint32 states(uint8 NEXT_STATE);
#endif
