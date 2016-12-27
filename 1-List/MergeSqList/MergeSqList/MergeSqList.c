//
//  MergeSqList.c
//  MergeSqList
//
//  Created by akka on 16/7/1.
//  Copyright © 2016年 akka. All rights reserved.
//

#include "MergeSqList.h"
#include "Status.h"
void MergeSqList_1(SqList La,SqList Lb,SqList *Lc) {
    int La_len,Lb_len;
    int i,j,k;
    LElementType_Sq ai,bj;
    
    i = j = 1;
    
    k = 0;
    
    InitList_Sq(Lc);
    
    La_len = ListLength_Sq(La);
    Lb_len = ListLength_Sq(Lb);
    
    while (i <= La_len && j <= Lb_len) {
        GetElem_Sq(La, i, &ai);
        GetElem_Sq(Lb, j, &bj);
        if (ai < bj) {
            ListInsert_Sq(Lc, ++k, ai);
            i++;
        } else {
            ListInsert_Sq(Lc, ++k, bj);
            j++;
        }
    }
    
    while (i<=La_len) {
        GetElem_Sq(La, i++, &ai);
        ListInsert_Sq(Lc, ++k, ai);
    }
    
    while (j<=Lb_len) {
        GetElem_Sq(Lb, j++, &bj);
        ListInsert_Sq(Lc, ++k, bj);
    }
}

void MergeSqList_2(SqList La,SqList Lb,SqList *Lc) {
    LElementType_Sq *pa,*pb,*pc;
    LElementType_Sq *pa_last,*pb_last;
    
    pa = La.elem;
    pb = Lb.elem;
    
    (*Lc).listsize = (*Lc).length = La.length + Lb.length;

    pc = (*Lc).elem = (LElementType_Sq *)malloc((*Lc).listsize*sizeof(LElementType_Sq));
    if (!pc) {
        exit(OVERFLOW);
    }
    
    pa_last = La.elem + La.length -1;
    pb_last = Lb.elem + Lb.length -1;
    
    while (pa<=pa_last && pb<pb_last) {
        if (*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
    
}















