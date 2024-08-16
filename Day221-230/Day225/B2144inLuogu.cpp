/*****************************************************************
 * 题目：阿克曼（Ackermann）函数
 * 描述：定义一个阿克曼函数，进行模拟。
 * 思路：简单模拟。
 * 函数：Ackermann模拟阿克曼函数。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/**************************************************
 * 计算规则：
 * m = 0, akm(m, n) = n + 1
 * m > 0, n = 0, akm(m, n) = akm(m - 1, 1)
 * m, n > 0, akm(m, n) = akm(m - 1, akm(m, n - 1))
 *************************************************/

int Ackermann(int A, int B)
{
    if (A > 0 && B > 0)
    {
        return Ackermann(A - 1, Ackermann(A, B - 1));
    }
    else if (B == 0)
    {
        return Ackermann(A - 1, 1);
    }
    else
    {
        return B + 1;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << Ackermann(a, b) << endl;
    return 0;
}
