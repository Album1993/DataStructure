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
    L = malloc(sizeof(SqList));
    L->elem = malloc(sizeof(LElementType_Sq) * LISTINCREMENT);
    if (!L->elem )
        return ERROR;
    L->length = 0;
    L->listsize = LISTINCREMENT;

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
    (*L).listsize = 0;
    (*L).length = 0;
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
    if (i < 1 || i > L.length) {
        return ERROR;
    }

    *e = L.elem[i-1];

    return OK;

}

/**
 *  get the first element's index which meet the comparison condition
 *  比较
 */
int LocateElem_Sq(SqList L,LElementType_Sq e,Status(Compare)(LElementType_Sq,LElementType_Sq)) {
    if (L.length == 0 )
        return 0;

    int i = 0 ;

    while (!Compare(L.elem[i],e) && i <= L.length ) {
        i++;
    }

    if (i < L.length )
    {

        return i+1;
    }
    else
        return 0;

}

/**
 *  prior element
 *  前驱
 */
Status PriorElem_Sq(SqList L,LElementType_Sq cur_e,LElementType_Sq *pre_e) {
    int  i = L.length-1;

    while (i > 0 && L.elem[i] != cur_e) {
        i--;
    }

    if (i > 0 )
    {
        *pre_e = L.elem[i-1];
        return OK;
    }
    return ERROR;
}

/**
 *  next element
 *  后继
 */
Status NextElem_Sq(SqList L,LElementType_Sq cur_e,LElementType_Sq *next_e) {
    int i = 0;
    while (i < L.length - 1 && L.elem[i] != cur_e) {
        i++;
    }
    if (i < L.length) {
        *next_e = L.elem[i+1];
        return OK;
    }

    return ERROR;

}

// insert
// 插入
Status ListInsert_Sq(SqList *L,int i ,LElementType_Sq e) {

    if (i < 1 || i > L->length + 1)
        return ERROR;

    if (L->length >= L->listsize)
    {
        L->listsize += LISTINCREMENT;
        L->elem = realloc(L->elem , sizeof(LElementType_Sq) * L->listsize);
    }

    LElementType_Sq * p , * q;
    p = &L->elem[L->length-1];
    q = &L->elem[i - 1];

    for (p ; p >= q ; p--) {
        *(p+1) = *(p);
    }
    *q = e;
    return OK;
}

// delete
// 删除
Status ListDelete_sq(SqList *L,int i ,LElementType_Sq *e) {

    if (i < 1 || i > L->length) {
        return ERROR;
    }

    LElementType_Sq  * p, * q;
    p = &L->elem[L->length - 1];
    q = &L->elem[i-1];
    *e = *q;

    for (q ; q < p ; q++) {
        *q = *(q+1);
    }
    free(*p);

}

/**
 *  iterate the list in certain rule
 */
Status ListTraverse_Sq(SqList L,void(visit)(LElementType_Sq)) {
    for (int i = 0; i < L.length; ++i) {
        printf("%d ",L.elem[i]);
    }
}
