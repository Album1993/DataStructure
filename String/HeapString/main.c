//
// Created by 张一鸣 on 16/8/11.
//


#include <stdio.h>
#include "HeapString.h"

int main(int argc, char **argv)
{
    char *chars = "abcdefg";

    char * t = "***";

    char * v = "^^^^";

    HString S,Tmp,T,V,Sub;

    int i;

    printf("初始化空串");

    InitString_H(&Tmp);

    printf("\n");

    StrAssign_H(&Tmp,chars);

    printf("\n");

    i = StrLength_H(Tmp);

    printf("Tmp 's length is :%d\n",i);

    printf("Tmp's element is");

    StrPrint_H(Tmp);

    printf("\n");

    return 0;
}