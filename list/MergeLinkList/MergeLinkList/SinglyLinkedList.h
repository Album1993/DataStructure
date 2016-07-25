//
//  SinglyLinkedList.h
//  SinglelyLinkedList
//
//  Created by akka on 16/7/3.
//  Copyright © 2016年 akka. All rights reserved.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include <stdio.h>
#include <stdlib.h>

#include "Status.h"
//#include "Scanf.c"

#ifndef BANKQUEUING_H

typedef int LElemType_L;

typedef struct LNode {
    LElemType_L data;
    struct LNode * next;
}LNode;

typedef LNode * LinkList;

#endif

Status InitList_L(LinkList *L);

Status ClearList_L(LinkList L);

void DestoryList_L(LinkList *L);

Status ListEmpty_L(LinkList L);

int ListLength_L(LinkList L);

Status GetElem_L(LinkList L,int i,LElemType_L *e);

int LocateElem_L(LinkList L,LElemType_L e,Status(Compare)(LElemType_L,LElemType_L));

Status PriorElem_L(LinkList L,LElemType_L cur_e,LElemType_L *pre_e);

Status NextElem_L(LinkList L,LElemType_L cur_e,LElemType_L *next_e);

Status ListInsert_L(LinkList L,int i,LElemType_L e);

Status ListDelete_L(LinkList L,int i,LElemType_L *e);

Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L));

Status CreateList_HL(FILE *fp,LinkList *L,int n);

Status CreateList_TL(FILE *fp,LinkList *L,int n);


#endif /* SinglyLinkedList_h */
