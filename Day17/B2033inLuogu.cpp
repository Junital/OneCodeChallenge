/************************************************************
 * 题目：A*B 问题
 * 要求：输入两个数，输出两个数的乘积。
 * 作者：Junital
 * 思路：无
 * 函数：Mul用于乘法。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

/* 输入两个longlong类型的数据，输出一个longlong类型的数据，为输入的乘积 */
ll Mul(ll x, ll y)
{
    return x * y;
}

int main()
{
    ll x, y;
    cin >> x >> y;
    cout << Mul(x, y) << endl;
    return 0;
}
