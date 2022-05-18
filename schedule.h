#ifndef SCHEDULE_H_   /* Include guard */
#define SCHEDULE_H_

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add_task(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

// call function of SJF shedule criterion
void sjf_criterion();

struct List
{
    struct node *head;
    struct node *last;
}List;

struct List list;

#endif