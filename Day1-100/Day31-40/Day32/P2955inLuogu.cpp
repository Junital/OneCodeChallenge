/***********************************************
 * 题目：[USACO09OCT] Even? Odd? G
 * 描述：输入数字，判断是奇数还是偶数。
 * 思路：数学常识。
 * 函数：JudgeOddEven判断是奇数还是偶数。
 * 注意：数字范围问题，不能用整型来存。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入一个数字的字符串，判断这个字符串代表的数字是奇数还是偶数。 */
void JudgeOddEven(string str)
{
    int len = str.size();
    if ((str[len - 1] - '0') % 2 == 0)
    {
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        JudgeOddEven(str);
    }
    return 0;
}