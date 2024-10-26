/*****************************************************************
 * 题目：[语言月赛202209] Luogu Academic
 * 描述：问一个字符串中出现luogu几次？
 * 思路：KMP算法。
 * 对象：SubStrCnt模拟子串计数。
 * 注意：提高拓展空间。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

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

int main()
{
    SubStrCnt ssc;
    const string pattern = "luogu";
    string query;
    cin >> query;

    cout << ssc.count_occurrences(query, pattern) << endl;
    return 0;
}
