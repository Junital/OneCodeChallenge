/***********************************************
 * 题目：最长连号
 * 描述：输入一串序列，找到最长的连号个数。
 * 思路：模拟。
 * 函数：LongestSeriNum来找到最长连号。
 * 注意：时间限制。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环

/* 输入一个数组表示数据序列，返回最长连续号数。 */
int LongestSeriNum(vector<int> Series)
{
    int Len = Series.size(); // 序列长度
    int Longest = 1;         // 最长连号(最小就是1)
    int TmpLong = 1;         // 临时连号，用于统计每一个连号

    rep(i, 1, Len - 1)
    {
        /* 思路：检查是否能连上，能连就继续连，不能就中止重新开始。 */
        if (Series[i] == Series[i - 1] + 1)
        {
            /* 能连上 */
            TmpLong++;
            Longest = max(Longest, TmpLong);
        }
        else
        {
            TmpLong = 1;
        }
    }

    return Longest;
}

int main()
{
    int N; // 序列长度
    vector<int> series;
    cin >> N;

    series.resize(N);

    rep(i, 0, N - 1)
    {
        cin >> series[i];
    }

    cout << LongestSeriNum(series) << endl;

    return 0;
}