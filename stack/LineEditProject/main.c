//
// Created by akka on 16/8/3.
//

#include <stdio.h>
#include "LineEdit.h"
int main (int args, char ** argv) {
    char *buf = "whi#ile(a#*s)\nahjd@putchar(*s++)";
    printf("%s\n",buf);
    printf("转换后:");
    LineEdit(buf);
    return 0;
}