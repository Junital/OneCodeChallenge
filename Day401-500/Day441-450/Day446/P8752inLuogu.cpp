/*****************************************************************
 * 题目：[蓝桥杯 2021 省 B2] 特殊年份
 * 描述：输入5个四位数年份，判断是否是特殊年份。
 * 思路：按照字符串处理。
 * 空间：Tools模拟工具包
 * 注意：注意字符串处理。
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
    const int size = 5;
    string year;

    int cnt = 0;
    rep(i, 1, size)
    {
        cin >> year;
        /* 年份长度固定为4。 */
        if (year.size() != 4)
        {
            throw runtime_error("Invalid year size.");
        }

        /* 判断是否都为数字。 */
        for (auto ch : year)
        {
            if (!isdigit(ch))
            {
                throw runtime_error("Invalid year format.");
            }
        }

        /* 判断是否为特殊年份（千位与十位相同、个位比百位多1）。 */
        if (year[0] == year[2] && year[3] == year[1] + 1)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}