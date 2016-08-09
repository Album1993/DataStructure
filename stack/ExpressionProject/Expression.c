//
// Created by akka on 16/8/8.
//

#include "Expression.h"

void(Visit)(SElemType_Sq s) {
    printf("\n%c\n",s);
}
// 表达式求值
OperandType EvaluateExpression(char exp[]) {
    SqStack OPTR,OPND;
    SElemType_Sq e,ch;

    OperatorType theta,x;
    OperandType a,b;

    int  i;

    InitList_Sq(&OPTR);
    Push_sq(&OPTR,'#');

    InitList_Sq(&OPND);

    i = 0;
    ch = exp[i++];

    while (ch != '#' || GetTop_OPTR(OPTR) != '#'){
        if (!In(ch)) {
            Push_sq(&OPND,ch);
            ch = exp[i++];
            StackTraverse_Sq(OPND,Visit);
        } else {
            switch (Precede(GetTop_OPTR(OPTR),ch)) {
                case '<':
                    Push_sq(&OPTR,ch);
                    StackTraverse_Sq(OPTR,Visit);
                    ch = exp[i++];
                    break;
                case '=':
                    Pop_Sq(&OPTR,&x);
                    StackTraverse_Sq(OPTR,Visit);
                    ch = exp[i++];
                    break;
                case '>':
                    Pop_Sq(&OPTR,&theta);
                    Pop_Sq(&OPND,&b);
                    Pop_Sq(&OPND,&a);
                    OperandType p = Operate(a,theta,b);
                    Push_sq(&OPND,Operate(a,theta,b));
                    StackTraverse_Sq(OPND,Visit);
                    StackTraverse_Sq(OPTR,Visit);
                    break;
            }
        }
    }

    return GetTop_OPTR(OPND);
}

// 获取操作符栈的栈顶元素
OperatorType GetTop_OPTR(SqStack OPTR) {
    SElemType_Sq e;
    GetTop_Sq(OPTR,&e);
    return e;
}

// 判断e是不是操作符
Status In(SElemType_Sq e) {
    switch (e)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':
            return TRUE;
        default:
            return FALSE;
    }
}

// 判断栈中操作符的优先级
OperatorType Precede(OperatorType o1,OperatorType o2) {
    OperatorType f ;

    switch (o2) {
        case '+':
        case '-':
        {
            if (o1 == '(' || o1 == '#') {
                f = '<';
            }
            else {
                f = '>';
            }
        }
            break;
        case '*':
        case '/':
        {
            if (o1 == '*' || o1 == '/' || o1 == ')') {
                f = '>';
            }
            else {
                f = '<';
            }
        }
            break;
        case '(':
            if (o1 == ')') {
                printf("\n括号匹配错误!\n");
                exit(ERROR);
            }
            else
            {
                f = '<';
            }
            break;
        case ')':
            switch (o1)
            {
                case '(':{
                    f = '=';
                }
                    break;
                case '#':
                    printf("\n输出了错误的括号!\n");
                    exit(ERROR);
                default:
                    f = '>';
            }
            break;
        case '#':
            switch (o1)
            {
                case '#':
                {
                    f = '=';
                }
                    break;
                case '(':
                    printf("\n表达式中有多余的括号!\n");
                    exit(ERROR);
                default:
                {
                    f = '>';
                }
            }
    }
    return f;
}

// 计算表达似的值
OperandType  Operate(OperandType a,OperatorType thete, OperandType b) {
    int x,y,z;
    x = a - 48;
    y = b - 48;

    switch (thete) {
        case '+':
            return x+y+48;
            break;
        case '-':
            return x-y+48;
            break;
        case '*':
            return x*y+48;
            break;
        case  '/':
            return x/y+48;
            break;
    }
    return 0;
}

