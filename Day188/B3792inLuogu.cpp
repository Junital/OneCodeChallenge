/***********************************************
 * 题目：[NICA #1] 年龄问题
 * 描述：已知爸爸的年龄和祖孙年龄差，求祖孙年龄。
 * 思路：简单加减法。
 * 函数：SonMotherAge计算祖孙年龄。
 * 注意：应该没什么问题。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

void SonMotherAge(int Age, int SonDiff, int MotherDiff)
{
    cout << Age - SonDiff << " " << MotherDiff + Age << endl;
}

int main()
{
    int age, sondiff, motherdiff;

    cin >> age >> sondiff >> motherdiff;

    SonMotherAge(age, sondiff, motherdiff);
    return 0;
}
