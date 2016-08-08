//
//  SequenceStack.c
//  SequenceStack
//
//  Created by akka on 16/8/3.
//  Copyright © 2016年 akka. All rights reserved.
//

#include "SequenceStack.h"

Status InitList_Sq(SqStack *S) {
    (*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE * sizeof(SElemType_Sq));
    if (!(*S).base) {
        exit(OVERFLOW);
    }
    
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    
    return OK;
    
}

Status DestoryStock_Sq(SqStack *S) {
    
    free((*S).base);
    (*S).base = NULL;
    (*S).top = NULL;
    (*S).stacksize = 0;
    
    return OK;
}

Status ClearStack_Sq(SqStack *S) {
    (*S).top = (*S).base;
    return OK;
}

Status StackEmpty_Sq(SqStack S) {
    if (S.top == S.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int StackLength_Sq(SqStack S) {
    return (int)(S.top - S.base);
}

Status GetTop_Sq(SqStack s,SElemType_Sq *e) {
    if (s.top == s.base) {
        return ERROR;
    }
    *e = *(s.top - 1);
    return OK;
}

Status Push_sq (SqStack *s,SElemType_Sq e) {
    if ((*s).top-(*s).base >= (*s).stacksize) {
        (*s).base = (SElemType_Sq *)realloc((*s).base, ((*s).stacksize + STACKINCREASEMENT)*sizeof(SElemType_Sq));
        if (!(*s).base)
            exit(OVERFLOW);
        (*s).top = (*s).base + (*s).stacksize;
        (*s).stacksize += STACKINCREASEMENT;
    }
    
    *(s->top) = e;
    (s->top)++;
    return OK;
}

Status Pop_Sq(SqStack *s,SElemType_Sq *e) {
    if((*s).top == (*s).base)
        return ERROR;
    
    (*s).top--;
    *e = *((*s).top);
    return OK;
}

Status StackTraverse_Sq(SqStack s,void(Visit)(SElemType_Sq)) {
    SElemType_Sq *p = s.base;
    while (p<s.top) {
        Visit(*p++);
    }
    return OK;
}













