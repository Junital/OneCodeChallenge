/*****************************************************************
 * 题目：喵喵喵幼儿园
 * 描述：找到不是eat的字符串。
 * 思路：提取字符串并判断。
 * 空间：StringExtensions模拟字符串拓展。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

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

    /* 将字符串转化为一组数字。 */
    vector<ll> to_longlong(string str)
    {
        int size = str.size();
        vector<ll> res;

        int idx = 0;
        while (idx < size)
        {
            if (str[idx] >= '0' && str[idx] <= '9')
            {
                ll num = 0;
                while (str[idx] >= '0' && str[idx] <= '9')
                {
                    num = num * 10 + (str[idx] - '0');
                    idx++;
                }
                res.push_back(num);
            }
            else
            {
                idx++;
            }
        }

        return res;
    }

    class SubStrCnt
    {
    private:
        /* 前缀函数。 */
        vector<int> prefix_function(string s)
        {
            int n = (int)s.length();
            vector<int> pi(n);
            for (int i = 1; i < n; i++)
            {
                int j = pi[i - 1];
                while (j > 0 && s[i] != s[j])
                    j = pi[j - 1];
                if (s[i] == s[j])
                    j++;
                pi[i] = j;
            }
            return pi;
        }

    public:
        /* 统计。 */
        int count_occurrences(string text, string pattern)
        {
            string cur = pattern + '#' + text;
            int sz1 = text.size(), sz2 = pattern.size();
            int count = 0;
            vector<int> lps = prefix_function(cur);
            for (int i = sz2 + 1; i <= sz1 + sz2; i++)
            {
                if (lps[i] == sz2)
                    count++;
            }
            return count;
        }
    };
}

int main()
{
    regex pattern(R"(([a-z]+) or ([a-z]+)?)");
    const string eat = "eat";
    const string none = "or";

    int query_num;
    cin >> query_num;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    rep(i, 1, query_num)
    {
        string str;
        getline(cin, str);

        auto begin = sregex_iterator(str.begin(), str.end(), pattern);
        auto end = sregex_iterator();

        bool flag = false;
        for (auto it = begin; it != end; ++it)
        {
            if (flag)
            {
                break;
            }
            smatch sm = *it;
            int sm_size = sm.size();
            rep(j, 1, sm_size - 1)
            {
                string s = sm[j].str();
                if (s != eat)
                {
                    cout << s << endl;
                    flag = true;
                    break;
                }
            }
        }

        if (!flag)
        {
            cout << none << endl;
        }
    }
    return 0;
}