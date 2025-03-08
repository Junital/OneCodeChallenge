/*****************************************************************
 * 题目：[GXPC-S 2024] 数字谜题
 * 描述：求出二进制数字的最多连续1个数。
 * 思路：遍历。
 * 函数：longestConsecutiveOnes模拟连续1的个数。
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

template <typename T>
T longestConsecutiveOnes(T x)
{
    T max_count = 0;
    T current = 0;
    while (x != 0)
    {
        if (x & 1)
        {
            current++;
            max_count = std::max(max_count, current);
        }
        else
        {
            current = 0;
        }
        x >>= 1;
    }
    return max_count;
}

int main()
{
    int size;
    cin >> size;

    rep(i, 1, size)
    {
        ll query;
        cin >> query;
        cout << longestConsecutiveOnes(query) << endl;
    }
    return 0;
}