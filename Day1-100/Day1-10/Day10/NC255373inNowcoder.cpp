/************************************************************
 * 题目：游游的字符串构造
 * 要求：输入一个长度为n的字符串，中间只包含k个you子串
 * 作者：Junital
 * 思路：yyyyyou结构应该就行。
 * 函数：YouPrint打印结果，如果无法打印就输出-1。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 简便循环

/* 先判断是否有机会打印出来，如果没有机会就输出-1。之后再打印 */
void YouPrint(int str_len, int you_num)
{
    if (str_len < 3 * you_num) // 判断字符串的长度能不能容下这些数量的"you"
    {
        cout << -1 << endl;
        return;
    }

    /* 先输出you，再输出o补齐 */
    rep(i, 1, you_num)
    {
        cout << "you";
    }
    rep(i, 1, str_len - you_num * 3)
    {
        cout << "o";
    }
    cout << endl;
    return;
}

int main()
{
    int str_len; // 字符串的长度
    int you_num; // 包含“you”子串的数量

    cin >> str_len >> you_num;
    YouPrint(str_len, you_num); // 开始打印
    return 0;
}
