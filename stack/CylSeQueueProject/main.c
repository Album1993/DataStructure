//
// Created by akka on 16/8/10.
//

#include <stdio.h>
#include "CycleSeqQueue.h"

void PrintElem(QElemType_CSq e);

int main(int argc, char **argv) {
    CSqQueue Q;
    int i;
    QElemType_CSq e;

    printf("initQueue");
    InitQueue_CSq(&Q);
    printf("\n");

    for (i = 1 ; i < 6; ++i) {
        printf("element:%2d has enter the queue:\n",2*i);
        EnQueue_CSq(&Q,2*i);
    }

    printf("elements in queue:");
    QueueTraverse_CSq(Q,PrintElem);
    return 0;
}

void PrintElem(QElemType_CSq e) {
    printf("%d\n",e);
}