/*********************************************
 * 题目：验证回文串
 * 描述：只考虑数字、字母，忽略大小写判断字符串是否回文。
 * 思路：预处理 + 倒转判断。
 * 对象：InvString模拟回文串。
 * 注意事项：预处理仔细点。
 ********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

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
    string str;
    InvString is;
    getline(cin, str);

    if (is.judge(str))
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}