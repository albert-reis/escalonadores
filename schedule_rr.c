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
   
   insert((&list.head), temp);
}

// invoke the scheduler
void schedule(){
   for (struct node  *temp = list.head; temp != NULL; temp = temp->next){
      
      if (temp->task->burst >= QUANTUM){
         run(temp->task, QUANTUM);
         temp->task->burst = temp->task->burst - QUANTUM;
      } else {
         run(temp->task ,temp->task->burst);
         delete((&list.head), temp->task);
      }     
   }
}