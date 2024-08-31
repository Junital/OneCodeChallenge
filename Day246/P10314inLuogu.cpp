/*****************************************************************
 * 题目：[SHUPC 2024] 函数
 * 描述：计算某个函数下的值。
 * 思路：找规律，发现是取下界。
 * 函数：Function1模拟函数。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

double Function1(double Input)
{
    return floor(Input);
}

int main()
{
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        double input;
        cin >> input;

        cout << fixed << setprecision(6) << Function1(input) << endl;
    }
}