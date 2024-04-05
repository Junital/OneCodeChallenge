/************************************************************
 * 题目：umi的函数
 * 要求：给出一个输入字符串和一个输出字符串，判断输出字符串是否每一位都比输入字符串小。
 * 如果是，那么输出输出字符串。
 * 如果不是，那么输出-1即可。
 * 作者：Junital
 * 思路：比较简单，先判断是否可行，如果可行就输出那个输出字符串不就行了。
 * 函数：JudgeString比较字符串，输出对应的结果
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++)

int len;        // 字符串的长度
string str_in;  // 输入字符串
string str_out; // 输出字符串

/* 直接按位比较，如果每一位输出字符串都小于等于输入字符串，输出输出字符串，否则输出-1 */
void JudgeString()
{
    rep(i, 0, len - 1)
    {
        if (str_out[i] > str_in[i])
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << str_out << endl;
    return;
}

int main()
{
    cin >> len;
    cin >> str_in;
    cin >> str_out;

    JudgeString(); // 开始比较字符串

    return 0;
}
