//
//  main.c
//  LinearListUnion
//
//  Created by akka on 16/7/1.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include "Union.h"

void PrintElem(LElementType_Sq e);

int main(int argc, const char * argv[]) {

    SqList La,Lb;
    
    LElementType_Sq a[5] = {5,1,2,3,9};
    LElementType_Sq b[7] = {7,2,3,12,51,23,21};
    
    InitList_Sq(&La);
    for (int i=0; i<5; i++) {
        ListInsert_Sq(&La, i+1, a[i]);
    }
    
    InitList_Sq(&Lb);
    for (int i = 0; i < 7;i++ ) {
        ListInsert_Sq(&Lb, i+1, b[i]);
    }
    
    printf("La:[");
    ListTraverse_Sq(La, PrintElem);
    printf("]\n");
   
    printf("Lb:[");
    ListTraverse_Sq(Lb, PrintElem);
    printf("]\n");
    
    printf("union:[");
    Union(&La, Lb);
    ListTraverse_Sq(La, PrintElem);
    printf("]\n\n");
    
    return 0;
}

void PrintElem(LElementType_Sq e) {
    printf("%d ",e);
}