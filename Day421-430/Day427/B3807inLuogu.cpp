/*****************************************************************
 * 题目：[语言月赛 202307] 塔台超频
 * 描述：计算塔台通信最大空隙。
 * 思路：遍历计算。
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
    int size;
    cin >> size;

    int max_gap = 0;
    int cur;
    cin >> cur;
    rep(i, 1, size - 1)
    {
        int range, next;
        cin >> range >> next;

        max_gap = max(next - (cur + range), max_gap);
        cur = next;
    }
    int range;
    cin >> range;
    cout << max_gap << endl;
    return 0;
}