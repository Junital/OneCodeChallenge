/*****************************************************************
 * 题目：[中山市赛 2024] 海洋宝宝
 * 描述：每次乘倍数，问何时超过阈值。
 * 思路：累乘。
 * 空间：Tools模拟工具箱。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

int main()
{
    ll num, multiple, thres;
    cin >> num >> multiple >> thres;

    ll cnt = 0;
    while (num < thres)
    {
        num *= (1 + multiple);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}