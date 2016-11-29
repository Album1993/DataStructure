//
// Created by 张一鸣 on 2016/9/27.
//

#include "stdio.h"
#include "CrossList.h"
int main () {
    CrossList M,N;

    FILE * fp;
    fp = fopen("/Users/zhangyiming/code/DataStructure/array/CrossList/TestData.txt","r");
    CreateSMatrix_OL(fp,2,&M,&N);

    fclose(fp);
    printf("\n");

    printf("M = \n");
    PrintSMatrix_OL(M);
    printf("N = \n");
    PrintSMatrix_OL(N);

    CrossList Tmp;
    CopySMatrix_OL(M,&Tmp);

    printf("Tmp = \n");
    PrintSMatrix_OL(Tmp);
    printf("\n");

    CrossList Q1;
    AddSMatrix_OL(M,N,&Q1);
    printf("Q1 = M + N = \n");
    PrintSMatrix_OL(Q1);
    printf("\n");

    CrossList Q2;
    SubSMatrix_OL(M,N,&Q2);
    printf("Q2 = M -N = \n");
    PrintSMatrix_OL(Q2);
    printf("\n");

    CrossList Q3 ;
    MultiSMatrix_OL(M,N,&Q3);
    printf("Q3 = M * N = \n");
    PrintSMatrix_OL(Q3);
    printf("\n");

    CrossList T;
    TransposeSMatrix_OL(M,&T);
    printf("T = M(T) = \n");
    PrintSMatrix_OL(T);
    printf("\n");

    return 0;

}