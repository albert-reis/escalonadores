
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
Task *sjf_exe_order[5];
// insert and delete operations.
void insert_rr(struct node **head, Task *task);
void insert_sjf(struct node **head, Task *task);
void delete(struct node **head, Task *task);
void sjf_consult(struct node *head);
void consult(struct node *head);

#endif