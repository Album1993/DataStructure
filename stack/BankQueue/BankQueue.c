//
// Created by akka on 16/8/12.
//

#include "BankQueue.h"

void Bank_Simulation_1() {
    char eventType;

    OpenForDay();

    while (MoreEvent()) {
        EventDrived(&eventType);

        switch (eventType) {
            case 'A':
                CustomerArrived();
                break;
            case 'B':
                CustomerDeparture();
                break;
            default:
                Invaild();
        }
    }

    CloseForDay();
}

void OpenForDay() {
    int i;

    gTotalTime = 0;
    gCustomerNum = 0;

    InitList_L(&gEv);

    gEn.OccurTime = 0;
    gEn.NType = Arrive;

    OrderInsert(gEv,gEn,cmp);

    for (i = 1; i <= 4 ; ++i) {
        InitQueue_L(&gQ[i]);
    }
    Show();
}

Status MornEvent() {
    if (!ListEmpty_L(gEv))
        return TRUE;
    else
        return FALSE;
}

void EventDrived(char * event) {
    ListDelete_L(gEv,1,&gEn);

    if (gEn.NType == Arrive)
        *event = 'A';
    else
        *event = 'D';
}

void CustomerArrived() {
    int duration,intertime;
    int cur_LeftTime,suc_ArrivalTime;
    int i;

    ++gCustomerNum;

    Random(&duration,&intertime);

    cur_LeftTime = gEn.OccurTime + duration;

    suc_ArrivalTime = gEn.OccurTime + intertime;

    gCustomerRcd.ArrivedTime = gEn.OccurTime;

    gCustomerRcd.Duration = duration;

    gCustomerRcd.Count = gCustomerNum;

    i = Minimum(gQ);

    EnQueue(&gQ[i],gCustomerRcd);

    Show();

    if (suc_ArrivalTime < gCloseTime) {
        gEn.OccurTime = suc_ArrivalTime;
        gEn.NType = Arrive;
        OrderInsert(gEv,gEn,cmp);
    }

    if (QueueLength_L(gQ[i]) == 1) {
        gEn.OccurTime = cur_LeftTime;
        gEn.NType = i;
        OrderInsert(gEv, gEn, cmp);
    }
}

void CustomerDeparture() {
    int i = gEn.NType;
    DeQueue_L(&gQ[i],&gCustomerRcd);
    Show();

    gTotalTime += gEn.OccurTime - gCustomerRcd.ArrivedTime;

    if (!QueueEmpty_L(gQ[i])) {
        GetHead_L(gQ[i],&gCustomerRcd);
        gEn.OccurTime += gCustomerRcd.Duration;
        gEn.NType = i;
        OrderInsert(gEv,gEn,cmp);
    }
}

void Invalid () {
    printf("运行错误");
    exit(OVERFLOW);
}

void CloseForDay() {
    printf("当天共有:%d个客户,平均逗留时间为:%d分钟。",gCustomerNum,gTotalTime/gCustomerNum);
}

int cmp(Event a,Event b) {
    if (a.OccurTime < b.OccurTime) {
        return -1;
    }

    if (a.OccurTime == b.OccurTime) {
        return 0;
    }

    if (a.OccurTime > b.OccurTime) {
        return 1;
    }
    return -2;
}

void Random(int *durtime, int *intertime) {
    srand((unsigned)time(NULL));
    *durtime = rand()%DurationTime;
    *intertime = rand()%IntervalTime;
}

Status OrderInsert(EventList gEv,Event gEn, int(cmp)(Event,Event)) {
    int i;
    EventList p, pre, s;

    pre = gEv;
    p = gEv->next;

    while (p && cmp(gEn,p->data) == 1) {
        pre = p;
        p = p->next;
    }

    s = (LinkList)malloc(sizeof(LNode));

    if (!s)
        exit(OVERFLOW);

    s->data = gEn;

    s->next = pre->next;

    pre->next = s;

    return OK;

}

int Minimum() {
    int i1 = QueueLength_L(gQ[1]);
    int i2 = QueueLength_L(gQ[2]);
    int i3 = QueueLength_L(gQ[3]);
    int i4 = QueueLength_L(gQ[4]);

    if (i1 <= i2 && i1 <= i3 && i1<=i4)
        return 1;
    if (i2 < i1 && i2<= i3 && i2 <=i4)
        return 2;
    if (i3 < i1 && i3 < i2 && i3 <= i4)
        return 3;
    if (i4 < i1 && i4 < i2 && i4 < i3)
        return 4;
    return 0;
}

void Show() {
    int i;
    QueuePtr p;
    system("cls");
    for (i = 1; i <= 4 ; ++i) {
        for (p = gQ[i].front; p ; p = p->next) {
            if (p == gQ[i].front) {
                if (i == 1)
                    printf("柜台一");
                if (i == 2)
                    printf("柜台二");
                if (i == 3)
                    printf("柜台三");
                if (i == 4)
                    printf("柜台四");
            } else {
                printf("(%03d)",p->data.Count);
            }

            if (p == gQ[i].rear)
                printf("\n");
        }
    }
    Wait(SleepTime);
}

void Bank_Simulation_2() {
    OpenForDay();
    while (!ListEmpty_L(gEv)) {
        ListDelete_L(gEv,1,&gEn);
        if (gEn.NType == Arrive)
            CustomerArrived();
        else
            CustomerDeparture();
    }
    printf("当天总共有%d个客户,平均都有为%d 分钟。\n",gCustomerNum,gTotalTime/gCustomerNum);
}