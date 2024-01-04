/************************************************************
 * 题目：输出保留 3 位小数的浮点数
 * 要求：输入一个浮点数，输出保留3位小数的浮点数。
 * 作者：Junital
 * 思路：尝试使用cout试试
 * 函数：无
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    float num; // 输入的浮点数

    cin >> num;

    cout << fixed << setprecision(3) << num << endl;

    return 0;
}
