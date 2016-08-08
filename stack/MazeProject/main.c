//
// Created by akka on 16/8/4.
//

#include <stdio.h>
#include "Maze.h"

int main(int argc, char *argv[]) {
    MazeType maze[N][N] ;
    Postype start,end;
    SElemType_Sq e;
    char Re = 'Y';

    InitMaze(maze,&start,&end);
    ShowMaze(maze);
    MazePath(maze,start,end);
    printf("%c",&Re);
    return 0;


}