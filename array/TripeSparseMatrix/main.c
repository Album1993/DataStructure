//
// Created by akka on 16/9/2.
//

#include <stdio.h>
#include "TripleSparseMatrix.h"

int main(int argc, char **argv) {
    TSMatrix M,N;
    FILE *fp;
    printf("创建两个稀疏矩阵\n");
    fp =  fopen("/Users/akka/DataStructure/array/TripeSparseMatrix/TestData.txt","r");
    CreateSMatrix_T(fp,2,&M,&N);
    fclose(fp);
    printf("\n");

    printf("M = \n");
//
    PrintSMatrix_T(M);
    printf("N = \n");
    PrintSMatrix_T(N);

    printf("\n");

    TSMatrix Tmp;
    printf("copy matrix to tmp\n");
//
    CopySMatrix_T(M, &Tmp);
//
    printf("Tmp = \n");
    PrintSMatrix_T(Tmp);
    printf("\n");

    TSMatrix Q1;
    AddMatri_T(M,N,&Q1);
    printf("Q1 = M + N = \n");
    PrintSMatrix_T(Q1);
//
    TSMatrix Q2;
    SubSMatrix(M,N,&Q2);
    printf("Q2 = M - N = \n");
    PrintSMatrix_T(Q2);
    printf("\n");

    TSMatrix Q3;
    MultiSMatrix(M,N,&Q3);
    printf("Q3 = M * N = \n");
    PrintSMatrix_T(Q3);
    printf("\n");

    TSMatrix T1 ;
    TransposeSMatrix(M,&T1);
    printf("T1 = M(T) = \n");
    PrintSMatrix_T(T1);
    printf("\n");

    TSMatrix T2;
    FastTransposeSMatrix_T(M,&T2);
    printf("T2 = M(T) = \n");
    PrintSMatrix_T(T2);
    printf("\n");

    return 0;
}