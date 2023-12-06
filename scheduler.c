#include "scheduler.h"

#define MAXIMUM_NUMBER_OF_TASK 10

task t_identifier;
task array[MAXIMUM_NUMBER_OF_TASK];

uint8 task_i = 0;
uint32 i = 0;

void task_init(void (*p)(void), int period)
{
    t_identifier.pointer = p;
    t_identifier.period = period;
    array[task_i] = t_identifier;
    task_i++;
}

void task_sched(void)
{
    while (1)
    {
        i = systick_counter;
        __asm(" CPSID I");
        if (i == 0)
        {
        }
        else
        {
            if (systick_flag == 0)
            {
                for (int x = 0; x < task_i; x++)
                {
                    if (i % (array[x].period) == 0)
                    {
                        (*array[x].pointer)();
                        systick_counter++;
                    }
                }
                systick_flag = 1;
            }
        }
        __asm(" CPSIE I");

    }

}
