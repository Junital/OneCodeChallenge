/*****************************************************************
 * 题目：[蓝桥杯 2024 省 Java B] 报数游戏
 * 描述：报出第202420242024个被20或24整除的数。
 * 思路：找规律。
 * 函数：print20or24模拟输出报数。
 * 注意：注意数据别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

void print20or24()
{
    const int Num = 20;
    int cnt = 0;
    int i = 1;
    while (cnt < Num)
    {
        if (i % 20 == 0 || i % 24 == 0)
        {
            cnt++;
            cout << i << " ";
        }
        i++;
    }
}

int main()
{
    // print20or24();

    ll x = 202420242024;
    cout << 24 * (x / 10 * 5 + 2) << endl;
    return 0;
}
