//
// Created by akka on 16/7/25.
//

#ifndef EXTENEDLINKEDLIST_EXTENEDLINKEDLIST_H
#define EXTENEDLINKEDLIST_EXTENEDLINKEDLIST_H

#include <stdlib.h>
#include "Status.h"
#include "Scanf.c"

#ifndef POLYNOMTAL_H
typedef int LElemType_E;
#endif

typedef struct ELNode
{
    LElemType_E data;
    struct ELNode *next;
}ELNode;
typedef ELNode* Link;
typedef ELNode* PositionPtr;

typedef  struct
{
    Link head,tail;
    int len;
}ELinkList;

Status MakeNode_E(Link *p,LElemType_E e);

void FreeNode_E(Link *p);

Status InitList_E(ELinkList *L);

void ClearList_E(ELinkList *L);

void DestroyList_E(ELinkList *L,Link h,Link s);

void InsFirst_E(ELinkList *L,Link h,Link s);

Status 



#endif //EXTENEDLINKEDLIST_EXTENEDLINKEDLIST_H
