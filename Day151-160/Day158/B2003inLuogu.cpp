/**********************************************************
 * 题目：输出第二个整数
 * 描述：输入三个数字，输出第二个整数。
 * 思路：忽略输入。
 * 函数：ignore_input用于忽略输入。
 * 注意：注意数据范围。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

void ignore_input()
{
    while (true)
    {
        char ch = cin.get();
        if (ch == ' ' || ch == '\n')
        {
            break;
        }
    }
}

int main()
{
    int Num;
    ignore_input();
    cin >> Num;
    ignore_input();
    cout << Num << endl;
    return 0;
}