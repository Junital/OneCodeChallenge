/*************************************
 * 题目：[USACO1.1] 你的飞碟在这儿 Your Ride Is Here
 * 描述：输入两个字母串，如果名字对应的数字之积取模47一样，则输出GO，否则为STAY。
 * 思路：模拟判断和计算。
 * 对象：LetterToNum计算字母串对应的数字，CmpLetters比较两个字母串。
 *************************************/

#include <bits/stdc++.h>

using namespace std;

#define MOD 47       // 取模
#define ll long long // 定义长整型

/* 输入一个字符串，输出字符串对应的数字。 */
ll LetterToNum(string Letter)
{
    ll res = 1; // 计算的结果，初始为零
    for (auto ch : Letter)
    {
        res *= (ll)(ch - ('A' - 1));
    }
    return res;
}

/* 输入两个字符串，查看是否符合要求 */
void CmpLetters(string str1, string str2)
{
    ll num1 = LetterToNum(str1);
    ll num2 = LetterToNum(str2);

    if (num1 % MOD == num2 % MOD)
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }
    return;
}

int main()
{
    string UFO, Comm;
    cin >> Comm >> UFO;
    CmpLetters(Comm, UFO);
    return 0;
}
