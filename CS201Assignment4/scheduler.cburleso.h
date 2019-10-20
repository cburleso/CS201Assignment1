//
// Created by CHBADMIN on 10/13/2019.
//

#ifndef CS201ASSIGNMENT4_SCHEDULER_CBURLESO_H
#define CS201ASSIGNMENT4_SCHEDULER_CBURLESO_H

#include <string.h>
#include <stdio.h>
#include "pqueue.cburleso.h"

// Event Type typedef
typedef enum EventTypeEnum{
    PROCESS_SUBMITTED,
    PROCESS_STARTS,
    PROCESS_ENDS,
    PROCESS_TIMESLICE_EXPIRES
} EventType;

// Process Struct
typedef struct {
    int pid;
    int burstTime;
    int waitTime;
    int numPreemptions;
    int lastTime;
} Process;

// Event Struct
typedef struct {
    EventType eventType;
    Process *process;
} Event;

Process *createProcesses();

void enqueueProcesses(PQueueNode **eventPQueue, Process *processes, int numProcesses);

void runSimulation(int schedulerType, int quantum, PQueueNode *eventPQueue);

const char* stringEventType(EventType type);




#endif //CS201ASSIGNMENT4_SCHEDULER_CBURLESO_H
