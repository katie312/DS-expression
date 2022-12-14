完成的功能：


1.加减乘除、取余、次幂计算

2.多位数运算

3.小数运算

4.解决第一个数为负数、-（xx）、--（xx）、+（-xx）等特殊情况判断


文件路径：

![1](https://user-images.githubusercontent.com/91370128/199647183-e218b4a0-5f64-4446-b2f8-5a452b54a624.jpg)


calculate：表达式处理

SqStack：顺序栈的建立

算法思路：表达式先存储在str数组中，然后依次进行单独数字转换成一个整体的数字、进数栈/符号栈、高优先级符号运算处理、再整体进行运算处理。

遍历栈遇到的情况有：

- 遇到左括号直接入栈，遇到右括号将栈中左括号之后入栈的运算符全部弹栈输出，同时左括号出栈但是不输出。
- 遇到乘号和除号直接入栈，直到遇到优先级比它更低的运算符，依次弹栈，计算再入栈。
- 遇到加号和减号，如果此时栈空，则直接入栈，否则，将栈中优先级高的运算符依次弹栈，计算再入栈（注意：加号和减号属于同一个优先级，所以也依次弹栈）直到栈空或则遇到左括号为止，停止弹栈。（且要把左括号弹出）。
- 获取完后，将栈中剩余的运算符号依次弹栈，计算，入栈，数栈最后得到的数字就是结果。


流程图：

![2](https://user-images.githubusercontent.com/91370128/199647187-babe638b-9d89-459e-9ffe-800fc609af46.jpg)
![1 drawio](https://user-images.githubusercontent.com/91370128/200475932-550a6b11-db33-43cc-9f5e-b3531b3ad77a.png)
