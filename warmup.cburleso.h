//
// Created by Connor Burleson on 9/3/2019.
//

#ifndef CS201ASSIGNMENT1_WARMUP_CBURLESO_H
#define CS201ASSIGNMENT1_WARMUP_CBURLESO_H

// Part One Function
int addSubtract(int n1, int n2, int *sum, int *difference);

// Part Two StudentData Struct Definition
typedef struct {
    char name[32];
    int id;
} StudentData;

// Part Two Function
int createRecord(int id, char *name, StudentData **record);

#endif //CS201ASSIGNMENT1_WARMUP_CBURLESO_H
