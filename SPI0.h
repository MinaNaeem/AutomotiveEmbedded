#ifndef _SPI0_
#define _SPI0_

#include "inc/tm4c123gh6pm.h"
#include "types.h"
void init_SPI0SLAVE();
void init_SPI0MASTER();

uint16 SPI0_receive(uint16 DATA);
uint16 SPI0_send(uint16 msg);


#endif
