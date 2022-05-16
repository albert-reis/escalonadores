#ifndef SCHEDULE_H_   /* Include guard */
#define SCHEDULE_H_

#include "list.h"
#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add_task(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

struct node * head;


#endif