//
// Created by CHBADMIN on 10/13/2019.
//

#ifndef CS201ASSIGNMENT4_PQUEUE_CBURLESO_H
#define CS201ASSIGNMENT4_PQUEUE_CBURLESO_H

// Priority queue struct
typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;

// Function declarations
int enqueue(PQueueNode **pqueue, int priority, void *data);
void *dequeue(PQueueNode **pqueue);
void *peek(PQueueNode *pqueue);
int printQueue(PQueueNode *pqueue, void (printFunction)(void*));
int getMinPriority(PQueueNode *pqueue);
int queueLength(PQueueNode *pqueue);
void printProcess(void *data);

#endif //CS201ASSIGNMENT4_PQUEUE_CBURLESO_H
