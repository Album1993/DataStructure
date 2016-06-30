//
//  main.c
//  LinearList
//
//  Created by akka on 16/6/30.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include "SequenceList.h"

Status CmpGreater(LElementType_Sq e,LElementType_Sq data);
void PrintElem(LElementType_Sq e);

int main(int argc, const char * argv[]) {
    
    SqList L;
    LElementType_Sq e;
    
    printf("init the list\n");
    
    InitList_Sq(&L);
    
    ListEmpty_Sq(L) ? printf("list is empty\n") : printf("list is not empty\n");
    
    for (int i = 1; i <= 6; i++) {
        printf("insert (%d) into list[%d]\n",i * 3,i-1);
        ListInsert_Sq(&L, i, 3*i);
    }
    
    printf("print the list\n");
    ListTraverse_Sq(L, PrintElem);
    
    printf("print the length of list:%d\n",ListLength_Sq(L));
    
    printf("delete the element when index is equal to 2\n");
    ListDelete_sq(&L, 2, &e);
    printf("the deleted is :%d\n",e);
    
    printf("print the list\n");
    ListTraverse_Sq(L, PrintElem);
    
    GetElem_Sq(L, 2, &e);
    printf("print the list[2] :%d\n",e);

    e = LocateElem_Sq(L, 15, CmpGreater);
    
    printf("15 is in :%d\n",e);
    
    NextElem_Sq(L, 15, &e);
    
    printf("15's next is :%d\n",e);
    
    PriorElem_Sq(L, 15, &e);
    printf("15's prior is :%d\n",e);
    
    return 0;
}

Status CmpGreater(LElementType_Sq e,LElementType_Sq data) {
    return data>e ? TRUE : FALSE;
}

void PrintElem(LElementType_Sq e) {
    printf("%d \n",e);
}