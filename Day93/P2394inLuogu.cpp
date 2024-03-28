/***********************************************
 * 题目：yyy loves Chemistry I
 * 描述：给一个实数，输出其除以23的前八位。
 * 思路：计算。
 * 对象：NaH2模拟钠变氢气。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ld long double // 定义长浮点

double NaH2(double Na)
{
    return Na / 23;
}

int main()
{
    ld na;
    cin >> na;

    cout << fixed << setprecision(8) << NaH2(na) << endl;
    return 0;
}