/*****************************************************************
 * 题目：[语言月赛 202403] 大西洋船王
 * 描述：出一艘船有成本，选择最赚的方案。
 * 思路：取最大值。
 * 对象：AtlanticKing模拟大西洋船王。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class AtlanticKing
{
private:
    vector<vector<ll>> Gains;
    ll BoatCost;
    ll MaxProfit;
    ll TaskNum;
    ll BoatNum;

    void preprocess()
    {
        MaxProfit = 0;
        rep(i, 0, TaskNum - 1)
        {
            vector<ll> PureProfit(BoatNum);

            rep(j, 0, BoatNum - 1)
            {
                PureProfit[j] = Gains[i][j] - (j + 1) * BoatCost;
            }

            MaxProfit += *(max_element(PureProfit.begin(),
                                       PureProfit.end()));
        }
    }

public:
    /* 初始化，输入获利与船只成本。 */
    AtlanticKing(vector<vector<ll>> &gains, ll boat_cost)
        : Gains(gains), BoatCost(boat_cost)
    {
        TaskNum = Gains.size();
        BoatNum = Gains[0].size();

        rep(i, 1, TaskNum - 1)
        {
            assert(BoatNum == Gains[i].size());
        }

        preprocess();
    }

    /* 获取最大利润。 */
    ll getMaxProfit()
    {
        return MaxProfit;
    }
};

int main()
{
    ll task_num;
    ll boat_num;
    ll boat_cost;

    cin >> task_num >> boat_num >> boat_cost;

    vector<vector<ll>> gains(task_num);

    rep(i, 0, task_num - 1)
    {
        gains[i].resize(boat_num);
        rep(j, 0, boat_num - 1)
        {
            cin >> gains[i][j];
        }
    }

    AtlanticKing ak(gains, boat_cost);
    cout << ak.getMaxProfit() << endl;
    return 0;
}