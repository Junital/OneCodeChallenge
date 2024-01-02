/************************************************************
 * 题目：【深基7.习8】猴子吃桃
 * 要求：猴子每天吃一半的桃子再加一个，告诉你第几天吃剩一个的，要求计算本来多少桃子。
 * 作者：Junital
 * 思路：x - (x/2 + 1) = x/2 - 1 = i, x = 2 * (i + 1)
 * 对象：CompPeaches计算本来的桃子，BackOneDay用于回溯一天
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速循环

/* 输入现在的桃子数量，返回前一天的桃子数量 */
int BackOneDay(int curPeachNum)
{
    return 2 * (curPeachNum + 1); // 按照思路所说的计算
}

/* 输入吃桃子的天数，返回原来的桃子数 */
int CompPeaches(int dayNum)
{
    int peachesNum = 1; // 目前的桃子数，随着天数回溯更新
    rep(i, 1, dayNum - 1)
    {
        peachesNum = BackOneDay(peachesNum);
    }
    return peachesNum;
}

int main()
{
    int dayNum; // 天数
    cin >> dayNum;
    cout << CompPeaches(dayNum) << endl;
    return 0;
}
