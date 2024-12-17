/*****************************************************************
 * 题目：[COCI2009-2010#1] DOMINO
 * 描述：求出所有整数对的和。
 * 思路：公式计算。
 * 函数：AllSum模拟全部之和。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

int AllSum(int Num)
{
    return Num * (Num + 1) / 2 * (Num + 2);
}

int main()
{
    int num;
    cin >> num;
    cout << AllSum(num) << endl;
    return 0;
}