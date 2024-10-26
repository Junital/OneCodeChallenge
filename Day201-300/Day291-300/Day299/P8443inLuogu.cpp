/*****************************************************************
 * 题目：gcd.
 * 描述：求一个区间内的所有数的gcd。
 * 思路：测试，发现相邻数gcd必为1。
 * 对象：IntervalGCD模拟区间最大公因数。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

// /* 求最大公因数 */
// inline int gcd(int x, int y)
// {
//     if (y == 0)
//     {
//         return x;
//     }
//     return gcd(y, x % y);
// }

// void test()
// {
//     rep(i, 1, 100000)
//     {
//         if (gcd(i, i + 1) != 1)
//         {
//             cout << i << endl;
//         }
//     }
// }

template <typename T>
class IntervalGCD
{
private:
public:
    T query(T Begin, T End)
    {
        assert(End >= Begin);
        if (Begin == End)
        {
            return End;
        }
        return 1;
    }
};

int main()
{
    // test();
    int query_num;
    IntervalGCD<ll> igcd;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        ll begin, end, base;
        cin >> begin >> end >> base;
        cout << igcd.query(begin / base, end / base) << endl;
    }
    return 0;
}