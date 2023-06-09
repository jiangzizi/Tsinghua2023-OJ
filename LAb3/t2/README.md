
# DM2023 3-2-2 小狗勾学编译 (2)


## 问题描述

从前有一只小狗勾，他对编译原理非常感兴趣，于是他决定自己写一个编译器。

编译器是将源代码（如 C++）翻译为目标架构（如 x86）下的机器代码的软件。小狗勾的目标机器有若干寄存器，所有参与计算的变量都要储存在寄存器中。源代码中每一个 变量 都需要被分配到到目标机器中的一个 寄存器 上，在目标机器代码中用该寄存器编号作为该变量的“新名字”。为了高效地使用寄存器，如果几个变量的值不需要同时被保存，就会给让它们共用一个寄存器。

例如，在以下例子中：
```c++
a = b + c;
d = a * c;
print(d);
```
↓
```c++
R0 = R0 + R1;
R0 = R0 * R1;
print(R0);
```
变量 a, b, d 共用了寄存器 R0。但还是有些变量不能共用一个寄存器，如上例的 b, c 和 a, c 不能共用一个寄存器，所以要用一个新的寄存器 R1 保存变量 c。

变量的个数可以任意多，但寄存器的个数是有限的。因此，如何高效地将有限的寄存器分配给无限的变量，是编译器设计中的关键问题之一。

为了简化这个问题，我们假设源代码中有 N 个变量，有 M 对约束关系，形如变量 a_i 和 b_i 不能共用一个寄存器，且这一段程序中每个变量自始至终只使用一个寄存器。小狗勾已经保证提取了全部的约束关系，只要寄存器分配方案满足了全部给定约束，无论源程序是什么，总能完成一次正确的程序翻译。

小狗勾想知道，给定一些变量及其约束关系，要想将变量全部分配到寄存器上，至少需要几个寄存器，且应当如何分配。你能帮他完成这个任务吗？
## 输入格式

从标准输入读取数据。

输入共 1 + M 行。

第 1 行是 2 个整数 N，M，含义见上文。

第 2 行到第 M + 1 行，第 1 + i 行有 2 个整数 a_i 和 b_i，表示第 a_i 个变量和第 b_i 个变量不能共用同一个寄存器。
## 输出格式

输出到标准输出。

输出共 2 行。

第 1 行为 1 个整数 k，表示为了完成分配最少需要的寄存器个数。

第 2 行为 N 个整数，表示分配方案，其中第 i 个整数 n_i 表示第 i 个变量应该分配的寄存器编号。其中 n_i 满足 1 ≤ n_i ≤ k。可能有多种合法的分配方案，输出其中一种即可。
样例输入
```c++
5 7
1 2
1 3
1 4
1 5
2 4
3 5
4 5
```
样例输出
```c++
3
1 2 3 3 2
```
## 样例解释

变量 1 使用一个寄存器。

变量 2，5 可以共用一个寄存器。

变量 3，4 可以共用一个寄存器。
## 数据范围与约定

1 ≤ N ≤ 15

1 ≤ M ≤ 100

时间限制：1 秒

内存限制：256 MiB
## 提示

本题无需你事先对编译原理有任何了解，请各位同学坐和放宽。
