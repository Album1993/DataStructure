//
//  main.c
//  MergeLinkList
//
//  Created by akka on 16/7/4.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include "MergeList.h"
void PrintElem(LElemType_L e);
int main(int argc, const char * argv[]) {
    // insert code here...
    
    FILE * fp;
    LinkList La,Lb,Lc;
    int m;
    m = 5;
    fp = fopen("/Users/akka/DataStructure/SinglelyLinkedList/SinglelyLinkedList/TestData_HL.txt", "r");
    CreateList_HL(fp, &La, m);
    fclose(fp);
    
    fp = fopen("/Users/akka/DataStructure/SinglelyLinkedList/SinglelyLinkedList/TestData_TL.txt", "r");
    CreateList_TL(fp, &Lb, m);
    fclose(fp);
    
    printf("la = \n");
    ListTraverse_L(La, PrintElem);
    
    printf("lb = \n");
    ListTraverse_L(Lb, PrintElem);
    
    MergeList_L(La, &Lb, &Lc);
    
    printf("合并la和lb = \n");
    
    ListTraverse_L(Lc, PrintElem);
    
    return 0;
}

void PrintElem(LElemType_L e) {
    printf("%d\n",e);
}