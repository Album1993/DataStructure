//
// Created by 张一鸣 on 16/9/17.
//

#ifndef CROSSLIST_CROSSLIST_H
#define CROSSLIST_CROSSLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Status.h"

typedef int CELemType;
typedef struct OLNode
{
    int i,j;
    CELemType e;
    struct OLNode *right;
    struct OLNode *down;
}OLNode;

typedef OLNode *OLink;

typedef struct
{
    OLink * rhead;
    OLink * chead;
    int mu,nu,tu;
}CrossList;

Status CreateSMatrix_OL(FILE *fp, int n,...);

void DestorySMatrix_OL(CrossList *M);

void PrintSMatrix_OL(CrossList M);

void CopySMatrix_OL(CrossList M,CrossList *T);

Status AddSMatrix_OL(CrossList M,CrossList N,CrossList *Q);

Status SubSMatrix_OL(CrossList M,CrossList N,CrossList *Q);

Status MultiSMatrix_OL(CrossList M,CrossList N,CrossList *Q);

void TransposeSMatrix_OL(CrossList M,CrossList *T);

#endif //CROSSLIST_CROSSLIST_H
