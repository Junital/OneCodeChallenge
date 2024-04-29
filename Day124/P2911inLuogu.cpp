/***************************************************************
 * 题目：[USACO08OCT] Bovine Bones G
 * 描述：求三个色子的点数之和最有可能是多少。
 * 思路：算了一下就均值相加即可。
        没有这么简单，应该是在两个之和的基础上再增加一个进行尝试。
        三个色子的顺序也得讲究，因为目前考虑的情报还不包括c比b+a+1长的情况。
        见P2911 Solve。
 * 对象：ThreeDiceSum模拟三个色子之和。
 * 注意：无。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ThreeDiceSum
{
private:
    int Dice1, Dice2, Dice3; // 三个色子的面数
    int MaxSum;              // 最可能的点数之和

public:
    /* 初始化，输入三个色子的面数。 */
    ThreeDiceSum(int dice1, int dice2, int dice3)
        : Dice1(dice1), Dice2(dice2), Dice3(dice3)
    {
    }

    /* 获得最可能的点数之和。 */
    int getMaxSum()
    {
        int MinDice = min(min(Dice1, Dice2), Dice3);
        int MaxDice = max(max(Dice1, Dice2), Dice3);
        int MidDice = (Dice1 + Dice2 + Dice3) - (MinDice + MaxDice);

        if (MidDice <= MaxDice - MinDice + 1)
        {
            return MinDice + MidDice + 1;
        }
        else
        {
            int LeftPart = 1 + (MidDice - (MaxDice - MinDice + 1)) / 2;
            int RightPart = 1 + MaxDice;
            return LeftPart + RightPart;
        }
    }
};

int main()
{
    int dice1, dice2, dice3;
    cin >> dice1 >> dice2 >> dice3;

    ThreeDiceSum tds(dice1, dice2, dice3);
    cout << tds.getMaxSum() << endl;
    return 0;
}