//
//  main.c
//  StaticLinkedList
//
//  Created by akka on 16/7/4.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include "StaticLinkedList.h"

void PrintElem(LElemType_S e);

int main(int argc, const char * argv[]) {
    // insert code here...
    SLinkList H;
    LElemType_S e;
    int i;
    
    printf("初始化静态链表的备用空间\n");
    InitSpace_SL();
    printf("\n");
    
    printf("初始化静态链表H,用Malloc_SL申请空间\n");
    InitList_SL(&H);
    
    ListEmpty_SL(H) ? printf("H 为空!!\n"):printf("H 不为空\n");
    
    for (i = 1; i<=6; i++) {
        printf("在H第%d个位置输入：%d\n",i,2*i);
        ListInsert_SL(H, i, 2*i);
    }
    
    printf("H 的长度为:%d",ListLength_SL(H));
    
    ListDelete_SL(H, 6, &e);
    
    printf("删除H中的第六个元素:%d\n",e);
    
    printf("H 的元素：\n");
    ListTraverse_SL(H, PrintElem);
    
    return 0;
}

void PrintElem(LElemType_S e) {
    printf("%d\n",e);
}