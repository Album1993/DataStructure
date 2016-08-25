//
// Created by akka on 16/8/17.
//

#ifndef KMP_KMP_H
#define KMP_KMP_H

#include <stdio.h>
#include "SequenceString.h"

int Index_KMP(SString s,SString T, int pos, int next[]);

void get_next(SString T, int next[]);

void get_nextval(SString T, int nextval[]);

#endif //KMP_KMP_H
