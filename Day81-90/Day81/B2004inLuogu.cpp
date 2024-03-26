/***********************************************
 * 题目：对齐输出
 * 描述：输出三个数，每个数占据8位。
 * 思路：无。
 * 函数：AlignPrint对齐输出。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 输入三个数字，之后对齐输出。 */
void AlignPrint(int a, int b, int c)
{
    cout.setf(ios::right);
    cout << setw(8) << a << " " << setw(8) << b << " " << setw(8) << c << endl;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    AlignPrint(a, b, c);
    return 0;
}