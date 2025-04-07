/*****************************************************************
 * 题目：[语言月赛 202312] 灵活控分
 * 描述：给出要应该的分数，问如何控分达到此分数。
 * 思路：见B3905 Solve。
 * 空间：Tools模拟工具包。
 * 注意：看一下前后阈值。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

int main()
{
    double a;
    cin >> a;

    double left_closed = pow(a / 10, 2);
    double right_opened = pow((a + 1) / 10, 2);

    cout << ceil(left_closed) << endl;
    return 0;
}