/*****************************************************************
 * 题目：「Daily OI Round 3」Simple
 * 描述：判断字符串的字母是否完全相同。
 * 思路：全部小写化。
 * 空间：StringExtension模拟字符串拓展。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace StringExtensions
{
    /* 字符串小写 */
    void toLowerCase(string &str)
    {
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
                  { return tolower(c); });
    }

    /* 字符串翻转 */
    void toReverse(string &str)
    {
        string rev;       // 逆转后的字符串
        stack<char> chst; // 存储char的栈

        for (auto ch : str)
        {
            chst.push(ch);
        }

        while (!chst.empty())
        {
            rev.push_back(chst.top());
            chst.pop();
        }

        str = rev;
    }
}

int main()
{
    string A = "Svpoll";
    string B = "Acoipp";

    string C;
    cin >> C;

    StringExtensions::toLowerCase(A);
    StringExtensions::toLowerCase(B);
    StringExtensions::toLowerCase(C);

    if (A == C)
    {
        cout << "Genshin" << endl;
    }
    else if (B == C)
    {
        cout << "Luogu" << endl;
    }
    else
    {
        cout << "Boring" << endl;
    }
    return 0;
}