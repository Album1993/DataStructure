//
// Created by 张一鸣 on 16/8/10.
//

#include <stdio.h>
#include "SequenceString.h"

int main(int argc, char ** argv) {
    char * chars = "abcdefg";
    char  *t = "***";
    char *v = "^^^^^^^^^";
    SString S,Tmp,T,V,Sub;

    int i;

    printf("TMP get the value\n");

    StrAssign_Sq(Tmp,chars);

    i = StrLength_Sq(Tmp);

    printf("length of the string is %d\n",i);

    printf("tmp is :");

    StrPrint_Sw(Tmp);

    return 0;
}