/***************************************************************
 * 题目：小球
 * 描述：有等数量的小球和盒子，分为两个颜色。
        如果红色小球放入红色盒子，分数为RR。
        如果蓝色小球放入蓝色盒子，分数为BB。
        如果小球和盒子异色，那么分数为RB。
 * 思路：见P2705 Solve，数论规划。
 * 对象：BoxBall模拟小球放入盒子。
 * 注意：注意要把所有情况考虑在内。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class BoxBall
{
private:
    int RedNum;   // 红色小球和盒子的数量
    int BlueNum;  // 蓝色小球和盒子的数量
    int RRScore;  // 红色小球放入红色盒子的分数
    int BBScore;  // 蓝色小球放入蓝色盒子的分数
    int RBScore;  // 小球和盒子异色的分数
    int MaxScore; // 最大分数

    void plan()
    {
        if (2 * RBScore > RRScore + BBScore)
        {
            int MinNum = min(RedNum, BlueNum);
            MaxScore = MinNum * 2 * RBScore +
                       (RedNum - MinNum) * RRScore +
                       (BlueNum - MinNum) * BBScore;
        }
        else
        {
            MaxScore = RedNum * RRScore + BlueNum * BBScore;
        }
    }

public:
    /* 初始化，输入红色小球和盒子的数量、蓝色小球和盒子的数量、三种分数。 */
    BoxBall(int rednum, int bluenum, int rrscore, int bbscore, int rbscore)
        : RedNum(rednum), BlueNum(bluenum),
          RRScore(rrscore), BBScore(bbscore), RBScore(rbscore)
    {
        plan(); // 进行规划。
    }

    /* 获取最大分数 */
    int getMaxScore()
    {
        return MaxScore;
    }
};

int main()
{
    int rednum, bluenum, rrscore, bbscore, rbscore;
    cin >> rednum >> bluenum >> rrscore >> bbscore >> rbscore;

    BoxBall BB(rednum, bluenum, rrscore, bbscore, rbscore);
    cout << BB.getMaxScore() << endl;
    return 0;
}
