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
   
   insert(&(list.head), &temp);

   //traverse(list.head);
}

// invoke the scheduler
void schedule(){
   traverse(list.head);
   for(int i = 0; i < 6; i++){
      run(sjf_exe_order[i], sjf_exe_order[i]->burst);
   }
}