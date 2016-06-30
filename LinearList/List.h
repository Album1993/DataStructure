//
//  List.h
//  LinearList
//
//  Created by akka on 16/6/29.
//  Copyright © 2016年 akka. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdio.h>

typedef struct lista Lista;

Lista * GlobalList (void);

void inserir(Lista * l,int e);

int remover(Lista * l,int e);

int inqueryr(Lista * l,int e);

void printer(Lista * l);

int empty(Lista * l);

void destory(Lista * l);

#endif /* List_h */
