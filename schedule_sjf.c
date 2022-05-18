#include <stdio.h>
#include "schedule.h"
#include "task.h"
#include "list.h"
#include "CPU.h"
#include <stdlib.h>


// add a task to the list 
void add_task(char *name, int priority, int burst){
   Task * temp = malloc(sizeof(struct task));
   temp->name = name;
   temp->priority = priority;
   temp->burst = burst;
   
   insert_sjf((&list.head), temp);
}

// invoke the scheduler
void schedule(){
   sjf_consult(list.head);
   for(int i = 0; i < 6; i++){
      run(sjf_exe_order[i], sjf_exe_order[i]->burst);
   }
}


