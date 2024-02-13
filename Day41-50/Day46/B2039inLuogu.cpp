/***********************************************
 * 题目：整数大小比较
 * 描述：比较两个整数，输出<、>、=
 * 思路：简单比较。
 * 函数：CmpLongLong比较整数。
 * 注意：小心别溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 快速定义长整型

/* 输入两个长整型，输出>、<、= */
char CmpLongLong(ll X, ll Y)
{
    if (X < Y)
    {
        return '<';
    }
    else if (X > Y)
    {
        return '>';
    }
    else
    {
        return '=';
    }
}

int main()
{
    ll X, Y;

    cin >> X >> Y;

    cout << CmpLongLong(X, Y) << endl;
    return 0;
}