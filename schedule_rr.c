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
   struct node *aux;
   struct node *temp = list.head;
   while (1){
      
      if (temp->task->burst > QUANTUM){
         run(temp->task, QUANTUM);
         temp->task->burst = temp->task->burst - QUANTUM;
         temp = temp->next;
      } else {
         run(temp->task ,temp->task->burst);
         aux = temp->next;
         delete((&list.head), temp->task);
         temp = aux;
      }     
   }
}