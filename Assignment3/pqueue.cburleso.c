#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.cburleso.h"

int insertStudent(StudentListNode **list, int id, char *name) {
    StudentListNode *currNode, *prevNode, *newNode;

    if (*list == NULL) {
        // list is empty: this will become the first node
        newNode = (StudentListNode *) malloc(sizeof(StudentListNode));
        newNode->id = id;
        strcpy(newNode->name, name);
        newNode->next = NULL;
        *list = newNode;
        return(0);
    }

    // list not empty: is a record with id already in the list?
    currNode = *list;
    prevNode = NULL;
    while ( currNode != NULL && id > currNode->id ) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode != NULL) {
        // found a matching record in the list
        if (currNode->id == id)
            return(1);
    }

    // insert before currNode

    newNode = (StudentListNode *) malloc(sizeof(StudentListNode));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = currNode;

    if (prevNode != NULL)
        prevNode->next = newNode;
    else
        *list = newNode;

    return(0);
}

//=====================================================================

int printList(StudentListNode *list) {
    StudentListNode *node;
    if (list == NULL)
        printf("(list is empty)\n");
    else {
        node = list;
        while (node != NULL) {
            printf("%d |%s|\n", node->id, node->name);
            node = node->next;
        }
    }

    return(0);
}

//=====================================================================

int findStudent(StudentListNode *list, int id, char *name) {
    StudentListNode *currNode;
    if (list == NULL)
        return(1);

    currNode = list;
    while (currNode != NULL && id > currNode->id) {
        currNode = currNode->next;
    }

    if (currNode == NULL)
        return(1);

    if (id < currNode->id)
        return(1);

    strcpy(name, currNode->name);
    return(0);
}

//=====================================================================

int deleteStudent(StudentListNode **list, int id) {
    StudentListNode *currNode, *prevNode;
    if (*list == NULL)
        return(1);

    prevNode = NULL;
    currNode = *list;
    while (currNode != NULL && id > currNode->id) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL)
        return(1);

    if (id < currNode->id)
        return(1);

    // delete currNode
    if (prevNode != NULL)
        prevNode->next = currNode->next;
    else
        *list = currNode->next;

    free(currNode);
    return(0);
}
