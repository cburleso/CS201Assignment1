//
// Created by CHBADMIN on 9/27/2019.
//

#ifndef ASSIGNMENT3_PQUEUE_CBURLESO_H
#define ASSIGNMENT3_PQUEUE_CBURLESO_H

// Student record struct
typedef struct {
    int id;
    char name[32];
} StudentRecord;

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
void printStudentRecord(void *data);


#endif //ASSIGNMENT3_PQUEUE_CBURLESO_H
