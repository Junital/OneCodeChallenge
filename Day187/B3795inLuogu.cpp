/***********************************************
 * 题目：[NICA #1] 成绩
 * 描述：输入各科成绩以及权重，求出传统得分和创新得分。
 * 思路：数学计算。
 * 对象：ScoreModel计算综合成绩。
 * 注意：注意计算复杂度。
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

    /* 空构造器。 */
    ScoreModel() {}

    /* 获得综合分数，适用于已经在构造的时候已经有成绩了。 */
    double getAggreScore()
    {
        assert(FullScoreSum != 0 && SelfScoreSum != 0);
        ll LackScoreSum = FullScoreSum - SelfScoreSum;

        double top = FullScoreSum * 3 - SelfScoreSum * 2;

        return top / LackScoreSum;
    }

    /* 判断不及格的科目是否小于等于阈值。 */
    bool JudgeFailNum(vector<int> Scores, int PassLine, int Threshold)
    {
        int fail_num = 0; // 不及格数量
        for (auto s : Scores)
        {
            if (s < PassLine)
            {
                fail_num++;
            }
        }

        return fail_num <= Threshold;
    }

    /* 计算加权平均分。 */
    double WeightedScore(vector<int> Scores, vector<double> Weights)
    {
        assert(Scores.size() == Weights.size());

        int LessonNum = Scores.size();
        double FinalScore = 0;
        double WeightSum = 0;

        rep(i, 0, LessonNum - 1)
        {
            FinalScore += Scores[i] * Weights[i];
            WeightSum += Weights[i];
        }

        return FinalScore / WeightSum;
    }
};

int main()
{
    const int PassLine = 60;
    const int ConvenThres = 1;
    const int LessonNum = 3;
    vector<int> Scores(LessonNum);
    vector<double> Weights(LessonNum);

    ScoreModel sm;

    rep(i, 0, LessonNum - 1)
    {
        cin >> Scores[i];
    }
    rep(i, 0, LessonNum - 1)
    {
        cin >> Weights[i];
    }

    if (sm.JudgeFailNum(Scores, PassLine, ConvenThres))
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    if (sm.WeightedScore(Scores, Weights) > PassLine)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    return 0;
}
