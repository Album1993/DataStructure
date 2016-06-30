//
//  SequenceList.c
//  LinearList
//
//  Created by akka on 16/6/30.
//  Copyright © 2016年 akka. All rights reserved.
//

#include "SequenceList.h"



// init
Status InitList_Sq(SqList * L) {
    (*L).elem = (LElementType_Sq*) malloc(LIST_INIT_SIZE*sizeof(LElementType_Sq));
    if (!(*L).elem)
        exit(OVERFLOW);
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return OK;
}

// clear
void ClearList_Sq (SqList * L) {
    (*L).length = 0;
}

// destkory
void DestoryList_Sq(SqList * L) {
    free((*L).elem);
    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listsize = 0;
}

/**
 *  check if the list is empty
 *  查看是否为空
 */
Status ListEmpty_Sq(SqList L) {
    return L.length == 0 ? TRUE : FALSE;
}

// get the length of the list
// 数组长度
int ListLength_Sq(SqList L) {
    return L.length;
}

/**
 *  get the element in index
 *  查询
 */
Status GetElem_Sq(SqList L,int i,LElementType_Sq *e) {
    if (i<1 || i>L.length) {
        return ERROR;
    } else {
        *e = L.elem[i-1];
    }
    return OK;
}

/**
 *  get the first element's index which meet the comparison condition
 *  比较
 */
int LocateElem_Sq(SqList L,LElementType_Sq e,Status(Compare)(LElementType_Sq,LElementType_Sq)) {
    int i = 1;
    while (i<=L.length && !Compare(e,L.elem[i-1])) {
        ++i;
    }
    if (i <= L.length) {
        return i;
    } else
        return 0;
}

/**
 *  prior element
 *  前驱
 */
Status PriorElem_Sq(SqList L,LElementType_Sq cur_e,LElementType_Sq *pre_e) {
    int i = 1;
    if (L.elem[0]!=cur_e) {
        while (i < L.length & L.elem[i]!=cur_e) {
            ++i;
        }
        
        if (i < L.length) {
            * pre_e = L.elem[i-1];
            return OK;
        }
    }
    return ERROR;
}

/**
 *  next element
 *  后继
 */
Status NextElem_Sq(SqList L,LElementType_Sq cur_e,LElementType_Sq *next_e) {
    int i = 0;
    while (i<L.length && L.elem[i]!=cur_e) {
        ++i;
    }
    if (i < L.length - 1) {
        *next_e = L.elem[i+1];
        return OK;
    }
    return ERROR;
}

// insert
// 插入
Status ListInsert_Sq(SqList *L,int i ,LElementType_Sq e) {
    LElementType_Sq * newbase;
    LElementType_Sq *p,*q;
    
    if (i<1 || i>(*L).length + 1) {
        return ERROR;
    }
    
    if ((*L).length >= (*L).listsize) {
        newbase = (LElementType_Sq *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT)*sizeof(LElementType_Sq));
        if (!newbase) {
            exit(OVERFLOW);
        }
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    
    q = &(*L).elem[i-1];
    
    for (p = &(*L).elem[(*L).length-1]; p>=q; --p) {
        *(p+1) = *p;
    }
    
    *q = e;
    (*L).length ++;
    return OK;
}

// delete
// 删除
Status ListDelete_sq(SqList *L,int i ,LElementType_Sq *e) {
    LElementType_Sq *p,*q;
    if (i <1 || i>(*L).length) {
        return ERROR;
    }
    
    p = &(*L).elem[i-1];
    *e = *p;
    q = (*L).elem+(*L).length-1;
    
    for (++p;p<=q; ++p) {
        *(p-1) = *p;
    }
    
    (*L).length --;
    return OK;
    
}

/**
 *  iterate the list in certain rule
 */
Status ListTraverse_Sq(SqList L,void(visit)(LElementType_Sq)) {
    int i;
    for (i=0; i<L.length; i++) {
        visit(L.elem[i]);
    }
    return OK;
}
