//
//  main.c
//  MergeSqList
//
//  Created by akka on 16/7/1.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include "MergeSqList.h"

void PrintElem(LElementType_Sq e);

int main(int argc, const char * argv[]) {
    SqList La, Lb, Lc1,Lc2;
    LElementType_Sq a[4] = {3,5,6,11};
    LElementType_Sq b[7] = {2,3,4,8,14,16};
    int i;
    InitList_Sq(&La);
    for (i = 1; i<=4; i++) {
        ListInsert_Sq(&La, i, a[i-1]);
    }
    InitList_Sq(&Lb);
    for (i = 1; i<=6; i++) {
        ListInsert_Sq(&Lb, i, b[i-1]);
    }
    printf("La = ");
    ListTraverse_Sq(La, PrintElem);
    printf("\n");
    
    printf("Lb = ");
    ListTraverse_Sq(Lb, PrintElem);
    printf("\n");
    
    MergeSqList_1(La, Lb, &Lc1);
    
    printf("Lc1 = ");
    ListTraverse_Sq(Lc1, PrintElem);
    printf("\n");
    
    MergeSqList_1(La, Lb, &Lc2);
    
    printf("Lc2 = ");
    ListTraverse_Sq(Lc2, PrintElem);
    printf("\n");
    
    return 0;
}

void PrintElem(LElementType_Sq e) {
    printf("%d ",e);
}