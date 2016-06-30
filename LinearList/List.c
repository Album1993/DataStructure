//
//  List.c
//  LinearList
//
//  Created by akka on 16/6/29.
//  Copyright © 2016年 akka. All rights reserved.
//

#define N 10
#include <stdlib.h>
#include "List.h"
struct lista{
    int cursor;
    int element[N];
};

Lista * GlobalList(void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->cursor = 0;
    return l;
}

void inserir(Lista * l ,int e){
    if (l == NULL || l->cursor == N) {
        printf("list was empty");
    } else {
        l->element[l->cursor++] = e;
    }
}

int remover(Lista * l,int e) {
    int i,d = inqueryr(l, e);
    if (d != -1) {
        for(i = d; i < l->cursor; i++)
        {
            l->element[i] = l->element[i+1];
        }
        l->cursor--;
        return 1;
    }
    return 0;
}

int inqueryr(Lista * l,int e) {
    if (l == NULL)
        return 0;
    int i = 0;
    while (i <= l->cursor && l->element[i]!=e) {
        i++;
    }
    return i > l->cursor ? -1 : i;
}

void printer(Lista * l) {
    int i = 0;
    for (i = 0; i < l->cursor; i++) {
        printf("%d ", l->element[i]);
    }
    printf("\n");
}

int empty(Lista *l) {
    return l->cursor == 0;
}

void destory(Lista *l) {
    free(l);
}








