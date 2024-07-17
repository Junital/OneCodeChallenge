/******************************************************
 * 题目：[NOIP2011 普及组] 数字反转
 * 描述：将数字反转，注意符号，前缀零。
 * 思路：利用to_string和stoi进行数字和字符串的转化。
 * 对象：NumberInverse模拟数字反转。
 * 注意：逻辑完备性。
 ******************************************************/

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
    int Num;
    NumberInverse ni;

    cin >> Num;
    cout << ni.inverse(Num) << endl;
    return 0;
}
