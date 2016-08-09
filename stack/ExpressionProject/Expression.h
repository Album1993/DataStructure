//
// Created by akka on 16/8/8.
//

#ifndef EXPRESSIONPROJECT_EXPRESSION_H
#define EXPRESSIONPROJECT_EXPRESSION_H

#include <stdio.h>


typedef char SElemType_Sq;

#include "SequenceStack.h"

typedef SElemType_Sq OperandType; // 操作数类型

typedef SElemType_Sq OperatorType; // 运算符类型

// 表达式求值
OperandType EvaluateExpression(char exp[]);

// 获取操作符栈的栈顶元素
OperatorType GetTop_OPTR(SqStack OPTR);

// 判断e是不是操作符
Status In(SElemType_Sq e);

// 判断栈中操作符的优先级
OperatorType Precede(OperatorType o1,OperatorType o2);

// 计算表达似的值
OperandType  Operate(OperandType e,OperatorType thete, OperandType b);

#endif //EXPRESSIONPROJECT_EXPRESSION_H
