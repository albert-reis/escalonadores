/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "schedule.h"

#include "task.h"
#include "list.h"

#define SIZE 100

int main(int argc, char *argv[])
{

    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    clock_t tempo;

    in = fopen(argv[1],"r");

   
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add_task(name, priority, burst);
        
        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    tempo = clock();
    schedule();
    tempo = clock() - tempo;
    printf("Escalonador com tempo de exe == %lf \n",((double)tempo)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
