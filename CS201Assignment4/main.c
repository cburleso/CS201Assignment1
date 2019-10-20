#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.cburleso.h"

PQueueNode *EventPQueue = NULL; // Initialize Event Queue
int NUM_PROCESSES = 5;

int main() {
    // Create the five processes
    Process *allProcesses = createProcesses();

    // Enqueue the processes
    enqueueProcesses(&EventPQueue, allProcesses, NUM_PROCESSES);

    runSimulation(1, 0, EventPQueue);


    return 0;
}