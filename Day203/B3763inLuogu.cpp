/*********************************************************
 * 题目：[语言月赛202305] 团体程序设计天梯赛
 * 描述：分数阶梯，打到指定分数线才能算下一阶段的分数。
 * 思路：分层计算。
 * 对象：MultiLevelScore模拟分数阶梯。
 * 注意：注意拓展性。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class MulitiLevelScore
{
private:
    int LevelNum;           // 层级数量
    vector<int> Thresholds; // 每个层级的要求

public:
    /* 初始化，输入每个阶段的要求。 */
    MulitiLevelScore(vector<int> thresholds) : Thresholds(thresholds)
    {
        LevelNum = Thresholds.size() + 1;
    }

    /* 输入多层数组，输出总数。 */
    int summary(vector<vector<int>> scores)
    {
        assert(Thresholds.size() + 1 == scores.size());
        int summary = 0;

        rep(i, 0, LevelNum - 1)
        {
            vector<int> level_score = scores[i];
            int thres;
            if (i != LevelNum)
            {
                thres = Thresholds[i];
            }
            else
            {
                thres = 0;
            }
            int level_sum = 0;

            for (auto s : level_score)
            {
                level_sum += s;
            }

            summary += level_sum;
            if (level_sum < thres)
            {
                break;
            }
        }

        return summary;
    }
};

int main()
{
    const vector<int> sub_num = {8, 4, 3};
    const vector<int> thresholds = {80, 40};
    vector<vector<int>> scores(sub_num.size());
    MulitiLevelScore mls(thresholds);

    const int level_num = sub_num.size();

    rep(i, 0, level_num - 1)
    {
        scores[i].resize(sub_num[i]);
        rep(j, 0, sub_num[i] - 1)
        {
            cin >> scores[i][j];
        }
    }

    cout << mls.summary(scores) << endl;
    return 0;
}
