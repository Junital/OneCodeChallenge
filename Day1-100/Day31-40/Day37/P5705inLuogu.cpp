/***********************************************
 * 题目：【深基2.例7】数字反转
 * 描述：反转字符串
 * 思路：用一个栈来维护。
 * 函数：getReverse获得字符串的反转。
 * 注意：注意前缀0问题。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    string str;
    cin >> str;
    cout << getReverse(str) << endl;
}