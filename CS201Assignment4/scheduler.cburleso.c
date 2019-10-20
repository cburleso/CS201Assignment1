#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "scheduler.cburleso.h"

// Create new array of processes
Process processArray[5];

int TOTAL_PROCESSES = 5;

// Process queue
PQueueNode *ProcessQueue = NULL;

// Current time variable
int currentTime = 0;

int waitTime, totalWaitTime;
bool machineBusy = false;

const char* stringEventType(EventType type){
    switch (type)
    {
        case PROCESS_SUBMITTED: return "PROCESS_SUBMITTED";
        case PROCESS_STARTS: return "PROCESS_STARTS";
        case PROCESS_ENDS: return "PROCESS_ENDS";
        case PROCESS_TIMESLICE_EXPIRES: return "PROCESS_TIMESLICE_EXPIRES";
    }
}

Process *createProcesses(){
    Process *processOne;
    processOne = (Process *) malloc(sizeof(Process)); // Create process one
    processOne->pid = 1;
    processOne->burstTime = 6;
    processArray[0] = *processOne;

    Process *processTwo;
    processTwo = (Process *) malloc(sizeof(Process)); // Create process two
    processTwo->pid = 2;
    processTwo->burstTime = 7;
    processArray[1] = *processTwo;

    Process *processThree;
    processThree = (Process *) malloc(sizeof(Process)); // Create process three
    processThree->pid = 3;
    processThree->burstTime = 2;
    processArray[2] = *processThree;

    Process *processFour;
    processFour = (Process *) malloc(sizeof(Process)); // Create process four
    processFour->pid = 4;
    processFour->burstTime = 5;
    processArray[3] = *processFour;

    Process *processFive;
    processFive = (Process *) malloc(sizeof(Process)); // Create process five
    processFive->pid = 5;
    processFive->burstTime = 2;
    processArray[4] = *processFive;

    return processArray;

}

void enqueueProcesses(PQueueNode **eventPQueue, Process *processes, int numProcesses){
    int startTimes[] = {0, 3, 4, 6, 6}; // Start times of processes 1 - 5
    for (int i = 0; i < numProcesses; i++){
        Event *newEvent;
        newEvent = (Event *) malloc(sizeof(Event));
        newEvent->eventType = PROCESS_SUBMITTED;
        newEvent->process = &processes[i];
        enqueue(eventPQueue, startTimes[i], newEvent); // Enqueue new Event (pointing to current process)
    }
}

void runSimulation(int schedulerType, int quantum, PQueueNode *eventPQueue){

    currentTime = getMinPriority(eventPQueue);
    Event *event = dequeue(&eventPQueue);
    while (event != NULL){
        Process *process = event->process;
        if (event->eventType == PROCESS_SUBMITTED){
            printf("t = %-4d %-19s pid = %-3d\n", currentTime, stringEventType(event->eventType), process->pid);
            process->lastTime = currentTime;
            if (!machineBusy){
                Event *newEvent = (Event *) malloc(sizeof(Event));
                newEvent->eventType = PROCESS_STARTS;
                newEvent->process = process;
                enqueue(&eventPQueue, currentTime, newEvent);
                machineBusy = true;
            } else {
                if (schedulerType == 1){ // FCFS
                    enqueue(&ProcessQueue, 0, process);
                }
                if (schedulerType == 2){ // SJF
                    enqueue(&ProcessQueue, process->burstTime, process);
                }
            }

        } else if (event->eventType == PROCESS_STARTS){
            printf("t = %-4d %-19s pid = %-3d\n", currentTime, stringEventType(event->eventType), process->pid);
            waitTime = currentTime - process->lastTime;
            totalWaitTime += waitTime;
            process->waitTime = waitTime;
            Event *newEvent = (Event *) malloc(sizeof(Event));
            newEvent->eventType = PROCESS_ENDS;
            newEvent->process = process;
            enqueue(&eventPQueue, currentTime + process->burstTime, newEvent);

        } else if (event->eventType == PROCESS_ENDS){
            printf("t = %-4d %-19s pid = %-3d waitTime = %d\n", currentTime, stringEventType(event->eventType),
                   process->pid,
                   process->waitTime);
            if (queueLength(ProcessQueue) > 0){
                process = dequeue(&ProcessQueue);
                Event *newEvent = (Event *) malloc(sizeof(Event));
                newEvent->eventType = PROCESS_STARTS;
                newEvent->process = process;
                enqueue(&eventPQueue, currentTime, newEvent);
            } else {
                machineBusy = false;
            }
        }

        currentTime = getMinPriority(eventPQueue);
        event = dequeue(&eventPQueue);

    }
    printf("\nMean wait time = %d ms", totalWaitTime / TOTAL_PROCESSES);
}





