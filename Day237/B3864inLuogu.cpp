/*****************************************************************
 * 题目：[GESP202309 一级] 小明的幸运数
 * 描述：计算区间内的倍数、个位数和。
 * 思路：只要知道最大的和最小的就行。
 * 函数：IntervalLuckySum计算区间幸运数和。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 计算区间倍数和。 */
int IntervalLuckySum(int Base, int Begin, int End)
{
    int sum = 0;
    rep(i, Begin, End)
    {
        if (i % Base == 0 || i % 10 == Base)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int base, begin, end;
    cin >> base >> begin >> end;

    cout << IntervalLuckySum(base, begin, end) << endl;
    return 0;
}
