#ifndef __Scheduler__
#define __Scheduler__

#include "types.h"

typedef struct{
  void (*pointer)(void);
  uint16 period;
}task;

extern uint32 systick_counter;
extern uint8 systick_flag;

void task_sched(void);
void task_init(void (*p)(void),int period);

#endif
