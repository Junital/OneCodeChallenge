/**********************************************************
 * 题目：打印字符
 * 描述：将数字转为对应的ASCII码。
 * 思路：类型转换。
 * 函数：Int2Char模拟int类型到char类型的转换。
 * 注意：封装好，增加拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

char Int2Char(int Num)
{
    return (char)Num;
}

int main()
{
    int num;
    cin >> num;
    cout << Int2Char(num) << endl;
    return 0;
}
