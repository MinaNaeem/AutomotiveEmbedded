#include "inc/tm4c123gh6pm.h"
#include "types.h"
#include "SPI0.h"
#include "states.h"
uint32 states(uint8 NEXT_STATE){
   
    var_states=NEXT_STATE * 10;
    var_states+=CURRENT_STATE;
    var_states*=10;
    var_states+=NEXT_COLOR;
    var_states*=10;
    var_states+=CURRENT_COLOR;
    return var_states;
}
