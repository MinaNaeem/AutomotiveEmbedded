#include <SysTick.h>
#include"bitwise_operation.h"
#include"DIOconfig.h"
#include "scheduler.h"
#include "SysTick.h"
#include "led.h"
void Task1(void)
{
     blue_led();
}

void Task2(void)
{
     green_led();
}



int main(void)
{
//gpio_init_fast(portA, pin0, output, 0, 0, 0); //initializing pin0 on portA to be a (Digital) output with no pullup and no alternative function select

//UART0_en();
//UART0_send("UART initiated successfully\n");


Led_INIT();
task_init(Task1,500);
task_init(Task2,1000);

__asm(" CPSIE I ");

SysTick_Setup_Second();



task_sched();
//char message1[10] = "Mina\n";
//UART0_send(message1);

return 0;
}
