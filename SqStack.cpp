//
// Created by katie on 2022/11/2.
//

#include "SqStack.h"
#include <stdlib.h>

/* 创建栈 */
SqStack *InitStack()
{
    SqStack *S;
    S = (SqStack *)malloc(sizeof(*S));
    S->top = -1;
    return S;
}

/* 入栈 */
bool Push(SqStack *S, double x)
{
    if(S->top==MAX_LEN-1)
    {
        return false;
    }
    S->top=S->top+1;
    S->data[S->top]=x;
    return true;
}

/* 出栈 */
bool Pop(SqStack *S, double *x)
{
    if(S->top==-1)
    {
        return false;
    }
    *x=S->data[S->top];
    S->top=S->top-1;
    return true;
}

/* 获得栈顶值 */
bool GetTop(SqStack *S, double *x)
{
    if(S->top==-1)
    {
        return false;
    }
    *x=S->data[S->top];
    return true;
}

/* 判断栈是否为空 */
bool IsStackEmpty(SqStack *S)
{
    if(S->top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
