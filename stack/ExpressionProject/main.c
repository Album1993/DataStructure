//
// Created by akka on 16/8/8.
//

#include <stdio.h>
#include "Expression.h"

int main(int argc, char ** argv) {
    char opnd;
    char *exp = "1+2*(5-3)-6/2+4#";
    opnd = EvaluateExpression(exp);
    printf("\nexpression:%s 结果:%c\n",exp,opnd);
    printf("\n");
    return 0;
}