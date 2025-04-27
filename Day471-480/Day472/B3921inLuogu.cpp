/*****************************************************************
 * 题目：[GESP202312 一级] 小杨的考试
 * 描述：从1开始的mod。
 * 思路：简单判断即可。
 * 函数：ModFrom1模拟从1开始的Mod。
 * 注意：提高可拓展性。
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

template <typename T>
T ModFrom1(T Num, T Mod)
{
    T ans = Num % Mod;

    if (ans == 0)
    {
        ans = Mod;
    }

    return ans;
}

int main()
{
    const int mod = 7;
    int a, b;

    cin >> a >> b;
    cout << ModFrom1(a + b, mod) << endl;
    return 0;
}