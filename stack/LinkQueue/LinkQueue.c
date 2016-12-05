//
// Created by akka on 16/8/9.
//

#include "LinkQueue.h"

Status InitQueue_L(LinkQueue *Q) {
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if (!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next = NULL;
    return OK;
}

void ClearQueue_L(LinkQueue *Q){
    (*Q).rear = (*Q).front->next; // 直接到第二个元素
    while ((*Q).rear) { // 从第二个元素一个一个销毁
        (*Q).front->next = (*Q).rear->next;
        free((*Q).rear);
        (*Q).rear = (*Q).front->next;
    }
    (*Q).rear = (*Q).front; // 保留第一个元素
}

void DestoryQueue_L(LinkQueue *Q) {
    while ((*Q).front) { //从第一个元素开始,一个一个向后销毁
        (*Q).rear = (*Q).front->next;
        free((*Q).front);
        (*Q).front = (*Q).rear;
    }
}

Status QueueEmpty_L(LinkQueue Q) {
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

<<<<<<< HEAD
typedef struct {
    QueuePtr
};
=======
int QueueLength_L(LinkQueue Q) {
    int count = 0;
    QueuePtr p = Q.front;
    while (p != Q.rear) {
        count ++;
        p = p->next;
    }
    return count;
}

Status GetHead_L(LinkQueue Q,QElemType_L *e) {
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    *e = p->data;

    return OK;
}
// 元素e入队
Status EnQueue_L(LinkQueue *Q,QElemType_L e) {
    QueuePtr p;

    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);

    p->data = e;
    p->next = NULL;

    (*Q).rear->next = p;
    (*Q).rear = p;
    return OK;
}
// 元素e出队
Status DeQueue_L(LinkQueue *Q,QElemType_L *e) {
    QueuePtr p;

    if ((*Q).front == (*Q).rear)
        return ERROR;

    p = (*Q).front->next;
    *e = p->data;

    (*Q).front ->next =p->next;
    if ((*Q).rear == p)
        (*Q).rear = (*Q).front;
    free(p);
    return OK;
}

void QueueTraverse_L(LinkQueue Q, void(Visit)(QElemType_L)) {
    QueuePtr p;
    p = Q.front->next;
    while (p) {
        Visit(p->data);
        p = p->next;
    }
}
>>>>>>> 0a8a36e753b6a69631ef134d6a05252d5495e8dd
