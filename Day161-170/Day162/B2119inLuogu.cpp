/**********************************************************
 * 题目：删除单词后缀
 * 描述：将最后ly、er、ing删除。
 * 思路：很难同时顾及三个，或许可以倒转字符串，然后子串查询。
 * 对象：WordSuffix模拟单词后缀。
 * 注意：注意拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class WordSuffix
{
private:
    vector<string> Suffixs;

    /* 反转字符串。 */
    string getReverse(string str)
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

        return rev;
    }

    /* 反转所有后缀。 */
    vector<string> reverse_suffix()
    {
        vector<string> RevSuff; // 反转字符串
        for (auto str : Suffixs)
        {
            string rev = getReverse(str);
            RevSuff.push_back(rev);
        }

        return RevSuff;
    }

    /* 判断是否含有前缀。 */
    bool hasSuffix(string revStr, string revSuff)
    {
        return revStr.find(revSuff) == 0;
    }

    /* 去除后缀 */
    void remove_suffix(string &revStr, int SuffixLen)
    {
        revStr.erase(0, SuffixLen);
    }

public:
    /* 初始化，输入后缀数组。 */
    WordSuffix(vector<string> suffixs) : Suffixs(suffixs) {}

    /* 输入字符串，输出去除后缀后的字符串。 */
    string refine_suffix(string Str)
    {
        string rev_str = getReverse(Str);
        vector<string> rev_suffix = reverse_suffix();

        for (auto suffix : rev_suffix)
        {
            if (hasSuffix(rev_str, suffix))
            {
                remove_suffix(rev_str, suffix.length());
                break;
            }
        }

        return getReverse(rev_str); // 再反转回来
    }
};

int main()
{
    vector<string> Suffixs;
    Suffixs.push_back("er");
    Suffixs.push_back("ly");
    Suffixs.push_back("ing");

    WordSuffix ws(Suffixs);

    string str;
    cin >> str;
    cout << ws.refine_suffix(str) << endl;
    return 0;
}
