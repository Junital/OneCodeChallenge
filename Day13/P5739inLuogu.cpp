/************************************************************
 * 题目：【深基7.例7】计算阶乘
 * 要求：输入一个数，输出它的阶乘
 * 作者：Junital
 * 思路：挑战，不适用循环，用递归试试。
 * 对象：multiX计算阶乘
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输出为一个数的阶乘，比如2!=2*1=2 */
int multiX(int x)
{
    if (x == 1)
    {
        return 1;
    }
    return x * multiX(x - 1); // n! = n * (n - 1)!
}

int main()
{
    int n;

    cin >> n;

    cout << multiX(n) << endl;
}