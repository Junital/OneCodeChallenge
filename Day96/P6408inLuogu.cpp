/***********************************************
 * 题目：[COCI2008-2009#3] PET
 * 描述：美食评委对选手打分，给出选手对应的每位评委的分数，
        求出得分最高的选手编号，以及对应分数。
 * 思路：统计。
 * 对象：FoodMatchJudge模拟美食比赛评审。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class FoodMatchJudge
{
private:
    vector<vector<int>> Scores; // 每一行代表选手，每一列代表某个评委的打分。
    int PlayerNum, JudgeNum;    // 选手人数和评委人数

public:
    /* 初始化，输入选手人数和评委人数。 */
    FoodMatchJudge(int playernum, int judgenum) : PlayerNum(playernum), JudgeNum(judgenum)
    {
        Scores.resize(PlayerNum + 1);

        rep(i, 1, PlayerNum)
        {
            Scores[i].resize(JudgeNum + 1);

            rep(j, 1, JudgeNum)
            {
                cin >> Scores[i][j];
            }
        }
    }

    /* 返回一个pair，编号 + 对应分数。 */
    pair<int, int> FindWinner()
    {
        int MaxScoreSum = 0; // 最高分数
        int MaxIdx = -1;     // 最高分数对应的玩家
        rep(i, 1, PlayerNum)
        {
            int scoresum = 0;
            rep(j, 1, JudgeNum)
            {
                scoresum += Scores[i][j];
            }

            if (scoresum > MaxScoreSum)
            {
                MaxScoreSum = scoresum;
                MaxIdx = i;
            }
        }

        return make_pair(MaxIdx, MaxScoreSum);
    }
};

int main()
{
    const int playernum = 5;
    const int judgenum = 4;

    FoodMatchJudge fmj(playernum, judgenum);

    pair<int, int> winner = fmj.FindWinner();

    cout << winner.first << " " << winner.second << endl;
    return 0;
}
