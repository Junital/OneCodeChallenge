/*****************************************************************
 * 题目：[语言月赛 202405] 交题解
 * 描述：将字符串中的非大小写字母去除。
 * 思路：遍历计算。
 * 空间：StringExtensions模拟字符串拓展。
 * 注意：注意提高可拓展性。
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

    /* 字符串替换。 */
    void replace_all(string &str, const string from, const string to)
    {
        if (from.empty())
        {
            return; // 如果子串为空，则直接返回原字符串
        }

        size_t pos = 0;

        // 使用循环找到所有匹配的子串并替换
        while ((pos = str.find(from, pos)) != std::string::npos)
        {
            str.replace(pos, from.length(), to);
            pos += to.length(); // 更新位置，避免死循环
        }
    }

    /* 去除非字母符号。 */
    void drop_non_letter(string &str)
    {
        string res;

        for (auto ch : str)
        {
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z'))
            {
                res += ch;
            }
        }

        str = res;
    }
}

int main()
{
    string Str;
    cin >> Str;

    StringExtensions::drop_non_letter(Str);
    cout << Str << endl;
    return 0;
}