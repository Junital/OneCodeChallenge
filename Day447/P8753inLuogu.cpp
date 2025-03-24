/*****************************************************************
 * 题目：[蓝桥杯 2021 省 AB2] 小平方
 * 描述：求出小于某个数的平方，并对这个数取模，取模后小于这个数一半的数量。
 * 思路：遍历一下。
 * 空间：Tools模拟工具包。
 * 注意：当心溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

int main()
{
    int num;
    cin >> num;

    int cnt = 0;
    rep(i, 1, num - 1)
    {
        if ((i % num) * (i % num) % num <= // 这里是为了防止溢出。
            num / 2 - (num % 2 == 0))      // 这里奇数和偶数的情况不同。
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}