/*****************************************************************
 * 题目：[语言月赛202305] 计算阶乘
 * 描述：从n-1开始，每次隔一个数字相乘。
 * 思路：模拟，无法分次计算。
 * 函数：CustomFactorial模拟自定义阶乘。
 * 注意：结果会溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

ull CustomFactorial(ull Num)
{
    ll iter = Num - 1;
    ull res = 1;

    while (iter > 0)
    {
        res *= iter;
        iter -= 2;
    }

    return res;
}

int main()
{
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        ull num;
        cin >> num;

        cout << (ull)2 * CustomFactorial(num) << endl;
    }
    return 0;
}