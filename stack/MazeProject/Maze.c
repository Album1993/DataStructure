//
// Created by akka on 16/8/4.
//

#include "Maze.h"
Status MazePath(MazeType maze[][N],Postype start,Postype end) {
    SqStack S;
    SElemType_Sq nodeInf;      // 当前通道的信息
    Postype curPos;            // 当前位置
    int curStep;               // 当前通道的序号

    InitList_Sq(&S);

    curPos = start;
    curStep = 1;

    do {
        if (Pass(curPos,maze)) {    // 当前位置可通过?
            FootPrint(curPos,maze); //留下足迹
            ShowMaze(maze);

            SetSElemType(&nodeInf,curStep,curPos,East); // 设置当前位置的属性

            Push_sq(&S,nodeInf); // 加入栈

            if (EqualPosType(curPos,end)) { // 如果到终点
                printf("\n 寻路成功!!\n\n");
                return TRUE;
            }

            curPos = NextPos(curPos,East); // 设置下一个为东
            curStep++; // 探索下一块
        } else {
            if (!StackEmpty_Sq(S)) {// 如果没有倒退到原点
                Pop_Sq(&S,&nodeInf);
                while (nodeInf.di == North && !StackEmpty_Sq(S)) {
                    MarkPrint(nodeInf.seat,maze);    // 四个方向都遍历过,就回退一步
                    ShowMaze(maze);
                    Pop_Sq(&S,&nodeInf);
                }

                if (nodeInf.di < North) {
                    maze[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;
                    ShowMaze(maze);
                    Push_sq(&S,nodeInf);
                    curPos = NextPos(nodeInf.seat,nodeInf.di);
                }
            }
        }
    } while (!StackEmpty_Sq(S));

    printf("\n 寻路失败!!\n\n");
    return FALSE;

}

void InitMaze(MazeType maze[][N],Postype *start,Postype *end) {
    int i,j,tmp;
    srand((unsigned)time(NULL));
    for ( i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if(i == 0 || j == 0 || i == N-1 || j == N - 1)
                maze[i][j] = Wall;
            else {
                tmp = rand() % X;
                if (!tmp)
                    maze[i][j] = Obstacle;
                else
                    maze[i][j] = Way;
            }
        }
    }

    (*start).x = 1;
    (*start).y = 0;
    (*end).x = N-2;
    (*end).y = N - 1;

    maze [1][0] = maze[N-2][N-1] = Way;
    maze [1][1] = maze[N-2][N-2] = Way;

}
//→←↑↓
void PaintMaze(MazeType maze[][N]) {
    int i,j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; j++) {
            MazeType tmp = maze[i][j];
            switch (tmp) {
                case Wall:
                    printf("▅");
                    break;
                case Obstacle:
                    printf("▅");
                    break;
                case East:
                    printf("→");
                    break;
                case South:
                    printf("↓");
                    break;
                case West:
                    printf("←");
                    break;
                case North:
                    printf("↑");
                    break;
                case DeadLock:
                    printf("★");
                    break;
                default:printf(" ");
                    break;
            }
            if (j!=0 && j % (N-1) == 0)
                printf("\n");
        }
    }
}

void ShowMaze(MazeType maze[][N]) {
    Wait(SleepTime);
    system("cls");
    PaintMaze(maze);
}

Status EqualPosType(Postype a,Postype b) {
    if (a.x == b.x && a.y == b.y)
        return TRUE;
    else
        return ERROR;
}

Status Pass(Postype seat,MazeType maze[][N]) {
    int x = seat.x;
    int y = seat.y;

    if (!IsCross(seat) && maze[x][y] == Way)
        return TRUE;
    else
        return FALSE;
}

void FootPrint(Postype seat,MazeType maze[][N]) {
    maze[seat.x][seat.y] = East;
}

void SetSElemType(SElemType_Sq *e, int ord,Postype seat, int di){
    (*e).ord = ord;
    (*e).seat = seat;
    (*e).di = di;
}

Postype NextPos(Postype seat, int di){
    Postype tmp = seat;

    switch (di) {
        case East: tmp.y++;
            break;
        case South: tmp.x++;
            break;
        case West: tmp.y--;
            break;
        case North: tmp.x--;
            break;
    }
    return tmp;
}

Status IsCross(Postype seat) {
    int x = seat.x;
    int y = seat.y;

    if (x<0 || y < 0 || x>N-1||y>N-1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void MarkPrint(Postype seat,MazeType maze[][N]) {
    int x = seat.x;
    int y = seat.y;

    maze[x][y] = DeadLock;
}

