//
// Created by Connor Burleson on 9/3/2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "warmup.cburleso.h"

// Part One Function
int addSubtract(int n1, int n2, int *sum, int *difference){
    *sum = n1 + n2; // Declare the integer pointer sum with n1 + n2
    *difference = n1 - n2; // Declare the integer pointer difference with n1 - n2
    if (n1 > n2){ // CONDITIONS: if n1 > n2, return 1, if n1 = n2, return 0, otherwise return -1
        return 1;
    } else if (n1 == n2){
        return 0;
    } else {
        return -1;
    }
}

// Part Two Function
int createRecord(int id, char *name, StudentData **record){
    if (strlen(name) > 31 || id <= 0){ // If the name is > 31 characters long or the id is <= 0, return 1 and
        *record = NULL; // Pass a NULL through the record parameter
        return 1;

    } else {
        StudentData *newStudent; // Malloc a new StudentData struct
        newStudent = (StudentData *) malloc(sizeof(StudentData));
        (*newStudent).id = id; // Assign ID of new StudentData struct to the given ID parameter
        strcpy(newStudent->name, name); // Set the name field of the StudentData struct to the given name parameter
        *record = newStudent; // Pass a pointer to the memory previously malloc'd
        return 0;
    }
}
