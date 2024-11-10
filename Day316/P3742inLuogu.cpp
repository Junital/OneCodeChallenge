/*****************************************************************
 * 题目：[语言月赛202304] 冠军
 * 描述：晋级赛，输入每场比赛的比分，输出最后的赢家。
 * 思路：主客场由序号决定，最后输出合适的序号。
 * 对象：PromotionMatch模拟晋级赛。
 * 注意：提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PromotionMatch
{
private:
    bool pow2judge(int Num)
    {
        // cout << (1 << 4) << endl;
        return Num == 1 << (int)log2(Num);
    }

public:
    /* 输入比分，进行比赛模拟。 */
    int simulation(vector<pair<int, int>> Scores)
    {
        int team_num = Scores.size() + 1;
        assert(pow2judge(team_num));

        queue<int> teams;
        rep(i, 0, team_num - 1)
        {
            teams.push(i);
        }
        teams.push(-1);

        rep(i, 0, team_num - 2)
        {
            int host = teams.front();
            teams.pop();

            if (host == -1)
            {
                host = teams.front();
                teams.pop();
                teams.push(-1);
            }

            int guest = teams.front();
            teams.pop();

            // cout << host << " " << guest << endl;
            assert(Scores[i].first != Scores[i].second);
            if (Scores[i].first > Scores[i].second)
            {
                teams.push(host);
            }
            else
            {
                // cout << i << " guest win." << endl;
                teams.push(guest);
            }
        }

        teams.pop();
        return teams.front();
    }
};

int main()
{
    const int TeamSize = 16;
    vector<pair<int, int>> scores(TeamSize - 1);

    PromotionMatch pm;

    rep(i, 0, TeamSize - 2)
    {
        scanf("%d-%d", &scores[i].first, &scores[i].second);
    }

    cout << (char)('A' + pm.simulation(scores)) << endl;
    return 0;
}