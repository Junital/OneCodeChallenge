/***************************************************************
 * 题目：【深基6.例1】自动修正
 * 描述：将字符串的小写字母转为大写字母。
 * 思路：常识题。
 * 函数：fix_string用来修正字符串。
 * 注意：无。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

void fix_string(string &Str)
{
    int StrLen = Str.size();

    rep(i, 0, StrLen - 1)
    {
        if (Str[i] >= 'a' && Str[i] <= 'z')
        {
            Str[i] += ('A' - 'a');
        }
    }

    return;
}

int main()
{
    string Str;
    cin >> Str;

    fix_string(Str);
    cout << Str << endl;
    return 0;
}