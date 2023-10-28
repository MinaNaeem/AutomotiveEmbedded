#include"bitwise_operation.h"
#include"DIOconfig.h"

int main(void)
{
gpio_init_fast(portA, pin0, output, 0, 0, 0); //initializing pin0 on portA to be a (Digital) output with no pullup and no alternative function select

return 0;
}
