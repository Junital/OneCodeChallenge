/*****************************************************************
 * 题目：[语言月赛202208] 求和
 * 描述：依次输出从1到n的和。
 * 思路：遍历。
 * 空间：Tools模拟工具包。
 * 注意：使用“\n”代替“endl”，最终答案得int64存储。
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
    int n;
    cin >> n;
    i64 sum = 0;

    rep(i, 1, n)
    {
        sum += i;
        cout << sum << "\n";
    }
    return 0;
}