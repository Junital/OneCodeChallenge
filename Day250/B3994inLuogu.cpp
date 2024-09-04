/*****************************************************************
 * 题目：[洛谷 202406GESP 模拟 二级] 周长与面积计算
 * 描述：输入正方形的数量，输出多个正方形面积、周长累加。
 * 思路：周长取决于边长，面积取决于边长平方。
 * 对象：SquareSequence模拟正方形序列。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (ll i = s; i <= k; i++) // 定义快速循环
#define ll long long                             // 定义长整型

class SquareSequence
{
private:
public:
    /* 输入正方形数量，输出边长和面积。 */
    pair<ll, ll> calculate(ll Num)
    {
        ll LenSum = 0;
        ll SuqareSum = 0;

        rep(i, 1, Num)
        {
            LenSum += i;
            SuqareSum += i * i;
        }

        return make_pair(LenSum * 2 + Num * 2, SuqareSum);
    }
};

int main()
{
    ll num;
    SquareSequence ss;

    cin >> num;
    auto res = ss.calculate(num);
    cout << res.first << endl;
    cout << res.second << endl;
    return 0;
}