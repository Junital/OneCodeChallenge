/**********************************************************
 * 题目：yyy loves Maths II
 * 描述：一序列数求和。
 * 思路：模拟。
 * 函数：LongDoubleSum求和。
 * 注意：注意溢出问题，注意精度问题。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ld long double // 定义长浮点数

int main()
{
    ld Num;

    ld Sum = 0;

    while (scanf("%Lf", &Num) != EOF)
    {
        Sum += Num * 1000000; // 玄幻精度解决
    }

    printf("%.5Lf\n", Sum / 1000000);
}