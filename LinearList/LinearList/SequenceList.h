//
//  SequenceList.h
//  LinearList
//
//  Created by akka on 16/6/30.
//  Copyright © 2016年 akka. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define LIST_INIT_SIZE 100 // init size of list
#define LISTINCREMENT  10  // crease size every time

#ifndef LELEMENTTYPE_SQ
#define LELEMENTTYPE_SQ
typedef int LElementType_Sq; // type of elements
#endif

typedef struct {
    LElementType_Sq * elem;
    int length;
    int listsize;
}SqList;

// init
Status InitList_Sq(SqList * L);

// clear
void ClearList_Sq (SqList * L);

// destkory
void DestoryList_Sq(SqList * L);

/**
 *  check if the list is empty
 *  查看是否为空
 *
 *  @param L
 *
 *  @return yes / no
 */
Status ListEmpty_Sq(SqList L);

// get the length of the list
// 数组长度
int ListLength_Sq(SqList L);

/**
 *  get the element in index
 *  查询
 *
 *  @param L
 *  @param i index
 *  @param e element
 *
 *  @return if success to get the element
 */
Status GetElem_Sq(SqList L,int i,LElementType_Sq *e);

/**
 *  get the first element's index which meet the comparison condition
 *  比较
 *
 *  @param L
 *  @param e       which to be compare
 *  @param Compare compare condition
 *
 *  @return index
 */
int LocateElem_Sq(SqList L,LElementType_Sq e,Status(Compare)(LElementType_Sq,LElementType_Sq));

/**
 *  prior element
 *  前驱
 *
 *  @param L
 *  @param cur_e the element which to query
 *  @param pre_e the element prior to the quaried element
 *
 *  @return success / failure
 */
Status PriorElem_Sq(SqList L,LElementType_Sq cur_e,LElementType_Sq *pre_e);

/**
 *  next element
 *  后继
 *
 *  @param L
 *  @param cur_e
 *  @param next_e
 *
 *  @return
 */
Status NextElem_Sq(SqList L,LElementType_Sq cur_e,LElementType_Sq *next_e);

// insert
// 插入
Status ListInsert_Sq(SqList *L,int i ,LElementType_Sq e);

// delete
// 删除
Status ListDelete_sq(SqList *L,int i ,LElementType_Sq *e);

/**
 *  iterate the list in certain rule
 *
 *  @param L
 *  @param visit rules
 *
 *  @return complete
 */
Status ListTraverse_Sq(SqList L,void(visit)(LElementType_Sq));

#endif /* SequenceList_h */
