/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "schedule.h"
#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = malloc(sizeof(struct node));
    if (*head == NULL){
        newNode->task = newTask;
        newNode->next = *head;
        *head = newNode;
        list.last = newNode;
    } else {
        newNode->task = newTask;
        newNode->next = *head;
        *head = newNode;
        list.last->next = *head;
    }
}

// delete the selected task from the list
void delete(struct node **head, Task *task) {
    struct node *temp;
    struct node *prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node *head) {
    Task *aux; 
    int j = 0;
    for (struct node  *temp = head; temp != NULL; temp = temp->next) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        
        sjf_exe_order[j] = temp->task;
        for(int i = 0; i < j; i++){
            if(temp->task->burst < sjf_exe_order[i]->burst){
                aux = sjf_exe_order[i];
                sjf_exe_order[i] = temp->task;
                temp->task = aux;
            }
        }
        j++;
    }
}
void consult(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}
