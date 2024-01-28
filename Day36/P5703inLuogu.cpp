/***********************************************
 * 题目：简单乘法。
 * 描述：输入两个数，输出两个数的乘法。
 * 函数：Multi乘法。
 * 注意：注意溢出问题。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入两个数，输出两个数的相乘 */
int Multi(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << Multi(a, b) << endl;
}