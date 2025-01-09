/*****************************************************************
 * 题目：最大公约数
 * 描述：求最大公约数。
 * 思路：已经有现成的函数了。
 * 函数：gcd模拟最大公因数、
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 求最大公因数 */
template <typename T>
inline T gcd(T x, T y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}