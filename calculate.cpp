//
// Created by katie on 2022-11-1.
//

using namespace std;
#include "calculate.h"

/* 将输入分割的数组转换成多位、带正负的数 */
double trans(char *buff)
{
    int len=strlen(buff);   //最大长度
    int flag=0;                 //判断是否为负数
    double res=0;               //输出结果

    //判断负数
    if(buff[0]=='-')
    {
        flag=1;
    }

    //将独立数字转换为一个数
    for(int i=0;i<len;i++)
    {
        if (buff[i] >= '0' && buff[i] <= '9')
        {
            res = res*10+buff[i]-'0';
        }
    }

    //转换负数
    if(flag)
    {
        res= (-1)*res;
    }

    return res;
}

/* 运算符优先级判断函数 */
int GetPri(double op)
{
    switch ((int)op)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
        case '@':
            return 3;
        default:
            return -1;
    }
}

/* 将两个数出栈，根据OldOp计算，然后再次入栈 */
void compute(SqStack *StackNum, double op)
{
    double res,num1,num2;   //弹出两个数栈里的数，进行计算
    Pop(StackNum,&num1);
    Pop(StackNum,&num2);

    //按照符号来进行操作
    switch ((int)op) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num2 - num1;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            res = num2 / num1;
            break;
        case '%':
            res = fmod(num2, num1);
            break;
        case '^':
            res = pow(num2, num1);
            break;
        case '@':
            res = pow(num2, 1 / num1);
            break;
    }

    //得到的结果再入栈
    Push(StackNum,res);
}

/* 处理符号 */
void DoOp(SqStack *StackNum, SqStack *StackOp, double op) {

    double OldOp;   //保存现在符号栈栈顶的符号

    //如符号栈为空 或 为左括号，直接将新的符号入栈
    if (IsStackEmpty(StackOp) || (int) op == '(') {
        Push(StackOp, op);
        return;
    }

    GetTop(StackOp, &OldOp);

    //如栈顶符号优先级比目前的符号大，直接入栈
    if (GetPri(op) > GetPri(OldOp)) {
        Push(StackOp, op);
        return;
    }

    //如栈顶符号优先级比目前的符号小，依次先弹栈、计算、压栈，如果为空就退出
    while (GetPri(op) <= GetPri(OldOp)) {
        Pop(StackOp, &OldOp);
        compute(StackNum, OldOp);
        if (IsStackEmpty(StackOp)) {
            break;
        }
        GetTop(StackOp, &OldOp);
    }
    Push(StackOp,op);
}

/* 处理右括号 */
void DoBracket(SqStack *StackNum, SqStack *StackOp)
{
    //保存现在符号栈栈顶的符号
    double OldOp;
    GetTop(StackOp,&OldOp);

    //依次弹栈、计算、压栈，直到遇到左括号
    while((double)OldOp!='(')
    {
        Pop(StackOp,&OldOp);
        compute(StackNum,OldOp);
        GetTop(StackOp,&OldOp);
    }

    //弹出左括号
    Pop(StackOp,&OldOp);
}

/* 计算整个式子，得到结果 */
double cal(char *str)
{
    int index1 = 0;         //初始数组下标
    int index2 = 0;         //转变后的数组下标
    char buff[MAX_LEN];     //存取字符型数字
    double num = 0;         //数字的值
    int flag = 0;           //标记是否有数字
    double OldOp;           //最新的运算符

    SqStack *StackNum, *StackOp;    //定义两个指向栈结构体的指针
    StackNum = InitStack();         //创建数栈
    StackOp = InitStack();          //创建符号栈

    //将初始的表达式解析，将高优先级的符号先进行计算，同时压入数栈/符号栈，得到优先级一样的符号栈
    while (str[index1] != '\0')
    {
        int sign = 0;
        if(str[index1]=='-')
        {
            if(index1==0)
            {
                if(str[1]=='(')
                {
                    Push(StackNum,0);
                    Push(StackOp,'-');
                    Push(StackOp,'(');
                    index1=2;
                }
                buff[index2++]=str[index1++];
                flag=1;
                continue;
            }
            if(str[index1-1]=='(' || str[index1-1]=='-')
            {
                buff[index2++]=str[index1++];
                flag=1;
                continue;
            }
        }
        //处理数字
        if ((str[index1] >= '0' && str[index1] <= '9'))
        {
            buff[index2++] = str[index1];
            flag = 1;
        }
        else
        {
            //buff里有数字
            if (flag)
            {
                //将单个的数字转化成个体，并入数栈
                num = trans(buff);
                Push(StackNum, num);

                //flag数字标志清零，中间变量数字，buff中间数组，转变后的数组下标清零
                flag = 0;
                num = 0;
                memset(buff, '\0', strlen(buff)*sizeof(char));
                index2 = 0;
            }
            //如为右括号，进行右括号的操作
            if ((int)str[index1] == ')')
            {
                DoBracket(StackNum, StackOp);
            }
            //如为其他符号
            else
            {
                DoOp(StackNum, StackOp, str[index1]);
            }
        }
         index1++;
    }

    //如果flag = 1，说明value里面还有数值，将其入栈
    if (flag)
    {
        num = trans(buff);
        Push(StackNum, num);
    }

    //循环依次将数栈、符号栈出栈计算
    while (!IsStackEmpty(StackOp))
    {
        Pop(StackOp, &OldOp);
        compute(StackNum, OldOp);
    }

    //数字栈最后剩下的数字为结果
    Pop(StackNum, &num);
    free(StackNum);
    free(StackOp);
    return num;
}