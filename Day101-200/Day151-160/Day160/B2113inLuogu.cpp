/**********************************************************
 * 题目：输出亲朋字符串
 * 描述：生成的字符为相邻两个字符的ASCII码相加。
 * 思路：遍历一次即可。
 * 函数：friend_string模拟亲朋字符串。
 * 注意：小心空格坑你。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

string friend_string(string Str)
{
    int Len = Str.length();
    string res; // 答案

    rep(i, 0, Len - 2)
    {
        res += (Str[i] + Str[i + 1]);
    }

    res += Str[0] + Str[Len - 1];

    return res;
}

int main()
{
    string str;
    getline(cin, str);

    cout << friend_string(str) << endl;
    return 0;
}