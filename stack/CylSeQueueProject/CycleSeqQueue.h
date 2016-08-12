//
// Created by akka on 16/8/10.
//

#ifndef CYLSEQUEUEPROJECT_CYCLESEQQUEUE_H
#define CYLSEQUEUEPROJECT_CYCLESEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define MAXSIZE 1000

typedef int QElemType_CSq;
typedef struct {
    QElemType_CSq *base;
    int front;
    int rear;
}CSqQueue;

Status InitQueue_CSq(CSqQueue *Q);

void ClearQueue_CSq(CSqQueue *Q);

void DestoryQueue_CSq(CSqQueue *Q);

Status QueueEmpty(CSqQueue Q);

int QueueLength_CSq(CSqQueue Q);

Status GetHead_CSq(CSqQueue Q,QElemType_CSq *e);

Status EnQueue_CSq(CSqQueue *Q,QElemType_CSq e);

Status DeQueue_CSq(CSqQueue *Q,QElemType_CSq *e);

void QueueTraverse_CSq(CSqQueue Q, void(Visit)(QElemType_CSq));


#endif //CYLSEQUEUEPROJECT_CYCLESEQQUEUE_H
