/*****************************************************************
 * 题目：[语言月赛202212] 不可以，总司令
 * 描述：根据Yes和No的概率，判断应该选择哪个选项。
 * 思路：比较大小即可。
 * 空间：Tools模拟工具包。
 * 注意：输出字符串有一些要求。
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
    int yes_prob, no_prob;
    cin >> no_prob >> yes_prob;

    if (yes_prob > no_prob)
    {
        cout << "Yes" << endl;
    }
    else if (yes_prob < no_prob)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "equal probability" << endl;
    }
    return 0;
}