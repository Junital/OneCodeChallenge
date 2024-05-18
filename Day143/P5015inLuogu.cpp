/******************************************************
 * 题目：[NOIP2018 普及组] 标题统计
 * 描述：统计一个字符串除去空格后的长度。
 * 思路：STL erase。
 * 函数：realLen统计不算空格的长度。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int realLen(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    return str.length();
}

int main()
{
    string str;

    getline(cin, str);

    cout << realLen(str) << endl;
    return 0;
}
