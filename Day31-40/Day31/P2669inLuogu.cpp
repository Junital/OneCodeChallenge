/***********************************************
 * 题目：[NOIP2015 普及组] 金币
 * 描述：第一天收到一个金币，后面两天收到两个金币，再后面三天收到三个金币，以此类推，问几天后收到几个金币？
 * 思路：模拟。
 * 函数：getCoins计算获得的金币。
 * 注意：溢出问题。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

ll getCoins(int Days)
{
    ll Coins = 0;    // 初始的金币数为0
    int i = 1;       // 天数计数器
    int dayCoin = 1; // 每天应得的金币

    while (true)
    {
        /* 模拟加入每天应得的金币 */
        for (int j = 1; j <= dayCoin; j++)
        {
            if (i > Days)
            {
                break;
            }
            Coins += dayCoin;
            i++;
        }
        if (i > Days)
        {
            break;
        }
        dayCoin++;
    }

    return Coins;
}

int main()
{
    int Days; // 天数

    cin >> Days;

    cout << getCoins(Days) << endl;

    return 0;
}