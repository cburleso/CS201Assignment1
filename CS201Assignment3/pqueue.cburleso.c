#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.cburleso.h"

// This will put the data in the priority queue in the correct place. If there is already one or more nodes in the list
// having the same priority as the data that you are enqueueing, then put the new node after all of the nodes having
// that priority. Return zero from this function.

int enqueue(PQueueNode **pqueue, int priority, void *data) {
    PQueueNode *currNode, *prevNode, *newNode;

    // If list is empty the new node will be the first node
    if (*pqueue == NULL) {
        newNode = (PQueueNode *) malloc(sizeof(PQueueNode));
        newNode->priority = priority;
        newNode->data = data;
        newNode->next = NULL;
        *pqueue = newNode;
        return(0);
    }

    currNode = *pqueue;
    prevNode = NULL;
    // While other nodes within the queue are less than or equal to the priority
    while (currNode != NULL && currNode->priority <= priority) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Allocate a new pqueue node pointing to the provided data argument
    newNode = (PQueueNode *) malloc(sizeof(PQueueNode));
    newNode->priority = priority;
    newNode->data = data;
    newNode->next = currNode;

    if (prevNode != NULL)
        prevNode->next = newNode;
    else
        *pqueue = newNode;

    return(0);
}

// Remove the front of the list and return the data from that list node (not the list node itself). If the pqueue is
// empty, then return NULL.

void *dequeue(PQueueNode **pqueue){

    PQueueNode *temp;
    temp = *pqueue;
    StudentRecord *data;

    // Check if list is empty, if so return NULL
    if (*pqueue == NULL) {
        return NULL;
    } else { // Delete the front of the list and return data from first node
        data = temp->data;
        *pqueue = temp->next;
        free(temp);
        return data;
    }

}

// Return the data from the ﬁrst node in the pqueue (not the node itself). If the pqueue is empty, then return NULL.
// The peek operation does not actually remove a node from the pqueue!

void *peek(PQueueNode *pqueue){
    PQueueNode *node;
    node = pqueue;
    // Check if list is empty, if so return NULL
    if (node == NULL) {
        return NULL;
    } else {
        return node->data;
    }
}

// Print the data from each node in the queue.
int printQueue(PQueueNode *pqueue, void (printStudentRecord)(void*)){
    PQueueNode *node;
    node = pqueue;
    while (node != NULL) {
        printf("priority = %d data = ", node->priority);
        printStudentRecord(node->data);
        node = node->next;
    }
}

// Return the priority of the ﬁrst node in the pqueue. If the pqueue is empty, return -1.
int getMinPriority(PQueueNode *pqueue){
    PQueueNode *node;
    node = pqueue;
    // Check if list is empty, if so return -1
    if (node == NULL) {
        return (-1);
    } else {
        return node->priority; // Return the priority of the first node in the queue
    }

}

// Return the number of nodes in the pqueue.
int queueLength(PQueueNode *pqueue){
    int numNodes = 0;
    PQueueNode *currNode;
    currNode = pqueue;
    while (currNode != NULL) {
        numNodes = numNodes + 1;
        currNode = currNode->next;
    }

    // Return the total number of nodes
    return numNodes;

}
// Print an instance of StudentRecord as "%s %d", with the name ﬁeld and id ﬁeld.
void printStudentRecord(void *data) {
    StudentRecord *node = (StudentRecord *) data;
    printf("%s %d\n", node->name, node->id);
}

