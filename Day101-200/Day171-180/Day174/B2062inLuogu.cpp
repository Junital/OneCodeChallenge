/**********************************************************
 * 题目：乘方计算
 * 描述：计算a的b次方。
 * 思路：快速幂。
 * 函数：binpow模拟快速幂。
 * 注意：注意数据范围。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 快速幂 */
int binpow(int a, int b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << binpow(a, b) << endl;
    return 0;
}