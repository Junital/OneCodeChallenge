/*****************************************************************
 * 题目：[COCI2008-2009#1] SKOCIMIS
 * 描述：计算坐标之间的插空空间。
 * 思路：简单计算。
 * 函数：NumberGap计算数据空隙。
 * 注意：注意提升可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
T NumberGap(T A, T B)
{
    if (A > B)
    {
        swap(A, B);
    }
    return B - A - 1;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    cout << max(NumberGap(A, B), NumberGap(B, C)) << endl;
    return 0;
}