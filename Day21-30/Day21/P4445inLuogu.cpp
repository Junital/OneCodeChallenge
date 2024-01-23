/************************************************************
 * 题目：[AHOI2018初中组] 报名签到
 * 要求：输入n个同学，每个同学希望前后和其他同学的不超过某个距离，求如何组织让队伍最小。
 * 作者：Junital
 * 思路：每次增加前后同学要求距离的最大值。
 * 函数：ArrangeQueue用于排序
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速排序
#define ll long long                              // 长整型

/* 给一个数组代表每位同学希望保持的距离，输出这个队伍最小的长度 */
ll ArrangeQueue(vector<int> Distance)
{
    ll QueueLen = 0;

    int QueueSize = Distance.size(); // 队伍的人数

    rep(i, 1, QueueSize - 1)
    {
        QueueLen += max(Distance[i], Distance[i - 1]); // 每次增加前后同学要求的最大值
    }

    return QueueLen;
}

int main()
{
    int StuNum;
    vector<int> StuDis;

    /* 输入部分 */
    cin >> StuNum;
    rep(i, 1, StuNum)
    {
        int Distance;
        cin >> Distance;
        StuDis.push_back(Distance);
    }

    cout << ArrangeQueue(StuDis) << endl; // 排列队伍
    return 0;
}