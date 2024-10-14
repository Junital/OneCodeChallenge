/*****************************************************************
 * 题目：「Wdoi-2」比赤色更红的梦
 * 描述：根据分数和通关情况，判断剩余命数。
 * 思路：简单计算。
 * 对象：OriRedDevilTown模拟《东方红魔乡》
 * 注意：提高拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class OriRedDevilTown
{
private:
    const int InitLife = 2;
    const map<ll, int> Score2Life = {{10000000, 1},
                                     {20000000, 2},
                                     {40000000, 3},
                                     {60000000, 4}};

    const map<int, int> Stage2Life = {{3, 1},
                                      {5, 2}};

public:
    /* 根据分数和通关情况判断剩余生命。 */
    int query(int stage, ll score)
    {
        int ans = InitLife;

        auto stage_it = Stage2Life.upper_bound(stage);
        if (stage_it != Stage2Life.begin())
        {
            stage_it--;
            ans += stage_it->second;
        }

        auto score_it = Score2Life.upper_bound(score);
        if (score_it != Score2Life.begin())
        {
            score_it--;
            ans += score_it->second;
        }

        return ans;
    }
};

int main()
{
    OriRedDevilTown ordt;

    int query_num;
    cin >> query_num;
    rep(i, 1, query_num)
    {
        int stage;
        ll score;
        cin >> stage >> score;
        cout << ordt.query(stage, score) << endl;
    }
    return 0;
}