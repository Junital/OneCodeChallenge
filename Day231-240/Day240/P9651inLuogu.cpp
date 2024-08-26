/*****************************************************************
 * 题目：[SNCPC2019] Digit Product
 * 描述：计算逐位乘积。
 * 思路：拆分数字。
 * 函数：DigitProduct计算数位乘积。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class DigitProduct
{
private:
    const ll Mod = 1e9 + 7;

    /* 单数字计算乘积 */
    ll SingleNumber(ll Num)
    {
        ll Prod = 1;
        while (Num != 0)
        {
            ll Digit = Num % 10;
            Prod = (Prod * Digit) % Mod;
            Num /= 10;
        }
        return Prod;
    }

public:
    /* 区间数字乘积。 */
    ll IntervalProd(ll Begin, ll End)
    {
        ll Prod = 1;
        rep(i, Begin, End)
        {
            Prod = (Prod * SingleNumber(i)) % Mod;
            if (Prod == 0)
            {
                break;
            }
        }
        return Prod;
    }
};

int main()
{
    int query_num;
    DigitProduct dp;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        ll begin, end;
        cin >> begin >> end;

        cout << dp.IntervalProd(begin, end) << endl;
    }
    return 0;
}