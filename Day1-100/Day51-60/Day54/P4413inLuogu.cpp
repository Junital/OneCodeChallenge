/***********************************************
 * 题目：[COCI2006-2007#2] R2
 * 描述：S = (R_1 + R_2) / 2，给定R_1和S，求R2。
 * 思路：普通计算，R2 = 2 * S - R1。
 * 函数：CalR2计算R2。
 * 注意：结果不能溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 给R1和S，计算R2。 */
int CalR2(int R1, int S)
{
    return 2 * S - R1;
}

int main()
{
    int r1, s;
    cin >> r1 >> s;
    cout << CalR2(r1, s) << endl;
}
