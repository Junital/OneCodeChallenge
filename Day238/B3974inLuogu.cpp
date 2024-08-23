/*****************************************************************
 * 题目：[语言月赛 202405] 放行李
 * 描述：计算与座位最近的行李存放点。
 * 思路：遍历空余的位置。
 * 函数：HighwayBaggage模拟高铁行李。
 * 注意：注意时间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class HighwayBaggage
{
private:
    int Len;
    vector<pair<int, int>> Spare;

public:
    /* 初始化，输入车厢的长度。 */
    HighwayBaggage(int l) : Len(l)
    {
        rep(i, 0, 1)
        {
            rep(j, 1, Len)
            {
                int State;
                cin >> State;
                if (State == 0)
                {
                    Spare.push_back(make_pair(i, j));
                }
            }
        }
    }

    /* 输入座位位置，输出最佳行李位置和距离。 */
    pair<pair<int, int>, int> decide(pair<int, int> Seat)
    {
        int best_dis = Len;
        pair<int, int> best_baggage = Seat;
        for (auto pii : Spare)
        {
            int dis = abs(Seat.second - pii.second);
            if (dis < best_dis || (dis == best_dis && pii.first == Seat.first))
            {
                best_baggage = pii;
                best_dis = dis;
            }
        }

        if (best_dis == Len)
        {
            return make_pair(make_pair(-1, -1), -1);
        }

        return make_pair(best_baggage, best_dis);
    }
};

int main()
{
    int len;
    cin >> len;

    HighwayBaggage hb(len);
    int x, y;
    cin >> x >> y;

    auto res = hb.decide(make_pair(x, y));
    if (res.second == -1)
    {
        cout << res.second << endl;
    }
    else
    {
        cout << res.first.first << " " << res.second << endl;
    }
    return 0;
}
