/***********************************************
 * 题目：手机
 * 描述：输入一个字符串，判断需要按几次键盘。
 * 思路：统计。
 * 对象：PhoneKeyBoard模拟手机九宫格键盘。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PhoneKeyBoard
{
private:
    map<char, int> ChTapTimes;

    void init()
    {
        ChTapTimes[' '] = 1;
        ChTapTimes['a'] = 1;
        ChTapTimes['b'] = 2;
        ChTapTimes['c'] = 3;
        ChTapTimes['d'] = 1;
        ChTapTimes['e'] = 2;
        ChTapTimes['f'] = 3;
        ChTapTimes['g'] = 1;
        ChTapTimes['h'] = 2;
        ChTapTimes['i'] = 3;
        ChTapTimes['j'] = 1;
        ChTapTimes['k'] = 2;
        ChTapTimes['l'] = 3;
        ChTapTimes['m'] = 1;
        ChTapTimes['n'] = 2;
        ChTapTimes['o'] = 3;
        ChTapTimes['p'] = 1;
        ChTapTimes['q'] = 2;
        ChTapTimes['r'] = 3;
        ChTapTimes['s'] = 4;
        ChTapTimes['t'] = 1;
        ChTapTimes['u'] = 2;
        ChTapTimes['v'] = 3;
        ChTapTimes['w'] = 1;
        ChTapTimes['x'] = 2;
        ChTapTimes['y'] = 3;
        ChTapTimes['z'] = 4;
    }

public:
    PhoneKeyBoard()
    {
        init();
    }

    /* 输入一串字符串，输出需要敲击的次数。 */
    int Tap(string Str)
    {
        int Sum = 0;

        for (auto ch : Str)
        {
            // cout << ch << endl;
            Sum += ChTapTimes[ch];
        }

        return Sum;
    }
};

int main()
{
    PhoneKeyBoard pkb;

    string str;
    getline(cin, str);
    cout << pkb.Tap(str) << endl;

    return 0;
}
