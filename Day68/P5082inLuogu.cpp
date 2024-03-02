/***********************************************
 * 题目：成绩
 * 描述：输入各科成绩和满分成绩，输出其综合成绩。
 * 思路：数学计算。
 * 对象：ScoreModel计算综合成绩。
 * 注意：空间限制，不能开数组了。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class ScoreModel
{
private:
    ll FullScoreSum; // 各科满分总和
    ll SelfScoreSum; // 个人成绩总分

public:
    /* 初始化，输入科目数量。 */
    ScoreModel(int SubNum)
    {
        FullScoreSum = 0;
        SelfScoreSum = 0;

        rep(i, 1, SubNum)
        {
            ll score;
            cin >> score;
            FullScoreSum += score;
        }

        rep(i, 1, SubNum)
        {
            ll score;
            cin >> score;
            SelfScoreSum += score;
        }
    }

    /* 获得综合分数。 */
    double getAggreScore()
    {
        ll LackScoreSum = FullScoreSum - SelfScoreSum;

        double top = FullScoreSum * 3 - SelfScoreSum * 2;

        return top / LackScoreSum;
    }
};

int main()
{
    int subnum;
    cin >> subnum;

    ScoreModel sm(subnum);

    cout << fixed << setprecision(6) << sm.getAggreScore() << endl;

    return 0;
}
