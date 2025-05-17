/*****************************************************************
 * 题目：[语言月赛 202403] 传染病
 * 描述：给定传染系数，问几轮过后有多少感染者。
 * 思路：模拟+快速幂。
 * 对象：Infectious模拟传染。
 * 注意：注意取模，别溢出。
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

class Infectious
{
private:
    const int64_t Mod = 722733748;
    int64_t Coeff;

    /* 快速幂。 */
    int64_t pow(int64_t a, int64_t b)
    {
        int64_t res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = res * a % Mod;
            a = a * a % Mod;
            b >>= 1;
        }
        return res;
    }

public:
    /* 初始化，输入传染系数。 */
    Infectious(int64_t coeff) : Coeff(coeff) {}

    /* 计算累乘。 */
    int64_t mul_accum(int64_t init, int64_t day_left)
    {
        int64_t cur = pow(init, day_left);
        rep(i, 1, day_left - 1)
        {
            cur = cur * pow(Coeff, i) % Mod;
        }
        return cur;
    }
};

int main()
{
    i64 day_num, init, coeff;
    cin >> day_num >> init >> coeff;
    Infectious infectious(coeff);

    cout << infectious.mul_accum(init, day_num) << endl;
    return 0;
}