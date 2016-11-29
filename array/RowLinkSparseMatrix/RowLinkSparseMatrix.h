//
// Created by akka on 16/9/11.
//

#ifndef ROWLINKSPARSEMATRIX_ROWLINKSPARSEMATRIX_H
#define ROWLINKSPARSEMATRIX_ROWLINKSPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include "Status.h"

#define  MAXSIZE 400 // 20 * 20 的矩阵
#define  MAXRC 20   // 单行最大元素

typedef int MELemType_RLSq;

typedef struct
{
    int i,j;
    MELemType_RLSq e;
}Triple;

typedef struct
{
    Triple data[MAXSIZE+1];  //非0元素三元组 data[0] 未用
    int rpos[MAXRC + 1]; // 各行第一个非0元素的位置表
    int mu,nu,tu; // 行数 列数 非0个数
}RLSMatrix;

Status CreateSMatrix_RL(FILE *fp, int n,...);

void DestorySMatrix_RL(RLSMatrix *M);

void PrintSMatrix_RL(RLSMatrix M);

void CopySMatrix_RL(RLSMatrix M, RLSMatrix *T);

Status AddSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q);

Status SubSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q);

Status MultSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q);

void TransposeSMatrix_RL(RLSMatrix M,RLSMatrix *T);

void FastTransposeSMatrix_RL(RLSMatrix M,RLSMatrix *T);

#endif //ROWLINKSPARSEMATRIX_ROWLINKSPARSEMATRIX_H
