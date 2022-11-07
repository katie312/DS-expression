//
// Created by katie on 2022/11/2.
//

#ifndef DS_TEST1_SQSTACK_H
#define DS_TEST1_SQSTACK_H
#define MAX_LEN 100

//栈的构建
typedef struct
{
    double data[MAX_LEN];
    int top;
} SqStack;

SqStack *InitStack();             //创建栈
bool Push(SqStack *, double);     //入栈
bool Pop(SqStack *, double *);    //出栈
bool GetTop(SqStack *, double *); //查看栈顶值
bool IsStackEmpty(SqStack *);     // 判断栈是否为空

#endif //DS_TEST1_SQSTACK_H
