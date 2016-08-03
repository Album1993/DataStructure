//
// Created by akka on 16/8/3.
//

#include "ConversionN.h"

void conversioNum (int i) {
    SqStack S;
    SElemType_Sq e;

    InitList_Sq(&S);

    printf("十进制%d 转为八进制数后为: 0",i);

    while (i) {
        Push_sq(&S,i%8);
        i = i /8;
    }

    while (!StackEmpty_Sq(S)) {
        Pop_Sq(&S,&e);
        printf("%d",e);
    }
}
