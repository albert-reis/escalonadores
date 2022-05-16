
#ifndef LIST_H_   /* Include guard */
#define LIST_H_
/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};
Task sjf_exe_order[6] = NULL;
// insert and delete operations.
void insert(struct node **head, Task *task);
void delete(struct node **head, Task *task);
void traverse(struct node *head);

#endif