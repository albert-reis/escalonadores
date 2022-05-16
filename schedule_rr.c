#include <stdio.h>
#include "schedule.h"
#include "task.h"
#include "list.h"

// add a task to the list 
void add_task(char *name, int priority, int burst){
   Task temp;
   temp.name = name;
   temp.priority = priority;
   temp.burst = burst;
   
   //insert(&inicio->next, &temp);
}

// invoke the scheduler
void schedule(){
   int x = 0;
}