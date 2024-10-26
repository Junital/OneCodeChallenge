/*****************************************************************
 * 题目：[CCC2022 J2] Fergusonball Ratings
 * 描述：计算每个球员的得分，判断是否为黄金球员。
 * 思路：简单计算。
 * 对象：GoldenPlayer模拟黄金球员。
 * 注意：注意拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class GoldenPlayer
{
private:
    const int threshold = 40;
    const int goal_weight = 5; // 进球的权重
    const int fail_weight = 3; // 失误的权重

public:
    /* 初始化，输入球员的数据。 */
    int summary(vector<pair<int, int>> players)
    {
        int sum = 0;
        for (auto pii : players)
        {
            if (pii.first * goal_weight - pii.second * fail_weight > threshold)
            {
                sum++;
            }
        }

        return sum;
    }
};

int main()
{
    GoldenPlayer gp;
    int num;
    cin >> num;
    vector<pair<int, int>> players;

    rep(i, 1, num)
    {
        int goal, fail;
        cin >> goal >> fail;
        players.push_back(make_pair(goal, fail));
    }

    cout << gp.summary(players);
    if (gp.summary(players) == num)
    {
        cout << "+";
    }
    cout << endl;
    return 0;
}