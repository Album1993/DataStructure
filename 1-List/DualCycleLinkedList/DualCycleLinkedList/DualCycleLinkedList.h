//
//  DualCycleLinkedList.h
//  DualCycleLinkedList
//
//  Created by akka on 16/7/9.
//  Copyright © 2016年 akka. All rights reserved.
//

#ifndef DualCycleLinkedList_h
#define DualCycleLinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

typedef int lElemType_DC;
typedef struct DuLNode {
    lElemType_DC data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode;

typedef DuLNode *DuLinkList;

Status InitList_DuL(DuLinkList *L);

Status ClearList_DuL(DuLinkList L);

void DestroyList_DuL(DuLinkList *L);

Status ListEmpty_DuL(DuLinkList L);

int ListLength_DuL(DuLinkList L);

Status GetElem_DuL(DuLinkList L,int i,lElemType_DC *e);

int LocateElem_DuL(DuLinkList L,lElemType_DC e,Status(Compare)(lElemType_DC,lElemType_DC));

Status PriorElem_DuL(DuLinkList L,lElemType_DC cur_e,lElemType_DC *pre_e);

Status NextElem_DuL(DuLinkList L,lElemType_DC cur_e,lElemType_DC *next_e);

DuLinkList GetElemPtr_DuL(DuLinkList l,int i);

Status ListInsert_DuL(DuLinkList L,int i,lElemType_DC e);

Status ListDelete_DuL(DuLinkList L,int i,lElemType_DC *e);

void ListTraverse_DuL(DuLinkList L,void(Visit)(lElemType_DC));

#endif /* DualCycleLinkedList_h */




































