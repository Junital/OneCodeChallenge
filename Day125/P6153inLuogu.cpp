/***************************************************************
 * 题目：询问
 * 描述：每次告诉你某两个物品是一类的，求一共有几类。
 * 思路：见P6153 Solve，唬人的。
 * 函数：Minus模拟减法。
 * 注意：注意数据范围很大。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

ll Minus(ll X, ll Y)
{
    return X - Y;
}

int main()
{
    ll Num, QueryNum;
    cin >> Num >> QueryNum;

    rep(i, 1, QueryNum)
    {
        ll x, y;
        cin >> x >> y;
    }

    cout << Minus(Num, QueryNum) << endl;
    return 0;
}
