//
// Created by akka on 16/8/9.
//

#include "LinkQueue.h"

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
    QueuePtr 
};
