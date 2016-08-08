//
//  SequenceStack.h
//  SequenceStack
//
//  Created by akka on 16/8/3.
//  Copyright © 2016年 akka. All rights reserved.
//

#ifndef SequenceStack_h
#define SequenceStack_h

#include <stdio.h>
#include <stdlib.h>

#include "Status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREASEMENT 10

#ifndef MAZEPROJECT_MAZE_H
typedef int SElemType_Sq;
#endif

typedef struct
{
    SElemType_Sq *base; // base 指向栈最后一个元素
    SElemType_Sq *top; // top 是指向栈顶的指针
    int stacksize;
}SqStack;

Status InitList_Sq(SqStack *S);

Status DestoryStock_Sq(SqStack *S);

Status ClearStack_Sq(SqStack *S);

Status StackEmpty_Sq(SqStack S);

int StackLength_Sq(SqStack S);

Status GetTop_Sq(SqStack s,SElemType_Sq *e);

Status Push_sq (SqStack *s,SElemType_Sq e);

Status Pop_Sq(SqStack *s,SElemType_Sq *e);

Status StackTraverse_Sq(SqStack s,void(Visit)(SElemType_Sq));

#endif /* SequenceStack_h */
