/***********************************************
 * 题目：[COCI2010-2011#1] TIMSKO
 * 描述：一个队伍需要1名男生、2名女生，现在有一定数量的女生和男生，需要去实习一批人，问最多能组几个队伍。
 * 思路：简单规划。
 * 函数：CalTeamNum计算队伍的数量。
 * 注意：各种情况都要考虑到。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

#define GIRL 2
#define BOY 1

/* 输入男生的个数，女生的个数，调离的人数。输出最多队伍的个数。 */
int CalTeamNum(int Boys, int Girls, int Leave)
{
    int NowMax = min(Boys, Girls / GIRL);               // 目前可以组的队伍数量
    int Empty = (Boys + Girls) - NowMax * (BOY + GIRL); // 计算可以闲置的人

    if (Leave <= Empty)
    {
        return NowMax;
    }
    else
    {
        int Cut = ceil((Leave - Empty) * 1.0 / (BOY + GIRL)); // 必须裁剪的队伍个数
        return NowMax - Cut;
    }
}

int main()
{
    int Girls, Boys, Leave;

    cin >> Girls >> Boys >> Leave;

    cout << CalTeamNum(Boys, Girls, Leave) << endl;
    return 0;
}