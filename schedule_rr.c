#include <stdio.h>
#include "schedule.h"
#include "task.h"
#include "list.h"
#include "CPU.h"

// add a task to the list 
void add_task(char *name, int priority, int burst){
   Task temp;
   temp.name = name;
   temp.priority = priority;
   temp.burst = burst;
   
   insert(head->next, &temp);
}

// invoke the scheduler
void schedule(){
   for ()
  
}