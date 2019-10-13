//
// Created by CHBADMIN on 9/3/2019.
//

#include <stdio.h>
#include <string.h>
#include "warmup.cburleso.h"

int main(){
    // Part One Testing
    int userSum;
    int userDifference;
    int answer = addSubtract(1, 2, &userSum, &userDifference);
    printf("The answer to Part One is %d", answer);

    // Part Two Testing
    int id = 17;
    char *name = "Connor_Burleson";
    StudentData *record;
    int answer2 = createRecord(id, name, &record);
    printf("The answer to Part Two is %d", answer2);

    return 0;
}

