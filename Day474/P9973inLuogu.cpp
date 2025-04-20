/*****************************************************************
 * 题目：[THUPC 2024 初赛] 你说得对，但是 AIGC
 * 描述：判断字符串是否以“你说得对，但是”开头。
 * 思路：字符串拓展。
 * 空间：StringExtensions模拟字符串拓展。
 * 注意：保持可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

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

    // 是否开始于某个子串。
    bool start_with(const string &str, const string &prefix)
    {
        return str.size() >= prefix.size() &&
               str.substr(0, prefix.size()) == prefix;
    }
}

using namespace StringExtensions;

int main()
{
    const string AI_prefix = "You are right, but ";

    string str;
    getline(cin, str);

    if (start_with(str, AI_prefix))
    {
        cout << "AI" << endl;
    }
    else
    {
        cout << "Human" << endl;
    }
    return 0;
}