/*****************************************************************
 * 题目：[语言月赛 202406] 编程学习
 * 描述：每天练习两题，需要几天完成。
 * 思路：取上界。
 * 函数：LLDevideCeil模拟长整型除法的结果取上界。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

ll LLDevideCeil(ll A, ll B)
{
    return A / B + (A % B != 0);
}

int main()
{
    ll current, target;
    const ll PerDay = 2;

    cin >> current >> target;

    cout << LLDevideCeil(target - current, PerDay) << endl;
    return 0;
}