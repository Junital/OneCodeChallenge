/***********************************************
 * 题目：【深基4.例11】数列求和
 * 描述：输入一个数字，求出1到这个数字的累加和。
 * 思路：n*(n+1)/2。
 * 函数：NumSeqSum计算数列求和。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

int NumSeqSum(int MaxNum)
{
    return MaxNum * (MaxNum + 1) / 2;
}

int main()
{
    int maxnum;

    cin >> maxnum;

    cout << NumSeqSum(maxnum) << endl;

    return 0;
}
