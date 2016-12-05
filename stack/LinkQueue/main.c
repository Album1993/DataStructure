//
// Created by akka on 16/8/9.
//

#include <stdio.h>
#include "LinkQueue.h"

void PrintElem(QElemType_L e);

int main(int argc, char ** argv)
{
    LinkQueue Q;
    int i;
    QElemType_L e;

    printf("初始化队列");
    InitQueue_L(&Q);
    printf("\n");

    PressEnter;

    QueueEmpty_L(Q) ? printf("Q 为空\n") : printf("Q 不为空\n");
    PressEnter;

    for (int j = 0; j < 6; ++j) {
        printf("元素%2d 入队\n",2*j);
        EnQueue_L(&Q,2*j);
        printf("累计第%d个元素\n",QueueLength_L(Q));
    }

    i = QueueEmpty_L(Q);
    printf("Q的长度%d\n",i);

    QueueTraverse_L(Q,PrintElem);

    GetHead_L(Q,&e);
    printf("the header of the queue is %d",e);

}


void PrintElem(QElemType_L e) {
    printf("%d\n",e);

}
