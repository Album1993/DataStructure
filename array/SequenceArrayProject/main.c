//
// Created by akka on 16/8/25.
//

#include <stdio.h>
#include "SequenceArray.h"

int main(int argc , char ** argv) {
    Array A;

    printf(" init a array with 2 and 3..\n");
    InitArray(&A, 2,2,3);

    printf("\n");

    int i,j;

    AElemType_Sq e = 0;

    for (i = 0; i < A.bounds[0]; ++i) {
        for (j = 0; j < A.bounds[1]; ++j) {
            printf("assign :A[%d][%d] = %d \n",i,j,++e);
            AssignArray(&A,e,i,j);
        }
    }
    printf("\n");

    printf("A = ");
    ArrayPrint(A);
    printf("\n\n");
    return 0;
}