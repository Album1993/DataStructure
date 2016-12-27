//
// Created by 张一鸣 on 2016/12/26.
//

#include <stdlib.h>
#include <stdio.h>
#include "SequenceList.h"

Status CmpGreater(LElementType_Sq e, LElementType_Sq data);
void PrintElem(LElementType_Sq e);

int main(int argc, char ** argb) {
    SqList L;
    int i;
    LElementType_Sq e;

    InitList_Sq(&L);

    ListEmpty_Sq(L) ? printf("empty\n") : printf("not empty\n");

    for (i = 1; i <= 6 ; ++i) {
        printf("insert %d into %d\n" ,2 * i, i);
        ListInsert_Sq(&L,i, 2 * i);
    }

    ListTraverse_Sq(L,PrintElem);
    printf("\n");

    i = ListLength_Sq(L);

    printf("length is %d\n",i);

    ListDelete_sq(&L,6,&e);

    printf("delete item in 6 :%d\n",e);

    GetElem_Sq(L,4,&e);

    printf("the item at index 4 is : %d\n",e);

    i = LocateElem_Sq(L,7,CmpGreater);

    printf("the elem greater than 7 is :%d\n",i);

    PriorElem_Sq(L,6,&e);
    printf("elem 6 's prior is :%d \n",e);

    NextElem_Sq(L,6,&e);
    printf("elem 6's next is :%d",e);
}

Status CmpGreater(LElementType_Sq e, LElementType_Sq data) {
    return data > e ? TRUE : FALSE;
}

void  PrintElem(LElementType_Sq e) {
    printf("%d ",e);
}