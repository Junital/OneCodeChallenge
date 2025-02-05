/*****************************************************************
 * 题目：[语言月赛202305] 制糊串
 * 描述：比较子串字典序。
 * 思路：封装一个子串获取函数。
 * 函数：get_sub_str模拟获取子串。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 输入子串的起始位置和终止位置，输出子串。 */
string get_sub_str(string str, int begin, int end)
{
    return str.substr(begin - 1, end - begin + 1);
}

int main()
{
    string a, b;
    cin >> a >> b;

    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int a_begin, a_end;
        int b_begin, b_end;

        cin >> a_begin >> a_end;
        cin >> b_begin >> b_end;

        string a_sub = get_sub_str(a, a_begin, a_end);
        string b_sub = get_sub_str(b, b_begin, b_end);

        if (a_sub < b_sub)
        {
            cout << "yifusuyi" << endl;
        }
        else if (a_sub > b_sub)
        {
            cout << "erfusuer" << endl;
        }
        else
        {
            cout << "ovo" << endl;
        }
    }
    return 0;
}
