//
// Created by akka on 16/8/12.
//

#ifndef BANKQUEUE_BANKQUEUE_H
#define BANKQUEUE_BANKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"
#include "SinglyLinkedList.h"
#define SleepTime 1
#define DurationTime 20
#define IntervalTime 10

#include "LinkQueue.h"

int gTotalTime,gCustomerNum;

int gCloseTime;

EventList gEv;

Event gEn;

LinkQueue gQ[5];

QElemType_L gCustomerRcd;

void Bank_Simulation_1();

void OpenForDay();

Status MoreEvent();

void EventDrived (char * event);

void CustomerArrived();

void CustomerDeparture();

void Invaild();

void CloseForDay();

int cmp(Event a,Event b);

void Random(int *duration, int *intertime);

Status OrderInsert(EventList gEv,Event gEn, int(cmp)(Event,Event));

int Minimum();

void Show();

void Bank_Simulatio_2();

#endif //BANKQUEUE_BANKQUEUE_H
