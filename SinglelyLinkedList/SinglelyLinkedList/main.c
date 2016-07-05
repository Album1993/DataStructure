//
//  main.c
//  SinglelyLinkedList
//
//  Created by akka on 16/7/1.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include "SinglyLinkedList.h"

Status CmpGreater(LElemType_L e,LElemType_L data);
void PrintElem(LElemType_L e);

int main(int argc, const char * argv[]) {
    
    LinkList L;
    int i;
    LElemType_L e;
    
    InitList_L(&L);
    printf("初始化\n");
    
    ListEmpty_L(L) ? printf("L 为空\n") : printf("L 不为空\n");
    
    for (i = 1; i<=6; i++) {
        printf("在L的第%d个位置插入:%d\n",i,2*i);
        ListInsert_L(L, i, 2*i);
    }
    
    printf("遍历L\n");
    ListTraverse_L(L, PrintElem);
    
    printf("L的长度为:%d\n",ListLength_L(L));
    
    ListDelete_L(L, 3, &e);
    
    printf("删除L中第3个元素为：%d\n",e);
    
    printf("遍历L\n");
    ListTraverse_L(L, PrintElem);
    
    GetElem_L(L, 4, &e);
    printf("获得L中第4个元素为：%d\n",e);

    i = LocateElem_L(L, 7, CmpGreater);
    
    printf("L中第一个大于7的元素位置为：%d\n",e);
    
    NextElem_L(L, 10, &e);
    printf("10的后继：%d\n",e);
    
    printf("CreateList_HL\n");
    {
        FILE * fp;
        LinkList L;
        printf("头插法建立链表L = ");
        fp = fopen("/Users/akka/DataStructure/SinglelyLinkedList/SinglelyLinkedList/TestData_HL.txt", "r");
        CreateList_HL(fp, &L, 5);
        fclose(fp);
        ListTraverse_L(L, PrintElem);
        printf("\n");
    }
    
    printf("CreateList_TL\n");
    {
        FILE * fp;
        LinkList L;
        printf("尾插法建立链表L = ");
        fp = fopen("/Users/akka/DataStructure/SinglelyLinkedList/SinglelyLinkedList/TestData_TL.txt", "r");
        CreateList_TL(fp, &L, 5);
        fclose(fp);
        ListTraverse_L(L, PrintElem);
        printf("\n");
    }
    
    return 0;
}

Status CmpGreater(LElemType_L e,LElemType_L data) {
    return data > e ? TRUE:FALSE;
}

void PrintElem(LElemType_L e) {
    printf("%d\n",e);
}





