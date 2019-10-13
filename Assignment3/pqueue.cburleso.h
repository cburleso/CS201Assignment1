//
// Created by CHBADMIN on 9/27/2019.
//

#ifndef ASSIGNMENT3_PQUEUE_CBURLESO_H
#define ASSIGNMENT3_PQUEUE_CBURLESO_H

typedef struct StudentListNodeStruct {
    int id;
    char name[32];
    struct StudentListNodeStruct *next;
} StudentListNode;

int insertStudent(StudentListNode **list, int id, char *name);
int findStudent(StudentListNode *list, int id, char *name);
int deleteStudent(StudentListNode **list, int id);
int printList(StudentListNode *list);


#endif //ASSIGNMENT3_PQUEUE_CBURLESO_H
