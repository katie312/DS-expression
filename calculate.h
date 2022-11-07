//
// Created by katie on 2022-11-1.
//

#ifndef DS_TEST1_CALCULATE_H
#define DS_TEST1_CALCULATE_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.h"

double trans(char *);                                       //将输入分割的数组转换成多位、带正负的数
int GetPri(double op);                                      //判断运算符优先级
void compute(SqStack *StackNum, double op);                 //将两个数出栈，根据OldOp计算，然后再次入栈
void DoOp(SqStack *StackNum, SqStack *StackOp, double op);  //处理符号
void DoBracket(SqStack *StackNum, SqStack *StackOp);        //处理右括号
double cal(char *);                                         //计算整个式子，得到结果

#endif //DS_TEST1_CALCULATE_H