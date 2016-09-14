//
// Created by akka on 16/9/11.
//

#ifndef ROWLINKSPARSEMATRIX_ROWLINKSPARSEMATRIX_H
#define ROWLINKSPARSEMATRIX_ROWLINKSPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include "Status.h"

#define  MAXSIZE 400
#define  MAXRC 30

typedef int MELemType_RLSq;

typedef struct
{
    int i,j;
    MELemType_RLSq e;
}Triple;

typedef struct
{
    Triple data[MAXSIZE+1];  //
    int rpos[MAXRC + 1];
    int mu,nu,tu;
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
