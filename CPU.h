#ifndef CPU_H_   /* Include guard */
#define CPU_H_
// length of a time quantum
#define QUANTUM 1
#include "task.h"

// run the specified task for the following time slice
void run(Task *task, int slice);
#endif