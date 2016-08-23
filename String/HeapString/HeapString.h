//
// Created by 张一鸣 on 16/8/11.
//

#ifndef HEAPSTRING_HEAPSTRING_H
#define HEAPSTRING_HEAPSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"

typedef  struct {
    char * ch;
    int length;
}HString;

void InitString_H(HString *S);

Status StrAssign_H(HString *T, char *chars);

Status StrCopy_H(HString *T,HString S);

Status StrEmpty(HString s);

Status StrCompare_H(HString S,HString T);

int StrLength_H(HString S);

Status ClearString_H(HString *S);

Status Concat_H(HString *T,HString S1,HString S2);

Status SubString_H(HString *Sub,HString S, int pos, int len);

int Index_H(HString S,HString T, int pos);

Status Replace_H(HString *S,HString T,HString V);

Status StrInsert_H(HString *S, int pos, HString T);

Status StrDelete_H(HString *S, int pos, int len);

void DestoryString_H(HString *S);

void StrPrint_H(HString S);

#endif //HEAPSTRING_HEAPSTRING_H
