/*****************************************************************
 * 题目：[CCC 2023 J1] Deliv-e-droid
 * 描述：送快递加钱，没送到减钱，成功比失败多有奖励。
 * 思路：直接计算。
 * 空间：Tools模拟工具包。
 * 注意：加一些常量，帮助理解代码。
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
    const int reward = 50;
    const int punishment = -10;
    const int bonus = 500;

    int success, fail;
    cin >> success >> fail;

    int balance = 0;
    balance += reward * success;
    balance += punishment * fail;

    if (success > fail)
    {
        balance += bonus;
    }

    cout << balance << endl;
    return 0;
}