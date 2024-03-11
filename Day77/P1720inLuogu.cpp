/***********************************************
 * 题目：月落乌啼算钱（斐波那契数列）
 * 描述：斐波那契数列。
 * 思路：存一个数组。
 * 函数：Fibonacci模拟斐波那契数列。
 * 注意：小心溢出情况。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

int Fibonacci(int Idx)
{
    vector<int> NumSeq;
    NumSeq.push_back(1);
    NumSeq.push_back(1);

    rep(i, 2, Idx - 1)
    {
        NumSeq.push_back(NumSeq[i - 1] + NumSeq[i - 2]);
    }

    return NumSeq[Idx - 1];
}

int main()
{
    int idx;
    cin >> idx;

    cout << fixed << setprecision(2) << (double)Fibonacci(idx) << endl;

    return 0;
}
