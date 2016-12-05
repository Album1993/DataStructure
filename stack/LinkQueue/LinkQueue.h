//
// Created by akka on 16/8/9.
//

#ifndef LINKQUEUE_LINKQUEUE_H
#define LINKQUEUE_LINKQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

typedef int QElemType_L;

typedef struct QNode {
    QElemType_L data;
    struct QNode *next;
}QNode;

typedef QNode *QueuePtr;

typedef struct {
    QueuePtr front; // 头指针
    QueuePtr rear;  // 尾指针
}LinkQueue;


Status InitQueue_L(LinkQueue *Q);

void ClearQueue_L(LinkQueue *Q);

void DestoryQueue_L(LinkQueue *Q);

Status QueueEmpty_L(LinkQueue Q);

int QueueLength_L(LinkQueue Q);

Status GetHead_L(LinkQueue Q,QElemType_L *e);
// 元素e入队
Status EnQueue_L(LinkQueue *Q,QElemType_L e);
// 元素e出队
Status DeQueue_L(LinkQueue *Q,QElemType_L *e);

void QueueTraverse_L(LinkQueue Q, void(Visit)(QElemType_L));
#endif //LINKQUEUE_LINKQUEUE_H
