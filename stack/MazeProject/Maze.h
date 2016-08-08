//
// Created by akka on 16/8/4.
//

#ifndef MAZEPROJECT_MAZE_H
#define MAZEPROJECT_MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"

#define N 15
#define X 4

#define SleepTime 2

typedef enum {
    Wall,
    Obstacle,
    Way,
    DeadLock,
    East,
    South,
    West,
    North
}MazeNode;

typedef struct {
    int x;
    int y;
}Postype;

typedef struct {
    int  ord;
    Postype seat;
    int di;
}SElemType_Sq;

#include "SequenceStack.h"

typedef int MazeType;

Status MazePath(MazeType maze[][N],Postype start,Postype end);

void InitMaze(MazeType maze[][N],Postype *start,Postype *end);

void PaintMaze(MazeType maze[][N]);

void ShowMaze(MazeType maze[][N]);

Status EqualPosType(Postype a,Postype b);

Status Pass(Postype seat,MazeType maze[][N]);

void FootPrint(Postype seat,MazeType maze[][N]);

void SetSElemType(SElemType_Sq *e, int ord,Postype seat, int di);

Postype NextPos(Postype seat, int di);

Status IsCross(Postype seat);

void MarkPrint(Postype seat,MazeType maze[][N]);

#endif //MAZEPROJECT_MAZE_H
