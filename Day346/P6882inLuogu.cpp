/*****************************************************************
 * 题目：[COCI2016-2017#3] Imena
 * 描述：给定一些句子，输出首字母为大写字母的单词个数。
 * 思路：字符串拓展业务。
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

    /* 划分句子（按照结束符号）。 */
    vector<string> split_sentences(string &str)
    {
        vector<string> sentences;
        regex regex(R"([^.!?]+[.!?])");
        auto begin = sregex_iterator(str.begin(), str.end(), regex);
        auto end = sregex_iterator();

        for (auto it = begin; it != end; ++it)
        {
            sentences.push_back(it->str());
        }

        return sentences;
    }

    /* 找到首字母大写的单词。 */
    vector<string> find_capital_word(string &str)
    {
        vector<string> cap_words;
        regex regex(R"(\b[A-Z][a-z]*\b)");

        auto begin = sregex_iterator(str.begin(), str.end(), regex);
        auto end = sregex_iterator();
        for (auto it = begin; it != end; ++it)
        {
            cap_words.push_back(it->str());
        }

        return cap_words;
    }
}

int main()
{
    string size;
    getline(cin, size);

    string str;
    getline(cin, str);

    vector<string> sentences =
        StringExtensions::split_sentences(str);

    for (auto sen : sentences)
    {
        cout << StringExtensions::
                    find_capital_word(sen)
                        .size()
             << endl;
    }
    return 0;
}