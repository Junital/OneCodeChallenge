/*****************************************************************
 * 题目：[洛谷 202406GESP 模拟 三级] 小洛的字符串分割
 * 描述：分割字符串，并判断回文串数量。
 * 思路：先分割，再判断。
 * 对象：StringSplit模拟字符串分割。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class StringSplit
{
private:
public:
    /* 递增分割。 */
    vector<string> increment_split(string str)
    {
        int size = str.size();
        int len = 1;
        int idx = 0;

        vector<string> res;
        while (true)
        {
            if (idx >= size)
            {
                break;
            }
            if (idx + len - 1 > size)
            {
                res.push_back(str.substr(idx));
                break;
            }
            res.push_back(str.substr(idx, len));
            idx += len;
            len++;
        }

        return res;
    }
};

class InvString
{
private:
    /* 预处理 */
    string preprocess(string Str)
    {
        string res;
        for (auto ch : Str)
        {
            if (ch >= 'A' && ch <= 'Z') // 大写转小写
            {
                res += ch + ('a' - 'A');
            }
            /* 保留小写和数字，其他都删去 */
            else if (ch >= 'a' && ch <= 'z')
            {
                res += ch;
            }
            else if (ch >= '0' && ch <= '9')
            {
                res += ch;
            }
        }

        return res;
    }

    /* 字符串倒置。 */
    string inv(string Str)
    {
        string res;
        stack<char> container;

        for (auto ch : Str)
        {
            container.push(ch);
        }

        while (!container.empty())
        {
            res += container.top();
            container.pop();
        }

        return res;
    }

public:
    /* 判断是否为回文串。 */
    bool judge(string Str)
    {
        Str = preprocess(Str);
        // cout << "Preprocess: " << Str << endl;
        string inv_str = inv(Str);
        // cout << "Inv: " << inv_str << endl;

        return inv_str == Str;
    }
};

int main()
{
    string Str;
    StringSplit ss;
    InvString is;
    cin >> Str;

    auto res = ss.increment_split(Str);
    int count = 0;
    for (auto s : res)
    {
        // cout << s << endl;
        if (is.judge(s))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}