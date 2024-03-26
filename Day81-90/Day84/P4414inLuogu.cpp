/***********************************************
 * 题目：[COCI2006-2007#2] ABC
 * 描述：给定三个数的顺序。
 * 思路：比较。
 * 函数：ABC模拟比较。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 输入三个数，输入输出顺序。 */
void ABC(int a, int b, int c, string order)
{
    map<char, int> ABC;

    ABC['A'] = min(c, min(a, b));
    ABC['C'] = max(c, max(a, b));
    ABC['B'] = a + b + c - ABC['A'] - ABC['C']; // 中间小的数

    for (auto ch : order)
    {
        cout << ABC[ch] << " ";
    }
    cout << endl;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    string order;
    cin >> order;

    ABC(a, b, c, order);

    return 0;
}