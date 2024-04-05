/***********************************************
 * 题目：yyy loves Chemistry I
 * 描述：给一个实数，输出其除以23的前八位。
 * 思路：计算。
 * 对象：NaH2模拟钠变氢气。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ld long double // 定义高精度浮点

ld NaH2(ld Na)
{
    return Na / (ld)23;
}

int main()
{
    ld na;
    scanf("%15Lf", &na); // 读取数据的时候，只读取15位

    // cout << na << endl;

    printf("%.8Lf", NaH2(na));
    return 0;
}