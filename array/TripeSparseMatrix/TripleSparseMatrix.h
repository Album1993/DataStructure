//
// Created by akka on 16/9/2.
//

#ifndef TRIPESPARSEMATRIX_TRIPLESPARSEMATRIX_H
#define TRIPESPARSEMATRIX_TRIPLESPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include "Status.h"

#define MAXSIZE 400

typedef int MElemType_TSq;

typedef struct {
    int i,j;
    MElemType_TSq e;
}Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int mu,nu,tu;
}TSMatrix;

Status CreateSMatrix_T(FILE * fp, int n, ...);

void DestoryMatrix_T(TSMatrix *M);

void PrintSMatrix_T(TSMatrix M);

void CopySMatrix_T(TSMatrix M,TSMatrix *T);

Status AddMatri_T(TSMatrix M,TSMatrix N,TSMatrix *Q);

Status SubSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q);

Status MultiSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q);

// 转置矩阵
void TransposeSMatrix(TSMatrix M,TSMatrix *T);

// 快速转置矩阵
void FastTransposeSMatrix_T(TSMatrix M,TSMatrix *T);

#endif //TRIPESPARSEMATRIX_TRIPLESPARSEMATRIX_H
