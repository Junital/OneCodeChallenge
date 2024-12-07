/*****************************************************************
 * 题目：「QFOI R1」贴贴
 * 描述：将字符串小写，替换，加入前缀。
 * 思路：字符串拓展。
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
}

int main()
{
    const string prefix = "solution-";
    string str;
    cin >> str;

    StringExtensions::toLowerCase(str);
    StringExtensions::replace_all(str, "_", "-");
    str = prefix + str;

    cout << str << endl;
    return 0;
}
