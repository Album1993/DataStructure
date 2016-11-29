//
// Created by akka on 16/8/25.
//

#ifndef SEQUENCEARRAYPROJECT_SEQUENCEARRAY_H
#define SEQUENCEARRAYPROJECT_SEQUENCEARRAY_H

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>

#include "Status.h"

#define MAX_ARRAY_DIM 8

typedef int AElemType_Sq;
typedef struct
{
    AElemType_Sq *base; // 元素基址
    int dim;            // 数组维数
    int *bounds;        // 数组维数基址
    int *constants;     // 数组跨越时的元素个数
}Array;

Status InitArray(Array *A, int dim,...);

Status DestoryArray(Array *A );

Status LocateArray(Array A,va_list ap, int * off);

Status ValueArray(Array A,AElemType_Sq *e,...);

Status AssignArray(Array *A,AElemType_Sq e,...);

void ArrayPrint(Array A);

#endif //SEQUENCEARRAYPROJECT_SEQUENCEARRAY_H
