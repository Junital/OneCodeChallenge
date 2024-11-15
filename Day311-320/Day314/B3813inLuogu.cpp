/*****************************************************************
 * 题目：[语言月赛 202308] 四个人的排名加起来没有小粉兔高
 * 描述：判断四个人的排名和与小粉兔的比较。
 * 思路：单行判断。
 * 对象：无。
 * 注意：里面的背景引以膜拜。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int main()
{
    const int PinkRabbit = 51;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a + b + c + d < PinkRabbit)
    {
        cout << "Rabbit wins" << endl;
    }
    else
    {
        cout << "Rabbit lose" << endl;
    }
    return 0;
}
