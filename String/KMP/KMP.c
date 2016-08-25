//
// Created by akka on 16/8/17.
//

#include "KMP.h"


int Index_KMP(SString S,SString T, int pos, int next[]) {
    int i = pos;
    int j = 1;

    if (pos < 1)
        return 0;

    while (i <= S[0] && j<=T[0]) {
        if (S[i] == T[j] || j == 0) {
            i++;
            j++;
        } else
            j = next[j];
    }

    if (j>T[0])
        return i - T[0];
    else
        return 0;
}

void get_next(SString T, int next[]) {
    int i = 1;
    printf("------------next\n");
    printf("i : %d\n",i);
    int j = 0;
    printf("j : %d\n",j);
    next[1] = 0;

    for (int k = 1 ; k <= 1; ++k) {
        printf("next[%d]:%d\n",i,next[i]);
    }

    while (i < T[0]) {
        printf("T[%d] :%d T[%d] : %d\n",i,T[i],j,T[j]);
        if (T[i] == T[j] || !j) {
            i++;
            j++;
            printf("i : %d\n",i);
            printf("j : %d\n",j);
            next[i] = j;
            for (int k = 1 ; k <= i; ++k) {
                printf("next[%d]:%d\n",k,next[k]);
            }
        } else{
            printf("get next value in j:%d\n",j);
            j = next[j];
        }

        printf("j : %d\n",j);
    }
}

void get_nextval(SString T, int nextval[]) {
    int i = 1;
    int j = 0;
    nextval[1] = 0;
    while (i < T[0]) {
        if (T[i] == T[j] || !j) {
            i++;
            j++;
            if (T[i] != T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];

        }
        else
            j = nextval[j];
    }
}
