//
// Created by akka on 16/9/11.
//


#include <stdio.h>
#include "RowLinkSparseMatrix.h"

int main(int argc, char **argv) {
    RLSMatrix M,N;

    FILE *fp;

    printf("create two matrix\n");

    fp = fopen("/Users/akka/DataStructure/array/RowLinkSparseMatrix/TestData.txt","r");

    CreateSMatrix_RL(fp,2,&M,&N);

    fclose(fp);
    printf("\n");

    printf("M = \n");
    PrintSMatrix_RL(M);
    printf("\n");
    printf("N = \n");
    PrintSMatrix_RL(N);
    printf("\n");

    RLSMatrix Q1;
    AddSMatrix_RL(M,N,&Q1);

    printf("Q1 = M + N = \n");
    PrintSMatrix_RL(Q1);

    printf("\n");

    RLSMatrix Q2;
    SubSMatrix_RL(M,N,&Q2);
    printf("Q2 = M - N = \n");
    PrintSMatrix_RL(Q2);
    printf("\n");

    RLSMatrix Q3;
    MultSMatrix_RL(M,N,&Q3);

    printf("Q3 = M * N = \n");
    PrintSMatrix_RL(Q3);
    printf("\n");


    RLSMatrix T1;
    TransposeSMatrix_RL(M,&T1);
    printf("T1 = M(T) = \n");
    PrintSMatrix_RL(T1);
    printf("\n");

    RLSMatrix T2;
    FastTransposeSMatrix_RL(M,&T2);
    printf("T2 = M(T) = \n");
    PrintSMatrix_RL(T2);
    printf("\n");

}
