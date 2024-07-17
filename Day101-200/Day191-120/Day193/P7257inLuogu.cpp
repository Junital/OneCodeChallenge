/*********************************************************
 * 题目：[COCI2009-2010#3] FILIP
 * 描述：范围翻转数字后较大的那个。
 * 思路：借鉴P1307的内容。
 * 对象：NumberInverse模拟数字反转。
 * 注意：注意完备性。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class NumberInverse
{
private:
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

public:
    int inverse(int Num)
    {
        bool Negative = false;
        if (Num < 0)
        {
            Num *= -1;
            Negative = true;
        }

        string container = to_string(Num);
        container = getReverse(container);

        int Res = stoi(container);

        /* 还原负数。 */
        if (Negative)
        {
            Res *= -1;
        }

        return Res;
    }
};

int main()
{
    NumberInverse ni;

    int a, b;
    cin >> a >> b;
    cout << max(ni.inverse(a), ni.inverse(b)) << endl;
    return 0;
}
