#ifndef HEADER_H
#define HEADER_H
typedef enum {
    Arrive,
    Leave_1,
    Leave_2,
    Leave_3,
    Leave_4
}EventType;

typedef struct {
    int OccurTime;
    EventType NType;
}Event;

typedef Event LElemType_L;

typedef struct LNode {
    LElemType_L data;
    struct LNode *next;
}LNode;

typedef LNode * LinkList;
typedef LinkList EventList;

typedef struct {
    int ArrivedTime;
    int Duration;
    int Count;
}QElemType_L;
#endif