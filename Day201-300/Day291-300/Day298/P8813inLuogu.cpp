/*****************************************************************
 * 题目：[CSP-J 2022] 乘方
 * 描述：在次幂的基础上如果超过阈值，直接输出-1。
 * 思路：快速幂 + 实时判断。
 * 对象：LimitPow模拟限制快速幂。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

class LimitPow
{
private:
    int Limit; // 限制

public:
    /* 初始化，输入模数。 */
    LimitPow(int limit) : Limit(limit) {}

    /* 快速幂。 */
    ll pow(ll a, ll b)
    {
        ll res = 1;
        // cout << a << " " << b << " " << res << endl;
        while (b > 0)
        {
            if (b & 1)
            {
                res = res * a;
                // cout << a << " " << res << endl;
            }
            a = a * a;
            b >>= 1;
            // cout << a << " " << b << endl;
            if (res > Limit || (a > Limit && b > 0))
            {
                return -1;
            }
        }
        return res;
    }
};

int main()
{
    const int limit = 1e9;
    LimitPow lp(limit);

    ll a, b;
    cin >> a >> b;
    // cout << a << " " << b << endl;
    cout << lp.pow(a, b) << endl;
    return 0;
}