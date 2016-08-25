//
// Created by 张一鸣 on 16/8/10.
//

#ifndef SEQUENCESTRING_SEQUENCESTRING_H
#define SEQUENCESTRING_SEQUENCESTRING_H

#include <stdio.h>
#include <string.h>

#include "Status.h"

#define MAXSTRLEN 255

typedef unsigned char SString[MAXSTRLEN + 1];

Status  StrAssign_Sq(SString T, const char * chars);

void StrCopy_Sq(SString T,SString S);

Status StrEmpty_Sq(SString S);

int  StrCompare_Sq(SString Sx,SString T);

int StrLength_Sq(SString);

void ClearString_Sq(SString S);

Status Concat_Sq(SString T,SString S1, SString S2);

Status SubString_Sq(SString Sub,SString S, int pos ,int len);

int Index_Sq_1(SString S,SString T, int pos);

int Index_Sq_2(SString S,SString T, int pos);

Status Replace_Sq(SString S,SString T,SString V);

Status StrInsert_Sq(SString S,int pos,SString T);

Status  StrDelete_Sw(SString S, int pos, int len);

Status DestroyString_Sq(SString S);

void StrPrint_Sw(SString S);

#endif //SEQUENCESTRING_SEQUENCESTRING_H
